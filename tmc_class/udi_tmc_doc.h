/**
 * \file
 *
 * \brief USB device driver for Vendor interface.
 *
 * Copyright (c) 2014-2015 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */

/**
 * \defgroup asfdoc_udi_vendor_group USB Device Interface (UDI) for Vendor Class Device
 *
 * USB Device Interface (UDI) for Vendor Class Device provides an
 * interface for the configuration and management of USB Vendor Device.
 *
 * The outline of this documentation is as follows:
 * - \ref asfdoc_udi_vendor_api_overview
 * - \ref asfdoc_udi_vendor_exqsg
 * - \ref asfdoc_udi_vendor_config_examples
 *
 * For more details for Atmel&reg; Software Framework (ASF) USB Device Stack, and
 * USB Device Vendor, refer to following application notes:
 * - <a href="http://www.atmel.com/dyn/resources/prod_documents/doc8360.pdf">
 *   AVR4900: ASF - USB Device Stack</a>
 * - <a href="http://www.atmel.com/dyn/resources/prod_documents/doc8481.pdf">
 *   AVR4901: ASF - USB Device Vendor Class Application</a>.
 * - <a href="http://www.atmel.com/dyn/resources/prod_documents/doc8410.pdf">
 *   AVR4920: ASF - USB Device Stack - Compliance and Performance Figures</a>
 * - <a href="http://www.atmel.com/dyn/resources/prod_documents/doc8411.pdf">
 *   AVR4921: ASF - USB Device Stack Differences between ASF V1 and V2</a>
 *
 * \section asfdoc_udi_vendor_api_overview API Overview
 * @{
 */

/**
 * \name Interface with USB Device Core (UDC)
 *
 * Variable required by UDC.
 *
 * @{
 */

#error This file is for documentation purposes only.  Values in it should not be referenced by sources!

/** Global structure which contains standard UDI interface for UDC. */
extern UDC_DESC_STORAGE udi_api_t udi_api_tmc;
/**@}*/

/**
 * \name USB Interface Descriptors
 *
 * The following structures provide predefined USB interface descriptors.
 * It must be used to define the final USB descriptors.
 * @{
 */

 /** Endpoint descriptors. */
 /**
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */
#if UDI_TMC_EPS_SIZE_INT_FS

# define UDI_TMC_EPS_INT_DESC \
	.ep_interrupt_in.bLength           = sizeof(usb_ep_desc_t),\
	.ep_interrupt_in.bDescriptorType   = USB_DT_ENDPOINT,\
	.ep_interrupt_in.bEndpointAddress  = UDI_TMC_EP_INTERRUPT_IN,\
	.ep_interrupt_in.bmAttributes      = USB_EP_TYPE_INTERRUPT,\
	.ep_interrupt_in.bInterval         = 1,\
	.ep_interrupt_out.bLength          = sizeof(usb_ep_desc_t),\
	.ep_interrupt_out.bDescriptorType  = USB_DT_ENDPOINT,\
	.ep_interrupt_out.bEndpointAddress = UDI_TMC_EP_INTERRUPT_OUT,\
	.ep_interrupt_out.bmAttributes     = USB_EP_TYPE_INTERRUPT,\
	.ep_interrupt_out.bInterval        = 1,

# define UDI_TMC_EPS_INT_DESC_FS \
	.ep_interrupt_in.wMaxPacketSize    = LE16(UDI_TMC_EPS_SIZE_INT_FS),\
	.ep_interrupt_out.wMaxPacketSize   = LE16(UDI_TMC_EPS_SIZE_INT_FS),

# define UDI_TMC_EPS_INT_DESC_HS \
	.ep_interrupt_in.wMaxPacketSize    = LE16(UDI_TMC_EPS_SIZE_INT_HS),\
	.ep_interrupt_out.wMaxPacketSize   = LE16(UDI_TMC_EPS_SIZE_INT_HS),

