#!/usr/bin/python3
#cython: language_level=3
from math import *
from sys import *

def find_factor(number):
        if (number % 2 == 0):
                return (2)
        max = isqrt(number) + 1
        for i in range(3, max, 2):
                if (number % i == 0):
                        return (i)

if __name__ == "__main__":
        if (len(argv) != 2):
                print("Usage: {} <file>".format(argv[0]))
                exit(1)
        file = open(argv[1], 'r')
        for line in file:
                intline = int(line)
                factor = find_factor(intline)
                print("{:d}={:d}*{:d}".format(intline, intline//factor, factor))
        file.close()