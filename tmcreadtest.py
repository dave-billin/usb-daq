#! /usr/bin/python

import sys
import os
import argparse
import math
import struct
import timeit

parser = argparse.ArgumentParser()
parser.add_argument('devicePath', metavar='DEVICE',
                    help='Path of the USBTMC device to operate on')
parser.add_argument('--count', type=int, default=9,
                    help='Number of Samples to read')
parser.add_argument('--printsamples', type=bool, default=False,
                    help='Print sample values')
args = parser.parse_args()

if not os.path.exists(args.devicePath):
    sys.stderr.write( "ERROR: '{}' does not specify a valid file!\n".format(args.devicePath) )
    sys.exit(1)

_BYTES_PER_SAMPLE = 4      # Number of Bytes per sample

# Open the USBTMC
print "Opening USBTMC device '{}'".format(args.devicePath)
tmcfd = os.open(args.devicePath, os.O_RDONLY)

samples = []
bytesToRead = (args.count * _BYTES_PER_SAMPLE)

# Read from the TMC device
try:
    start_time = timeit.default_timer()
    usbtmcData = os.read(tmcfd, bytesToRead)
    elapsed = timeit.default_timer() - start_time

    while usbtmcData:
        sampleBytes = usbtmcData[0:4]
        usbtmcData = usbtmcData[4:]
        sample = struct.unpack('I', sampleBytes)[0]
        samples += [sample]

    # Print sample values that were read
    print ("Read {} {}-Byte samples in {} seconds ({} smp/sec)"
          ).format( args.count, _BYTES_PER_SAMPLE, elapsed, 
                    math.floor(args.count/elapsed) )

    if args.printsamples:
        for s in samples:
            print s

except Exception as e:
    sys.stderr.write(("ERROR: Failed to read from {}: {}\n"
                     ).format(args.devicePath, str(e)) )
    sys.exit(1)