#else
# define UDI_TMC_EPS_INT_DESC
# define UDI_TMC_EPS_INT_DESC_FS
# define UDI_TMC_EPS_INT_DESC_HS
#endif

#if UDI_TMC_EPS_SIZE_BULK_FS
# define UDI_TMC_EPS_BULK_DESC \
	.ep_bulk_in.bLength                = sizeof(usb_ep_desc_t),\
	.ep_bulk_in.bDescriptorType        = USB_DT_ENDPOINT,\
	.ep_bulk_in.bEndpointAddress       = UDI_TMC_EP_BULK_IN,\
	.ep_bulk_in.bmAttributes           = USB_EP_TYPE_BULK,\
	.ep_bulk_in.bInterval              = 0,\
	.ep_bulk_out.bLength               = sizeof(usb_ep_desc_t),\
	.ep_bulk_out.bDescriptorType       = USB_DT_ENDPOINT,\
	.ep_bulk_out.bEndpointAddress      = UDI_TMC_EP_BULK_OUT,\
	.ep_bulk_out.bmAttributes          = USB_EP_TYPE_BULK,\
	.ep_bulk_out.bInterval             = 0,

# define UDI_TMC_EPS_BULK_DESC_FS \
	.ep_bulk_in.wMaxPacketSize         = LE16(UDI_TMC_EPS_SIZE_BULK_FS),\
	.ep_bulk_out.wMaxPacketSize        = LE16(UDI_TMC_EPS_SIZE_BULK_FS),

# define UDI_TMC_EPS_BULK_DESC_HS \
	.ep_bulk_in.wMaxPacketSize         = LE16(UDI_TMC_EPS_SIZE_BULK_HS),\
	.ep_bulk_out.wMaxPacketSize        = LE16(UDI_TMC_EPS_SIZE_BULK_HS),

#else
# define UDI_TMC_EPS_BULK_DESC
# define UDI_TMC_EPS_BULK_DESC_FS
# define UDI_TMC_EPS_BULK_DESC_HS
#endif

#if UDI_TMC_EPS_SIZE_ISO_FS

#error Isochronous enpoints are not supported by this implementation!

# define UDI_TMC_EPS_ISO_DESC \
	.ep_iso_in.bLength                 = sizeof(usb_ep_desc_t),\
	.ep_iso_in.bDescriptorType         = USB_DT_ENDPOINT,\
	.ep_iso_in.bEndpointAddress        = UDI_TMC_EP_ISO_IN,\
	.ep_iso_in.bmAttributes            = USB_EP_TYPE_ISOCHRONOUS,\
	.ep_iso_in.bInterval               = 1,\
	.ep_iso_out.bLength                = sizeof(usb_ep_desc_t),\
	.ep_iso_out.bDescriptorType        = USB_DT_ENDPOINT,\
	.ep_iso_out.bEndpointAddress       = UDI_TMC_EP_ISO_OUT,\
	.ep_iso_out.bmAttributes           = USB_EP_TYPE_ISOCHRONOUS,\
	.ep_iso_out.bInterval              = 1,

# define UDI_TMC_EPS_ISO_DESC_FS \
	.ep_iso_in.wMaxPacketSize          = LE16(UDI_TMC_EPS_SIZE_ISO_FS),\
	.ep_iso_out.wMaxPacketSize         = LE16(UDI_TMC_EPS_SIZE_ISO_FS),

# define UDI_TMC_EPS_ISO_DESC_HS \
	.ep_iso_in.wMaxPacketSize          = LE16(UDI_TMC_EPS_SIZE_ISO_HS),\
	.ep_iso_out.wMaxPacketSize         = LE16(UDI_TMC_EPS_SIZE_ISO_HS),

#else
# define UDI_TMC_EPS_ISO_DESC
# define UDI_TMC_EPS_ISO_DESC_FS
# define UDI_TMC_EPS_ISO_DESC_HS
#endif

 /** Interface descriptor structure for TMC Class interface. */
