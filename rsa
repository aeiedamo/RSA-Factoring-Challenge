#!/usr/bin/python3
from math import *
from sys import *

def factorize(number):
    if (number % 2 == 0):
        return (2)
    max = isqrt(number) + 1
    for i in range(3, max, 2):
        if (number % i == 0):
            return (i)

if __name__=='__main__':
    if (len(argv) != 2):
        print("Usage: factors <file>")
        exit(-1)
    with open(argv[1], 'r') as f:
        for line in f:
            n = int(line)
            q = factorize(n)
            p = n // q
            print("{:d}={:d}*{:d}".format(n, p, q))
        f.close()
