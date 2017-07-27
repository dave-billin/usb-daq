//==============================================================================
/*
 * @file
 *
 * @brief Implementation of routines used to acquire data from ADC's
 *
 * @author Dave Billin
 */
//==============================================================================

#include "adc_driver.h"

#ifdef USE_MOCK_ADC_DRIVER

#include <tcc.h>
#include <tcc_callback.h>

/// Data structure used to access TCC0
struct tcc_module g_tcc_instance;

/// ADC channel enablement mask where bit0=ADC1...bit7=ADC8 and 1=Enabled
uint8_t g_channelEnableMask;

////////////////////////////////////////////////////////////////////////////////
/// Callback function invoked when TCC0 overflows
///
/// @param tccModule
///   Pointer to the tcc_module for the timer that overflowed
///
static void tcc0OverflowCallback( struct tcc_module* const tccModule )
{
   // TODO: implement this callback routine
}

////////////////////////////////////////////////////////////////////////////////
/// Configures TCC0 for simulation of ADC data
///
/// @param channelEnableMask
///   A bitfield indicating which ADC channels are enabled for conversion where
///   bit zero indicates channel 1 and bit 7 indicates channel 8.  A bit value
///   of 1 enables the corresponding channel, while a value of zero disables it
///
static void configureTcc0( uint8_t channelEnableMask )
{
   g_channelEnableMask = channelEnableMask;

   // Configure TCC0 and initialize fields to zero
   struct tcc_config config_tcc = {0};

   tcc_get_config_defaults(&config_tcc, TCC0);
   config_tcc.counter.clock_source = GCLK_GENERATOR_1;
   config_tcc.counter.clock_prescaler = TCC_CLOCK_PRESCALER_DIV64;
   config_tcc.counter.period = 2000;
   tcc_init(&g_tcc_instance, TCC0, &config_tcc);
   tcc_enable(&g_tcc_instance);
}


////////////////////////////////////////////////////////////////////////////////
/// Configures callbacks for TCC0 events
static void configureTcc0Callbacks( void )
{
   tcc_register_callback(&g_tcc_instance, tcc0OverflowCallback,
                         TCC_CALLBACK_OVERFLOW);
   tcc_enable_callback(&g_tcc_instance, TCC_CALLBACK_OVERFLOW);
}

#endif // END #ifdef USE_MOCK_ADC_DRIVER

////////////////////////////////////////////////////////////////////////////////
/// Initializes the ADC driver
void adc_initialize( void )
{
   // TODO: initialize ADC data acquisition

#ifndef USE_MOCK_ADC_DRIVER
   // TODO: add the real ADC initialization
#else
   configureTcc0(0x3f);
   configureTcc0Callbacks();
#endif
}

////////////////////////////////////////////////////////////////////////////////
uint32_t adc_readSamples( void* dest, uint16_t numBytes )
{
   // For now, we just simulate ADC data as incrementing values
   static uint32_t sampleValues[ADC_NUM_CHANNELS] = {0};
   static uint8_t readIndex = 0;

   uint32_t* dest32 = (uint32_t*)dest;
   uint32_t numBytesRead = 0;
   while ( numBytes >= ADC_BYTES_PER_SAMPLE )
   {
      // Read a sample into the buffer, incrementing pointer and read index
      *dest32++ = sampleValues[readIndex++];

      // Decrement remaining Bytes in dest
      numBytes -= ADC_BYTES_PER_SAMPLE;

      // Increment the number of Bytes copied
      numBytesRead += ADC_BYTES_PER_SAMPLE;

      // Wrap read index.  Increment sample value on wrap
      if ( readIndex == ADC_NUM_CHANNELS )
      {
         for (readIndex = 0; readIndex < ADC_NUM_CHANNELS; ++readIndex)
         {
            ++sampleValues[readIndex];
         }
         readIndex = 0;
      }
   }

   return numBytesRead;
}