typedef struct {
	/** Standard USB interface descriptor structure */
	usb_iface_desc_t iface0;
	/** Standard USB interface descriptor structure */
	usb_iface_desc_t iface1;
#if UDI_TMC_EPS_SIZE_INT_FS
	/** Standard USB endpoint descriptor structure */
	usb_ep_desc_t ep_interrupt_in;
	/** Standard USB endpoint descriptor structure */
	usb_ep_desc_t ep_interrupt_out;
#endif
#if UDI_TMC_EPS_SIZE_BULK_FS
	/** Standard USB endpoint descriptor structure */
	usb_ep_desc_t ep_bulk_in;
	/** Standard USB endpoint descriptor structure */
	usb_ep_desc_t ep_bulk_out;
#endif
#if UDI_TMC_EPS_SIZE_ISO_FS
	/** Standard USB endpoint descriptor structure */
	usb_ep_desc_t ep_iso_in;
	/** Standard USB endpoint descriptor structure */
	usb_ep_desc_t ep_iso_out;
#endif
} udi_tmc_desc_t;

 /** By default no string is associated to this interface. */
#ifndef UDI_TMC_STRING_ID
#define UDI_TMC_STRING_ID     0
#endif

 /** Maximum six endpoints used by TMC interface. */
#define UDI_TMC_EP_NB_INT  ((UDI_TMC_EPS_SIZE_INT_FS)?2:0)
#define UDI_TMC_EP_NB_BULK ((UDI_TMC_EPS_SIZE_BULK_FS)?2:0)
#define UDI_TMC_EP_NB_ISO  ((UDI_TMC_EPS_SIZE_ISO_FS)?2:0)
#define UDI_TMC_EP_NB      (UDI_TMC_EP_NB_INT+UDI_TMC_EP_NB_BULK+UDI_TMC_EP_NB_ISO)


 /** Content of TMC interface descriptor for all speeds. */
#define UDI_TMC_DESC      \
	.iface0.bLength            = sizeof(usb_iface_desc_t),\
	.iface0.bDescriptorType    = USB_DT_INTERFACE,\
	.iface0.bInterfaceNumber   = UDI_TMC_IFACE_NUMBER,\
	.iface0.bAlternateSetting  = 0,\
	.iface0.bNumEndpoints      = 0,\
	.iface0.bInterfaceClass    = TMC_CLASS,\
	.iface0.bInterfaceSubClass = TMC_SUBCLASS,\
	.iface0.bInterfaceProtocol = TMC_PROTOCOL,\
	.iface0.iInterface         = UDI_TMC_STRING_ID,\
	.iface1.bLength            = sizeof(usb_iface_desc_t),\
	.iface1.bDescriptorType    = USB_DT_INTERFACE,\
	.iface1.bInterfaceNumber   = UDI_TMC_IFACE_NUMBER,\
	.iface1.bAlternateSetting  = 1,\
	.iface1.bNumEndpoints      = UDI_TMC_EP_NB,\
	.iface1.bInterfaceClass    = TMC_CLASS,\
	.iface1.bInterfaceSubClass = TMC_SUBCLASS,\
	.iface1.bInterfaceProtocol = TMC_PROTOCOL,\
	.iface1.iInterface         = UDI_TMC_STRING_ID,\
	UDI_TMC_EPS_INT_DESC \
	UDI_TMC_EPS_BULK_DESC \
	UDI_TMC_EPS_ISO_DESC \

 /** Content of TMC interface descriptor for full speed only. */
#define UDI_TMC_DESC_FS {\
	UDI_TMC_DESC \
	UDI_TMC_EPS_INT_DESC_FS \
	UDI_TMC_EPS_BULK_DESC_FS \
	UDI_TMC_EPS_ISO_DESC_FS \
   }

 /** Content of TMC interface descriptor for high speed only. */
#define UDI_TMC_DESC_HS   {\
	UDI_TMC_DESC \
	UDI_TMC_EPS_INT_DESC_HS \
	UDI_TMC_EPS_BULK_DESC_HS \
	UDI_TMC_EPS_ISO_DESC_HS \
   }
/**@}*/

/**
 * \name USB Device Interface (UDI) for TMC Class
 *
 * Common APIs used by high level application to use this USB class.
 *
 * These routines are used to transfer data to/from USB VENDOR endpoints.
 *
 * See Quick start guide for USB Device vendor module.
 * @{
 */

 #if UDI_TMC_EPS_SIZE_INT_FS || defined(__DOXYGEN__)
/**
 * \brief Start a transfer on interrupt IN
 *
 * When the transfer is finished or aborted (stall, reset, ...), the \a callback is called.
 * The \a callback returns the transfer status and eventually the number of byte transferred.
 *
 * \param[in] buf           Buffer on Internal RAM to send or fill.
 *                      It must be align, then use COMPILER_WORD_ALIGNED.
 * \param[in] buf_size      Buffer size to send or fill
 * \param[in] callback      NULL or function to call at the end of transfer
 *
 * \return \c 1 if function was successfully done, otherwise \c 0.
 */
bool udi_tmc_interrupt_in_run(uint8_t * buf, iram_size_t buf_size,
                              udd_callback_trans_t callback);

/**
 * \brief Start a transfer on interrupt OUT
 *
 * When the transfer is finished or aborted (stall, reset, ...), the \a callback is called.
 * The \a callback returns the transfer status and eventually the number of byte transferred.
 *
 * \param[in] buf           Buffer on Internal RAM to send or fill.
 *                      It must be align, then use COMPILER_WORD_ALIGNED.
 * \param[in] buf_size      Buffer size to send or fill
 * \param[in] callback      NULL or function to call at the end of transfer
 *
 * \return \c 1 if function was successfully done, otherwise \c 0.
 */
bool udi_tmc_interrupt_out_run(uint8_t * buf, iram_size_t buf_size,
                               udd_callback_trans_t callback);
#endif

#if UDI_TMC_EPS_SIZE_BULK_FS || defined(__DOXYGEN__)
/**
 * \brief Start a transfer on bulk IN
 *
 * When the transfer is finished or aborted (stall, reset, ...), the \a callback is called.
 * The \a callback returns the transfer status and eventually the number of byte transferred.
 *
 * \param[in] buf           Buffer on Internal RAM to send or fill.
 *                      It must be align, then use COMPILER_WORD_ALIGNED.
 * \param[in] buf_size      Buffer size to send or fill
 * \param[in] callback      NULL or function to call at the end of transfer
 *
 * \return \c 1 if function was successfully done, otherwise \c 0.
 */
bool udi_tmc_bulk_in_run(uint8_t * buf, iram_size_t buf_size,
                         udd_callback_trans_t callback);

/**
 * \brief Start a transfer on bulk OUT
 *
 * When the transfer is finished or aborted (stall, reset, ...), the \a callback is called.
 * The \a callback returns the transfer status and eventually the number of byte transferred.
 *
 * \param[in] buf           Buffer on Internal RAM to send or fill.
 *                      It must be align, then use COMPILER_WORD_ALIGNED.
 * \param[in] buf_size      Buffer size to send or fill
 * \param[in] callback      NULL or function to call at the end of transfer
 *
 * \return \c 1 if function was successfully done, otherwise \c 0.
 */
bool udi_tmc_bulk_out_run(uint8_t * buf, iram_size_t buf_size,
		udd_callback_trans_t callback);
#endif


#if UDI_TMC_EPS_SIZE_ISO_FS || defined(__DOXYGEN__)
/**
 * \brief Start a transfer on isochronous IN
 *
 * When the transfer is finished or aborted (stall, reset, ...), the \a callback is called.
 * The \a callback returns the transfer status and eventually the number of byte transferred.
 *
 * \param[in] buf           Buffer on Internal RAM to send or fill.
 *                      It must be align, then use COMPILER_WORD_ALIGNED.
 * \param[in] buf_size      Buffer size to send or fill
 * \param[in] callback      NULL or function to call at the end of transfer
 *
 * \return \c 1 if function was successfully done, otherwise \c 0.
 */
bool udi_tmc_iso_in_run(uint8_t * buf, iram_size_t buf_size,
		udd_callback_trans_t callback);

/**
 * \brief Start a transfer on isochronous OUT
 *
 * When the transfer is finished or aborted (stall, reset, ...), the \a callback is called.
 * The \a callback returns the transfer status and eventually the number of byte transferred.
 *
 * \param[in] buf           Buffer on Internal RAM to send or fill.
 *                      It must be align, then use COMPILER_WORD_ALIGNED.
 * \param[in] buf_size      Buffer size to send or fill
 * \param[in] callback      NULL or function to call at the end of transfer
 *
 * \return \c 1 if function was successfully done, otherwise \c 0.
 */
bool udi_tmc_iso_out_run(uint8_t * buf, iram_size_t buf_size,
		udd_callback_trans_t callback);
#endif

/**@}*/
/**@}*/

/**
 * \page asfdoc_udi_vendor_exqsg Quick Start Guide for USB Device Vendor Module (UDI Vendor)
 *
 * This is the quick start guide for the \ref asfdoc_udi_vendor_group
 * "USB Device Vendor Module (UDI Vendor)" with step-by-step instructions on
 * how to configure and use the modules in a selection of use cases.
 *
 * The use cases highlights several code fragments. The code fragments in the
 * steps for setup can be copied into a custom initialization function, while
 * the steps for usage can be copied into, e.g., the main application function.
 *
 * \section udi_vendor_basic_use_case Basic Use Case
 * In this basic use case, the "USB Vendor (Single Class support)" module is
 * used. The "USB Vendor (Composite Device)" module usage is described in \ref udi_vendor_use_cases
 * "Advanced Use Cases".
 *
 * \subsection udi_vendor_basic_use_case_setup Setup Steps
 * As a USB device, it follows common USB device setup steps. Refer to
 * \ref asfdoc_udc_basic_use_case_setup "USB Device Basic Setup".
 *
 * \subsection udi_vendor_basic_use_case_usage Usage Steps
 *
 * \subsubsection udi_vendor_basic_use_case_usage_code Example code
 * Content of conf_usb.h:
 * \code
	 * #define UDI_TMC_ENABLE_EXT() my_callback_vendor_enable()
	 * extern bool my_callback_vendor_enable(void);
	 * #define UDI_TMC_DISABLE_EXT() my_callback_vendor_disable()
	 * extern void my_callback_vendor_disable(void);
	 *
	 * #define  UDI_TMC_SETUP_OUT_RECEIVED()  my_vendor_setup_out_received()
	 * extern bool my_vendor_setup_out_received(void);
	 * #define  UDI_TMC_SETUP_IN_RECEIVED()   my_vendor_setup_in_received()
	 * extern bool my_vendor_setup_in_received(void);
	 *
	 * #define  UDI_TMC_EPS_SIZE_INT_FS    64
	 * #define  UDI_TMC_EPS_SIZE_BULK_FS   64
	 * #define  UDI_TMC_EPS_SIZE_ISO_FS   256
	 * #define  UDI_TMC_EPS_SIZE_INT_HS    64
	 * #define  UDI_TMC_EPS_SIZE_BULK_HS  512
	 * #define  UDI_TMC_EPS_SIZE_ISO_HS    64

	 * #include "udi_tmc_conf.h" // At the end of conf_usb.h file
 \endcode
 *
 * Add to application C-file:
 * \code
	 static bool my_flag_autorize_vendor_transfert = false;
	 bool my_callback_vendor_enable(void)
	 {
	    my_flag_autorize_vendor_transfert = true;
	    return true;
	 }
	 void my_callback_vendor_disable(void)
	 {
	    my_flag_autorize_vendor_transfert = false;
	 }

	 uint8_t global_buffer[X];
	 void task(void)
	 {
	    if (my_flag_autorize_vendor_transfert) {
	      // Enable a transfer on OUT interrupt endpoint
	      udi_tmc_interrupt_out_run(
	      		global_buffer,
	      		sizeof(global_buffer),
	      		NULL);
	      // Enable a transfer on IN interrupt endpoint
	      udi_tmc_interrupt_in_run(
	      		global_buffer,
	      		sizeof(global_buffer),
	      		NULL);
	      ...
	    }
	 }
 \endcode
 *
 * \subsection udi_vendor_basic_use_case_setup_flow Workflow
 * -# Ensure that conf_usb.h is available and contains the following configuration,
 * which is the USB device Vendor configuration:
 * \code
 #define UDI_TMC_ENABLE_EXT() my_callback_vendor_enable()
 extern bool my_callback_vendor_enable(void);
 \endcode
 * \note After the device enumeration (detecting and identifying USB devices),
 *       the USB host starts the device configuration. When the USB Vendor interface
 *       from the device is accepted by the host, the USB host enables this interface and the
 *       UDI_TMC_ENABLE_EXT() callback function is called and return true.
 *       Thus, when this event is received, the Vendor transfers can start.
 *
 * \code
 #define UDI_TMC_DISABLE_EXT() my_callback_vendor_disable()
 extern void my_callback_vendor_disable(void);
 \endcode
 * \note When the USB device is unplugged or is reset by the USB host, the USB
 *       interface is disabled and the UDI_TMC_DISABLE_EXT() callback function
 *       is called. Thus, it is recommended to disable the data Vendor transfer.
 *
 * \code
 #define  UDI_TMC_SETUP_OUT_RECEIVED()  my_vendor_setup_out_received()
 extern bool my_vendor_setup_out_received(void);
 #define  UDI_TMC_SETUP_IN_RECEIVED()   my_vendor_setup_in_received()
 extern bool my_vendor_setup_in_received(void);
 \endcode
 * \note The control requests for the interface Vendor will be processed
 *       through these both callbacks.
 *
 * \code
 #define  UDI_TMC_EPS_SIZE_INT_FS    64
 #define  UDI_TMC_EPS_SIZE_BULK_FS   64
 #define  UDI_TMC_EPS_SIZE_ISO_FS   256
 #define  UDI_TMC_EPS_SIZE_INT_HS    64
 #define  UDI_TMC_EPS_SIZE_BULK_HS  512
 #define  UDI_TMC_EPS_SIZE_ISO_HS    64
 \endcode
 * \note The endpoint size is defined by the final application, and can be
 *       disabled if the full speed size is zero.
 *
 * -# The Vendor transfers on interrupt, bulk, and isochronous endpoints are
 * done through these functions:
 * \code
 // Start a transfer on interrupt IN
 udi_tmc_interrupt_in_run();
 // Start a transfer on interrupt OUT
 udi_tmc_interrupt_out_run();
 // Start a transfer on bulk IN
 udi_tmc_bulk_in_run();
 // Start a transfer on bulk OUT
 udi_tmc_bulk_out_run();
 // Start a transfer on isochronous IN
 udi_tmc_iso_in_run();
 // Start a transfer on isochronous OUT
 udi_tmc_iso_out_run();
 \endcode
 *
 * \section udi_vendor_use_cases Advanced Use Cases
 * \ifnot ASF_MANUAL
 * For more advanced use of the udi vendor module, see the following use cases:
 * - \subpage udi_vendor_use_case_composite
 * - \subpage udc_use_case_1
 * - \subpage udc_use_case_2
 * - \subpage udc_use_case_3
 * - \subpage udc_use_case_5
 * - \subpage udc_use_case_6
 * \else
 * For multiple interface use of UDI Vendor module, see the following:
 * - \subpage udi_vendor_use_case_composite
 *
 * For more advanced use of the UDI Vendor module, see the following:
 * - \ref asfdoc_udc_use_cases
 * \endif
 */
/**
 * \page udi_vendor_use_case_composite Vendor in a Composite Device
 *
 * A USB Composite Device is a USB Device, which uses more than one USB class.
 * In this use case, the "USB Vendor (Composite Device)" module is used to
 * create a USB composite device. Thus, this USB module can be associated with
 * another "Composite Device" module, like "USB HID Mouse (Composite Device)".
 *
 * Also, you can refer to application note
 * <A href="http://www.atmel.com/dyn/resources/prod_documents/doc8445.pdf">
 * AVR4902 ASF - USB Composite Device</A>.
 *
 * \section udi_vendor_use_case_composite_setup Setup Steps
 * For the setup code of this use case to work, the
 * \ref udi_vendor_basic_use_case "Basic Use Case" must be followed.
 *
 * \section udi_vendor_use_case_composite_usage Usage Steps
 *
 * \subsection udi_vendor_use_case_composite_usage_code Example Code
 * Content of conf_usb.h:
 * \code
 #define USB_DEVICE_EP_CTRL_SIZE  64
 #define USB_DEVICE_NB_INTERFACE (X+1)
 #define USB_DEVICE_MAX_EP (X) to (X+6)

 #define  UDI_TMC_EP_INTERRUPT_IN  (1 | USB_EP_DIR_IN)
 #define  UDI_TMC_EP_INTERRUPT_OUT (2 | USB_EP_DIR_OUT)
 #define  UDI_TMC_EP_BULK_IN       (3 | USB_EP_DIR_IN)
 #define  UDI_TMC_EP_BULK_OUT      (4 | USB_EP_DIR_OUT)
 #define  UDI_TMC_EP_ISO_IN        (5 | USB_EP_DIR_IN)
 #define  UDI_TMC_EP_ISO_OUT       (6 | USB_EP_DIR_OUT)

 #define UDI_TMC_IFACE_NUMBER  X

 #define UDI_COMPOSITE_DESC_T \
    udi_tmc_desc_t udi_vendor; \
    ...
 #define UDI_COMPOSITE_DESC_FS \
    .udi_vendor = UDI_TMC_DESC, \
    ...
 #define UDI_COMPOSITE_DESC_HS \
    .udi_vendor = UDI_TMC_DESC, \
    ...
 #define UDI_COMPOSITE_API \
    &udi_api_tmc, \
    ...
 \endcode
 *
 * \subsection udi_vendor_use_case_composite_usage_flow Workflow
 * -# Ensure that conf_usb.h is available and contains the following parameters
 * required for a USB composite device configuration:
 * \code
 // Endpoint control size, This must be:
 // - 8, 16, 32 or 64 for full speed device (8 is recommended to save RAM)
 // - 64 for a high speed device
 #define USB_DEVICE_EP_CTRL_SIZE  64
 // Total Number of interfaces on this USB device.
 // Add 1 for Vendor.
 #define USB_DEVICE_NB_INTERFACE (X+1)
 // Total number of endpoints on this USB device.
 // This must include each endpoint for each interface.
 // Add 0 to 6 for Vendor interface.
 // The number depends on UDI_VENDOR_EPS_SIZE_..._FS defines.
 #define USB_DEVICE_MAX_EP (X) to (X+6)
 \endcode
 * -# Ensure that conf_usb.h contains the description of
 * composite device:
 * \code
 // The endpoint numbers chosen by you for the Vendor.
 // The endpoint numbers starting from 1.
 #define  UDI_TMC_EP_INTERRUPT_IN  (1 | USB_EP_DIR_IN)
 #define  UDI_TMC_EP_INTERRUPT_OUT (2 | USB_EP_DIR_OUT)
 #define  UDI_TMC_EP_BULK_IN       (3 | USB_EP_DIR_IN)
 #define  UDI_TMC_EP_BULK_OUT      (4 | USB_EP_DIR_OUT)
 #define  UDI_TMC_EP_ISO_IN        (5 | USB_EP_DIR_IN)
 #define  UDI_TMC_EP_ISO_OUT       (6 | USB_EP_DIR_OUT)
 // The interface index of an interface starting from 0
 #define UDI_TMC_IFACE_NUMBER  X
 \endcode
 * -# Ensure that conf_usb.h contains the following parameters
 * required for a USB composite device configuration:
 * \code
 // USB Interfaces descriptor structure
 #define UDI_COMPOSITE_DESC_T \
    ...
    udi_tmc_desc_t udi_vendor; \
    ...
 // USB Interfaces descriptor value for Full Speed
 #define UDI_COMPOSITE_DESC_FS \
    ...
    .udi_vendor = UDI_TMC_DESC_FS, \
    ...
 // USB Interfaces descriptor value for High Speed
 #define UDI_COMPOSITE_DESC_HS \
    ...
    .udi_vendor = UDI_TMC_DESC_HS, \
    ...
 // USB Interface APIs
 #define UDI_COMPOSITE_API \
    ...
    &udi_api_tmc, \
    ...
 \endcode
 * \note The descriptors order given in the four lists above must be the
 *       same as the order defined by all interface indexes. The interface index
 *       orders are defined through UDI_X_IFACE_NUMBER defines.
 */

/**
 * \page asfdoc_udi_vendor_config_examples Configuration File Examples
 *
 * \section asfdoc_udi_vendor_config_examples_1 conf_usb.h
 * \subsection asfdoc_udi_vendor_config_examples_1_1  UDI Vendor Single
 * \include module_config/conf_usb.h
 * \subsection asfdoc_udi_vendor_config_examples_1_2  UDI Vendor Multiple (Composite)
 * \include composite/device/module_config/conf_usb.h
 *
 * \section asfdoc_udi_vendor_config_examples_2 conf_clock.h
 *
 * \subsection asfdoc_udi_vendor_config_examples_2_1 SAM3X and SAM3A Devices (UOTGHS: USB OTG High Speed)
 * \include example/sam3x8h_sam3x_ek/conf_clock.h
 *
 * \subsection asfdoc_udi_vendor_config_examples_2_2 SAM4L Device (USBC)
 * \include example/sam4lc4c_sam4l_ek/conf_clock.h
  *
 * \section asfdoc_udi_vendor_config_examples_3 conf_clocks.h
 *
 * \subsection asfdoc_udi_vendor_config_examples_3_1 SAM D21 Device (USB)
 * \include example/samd21j18a_samd21_xplained_pro/conf_clocks.h
 *
 * \section asfdoc_udi_vendor_config_examples_4 conf_board.h
 *
 * \subsection asfdoc_udi_vendor_config_examples_4_1 SAM3X and SAM3A Devices (UOTGHS: USB OTG High Speed)
 * \include example/sam3x8h_sam3x_ek/conf_board.h
 *
 * \subsection asfdoc_udi_vendor_config_examples_4_2 SAM4L Device (USBC)
 * \include example/sam4lc4c_sam4l_ek/conf_board.h
 *
 * \subsection asfdoc_udi_vendor_config_examples_4_3 SAM D21 Device (USB)
 * \include example/samd21j18a_samd21_xplained_pro/conf_board.h
 */

/**
 * \page asfdoc_udi_vendor_document_revision_history Document Revision History
 *
 * <table>
 * <tr>
 *    <th>Doc. Rev.</th>
 *    <th>Date</th>
 *    <th>Comments</th>
 * </tr>
 * <tr>
 *    <td>42345B</td>
 *    <td>12/2015</td>
 *    <td>Fixed typos</td>
 * </tr>
 * <tr>
 *    <td>42345A</td>
 *    <td>12/2014</td>
 *    <td>Initial release</td>
 * </tr>
 * </table>
 */

