#!/usr/bin/python3
from math import *
from sys import *

def ten_times(number, first_prime):
    max = isqrt(number) + 1
    for i in range(first_prime, max, 10):
        if (number % i == 0):
            return (i)
    return (-1)

def factorize(number):
    if (number % 2 == 0):
        return (2)
    if (number % 5 == 0):
        return (5)
    primes = [3, 7, 11, 19]
    for i in primes:
        factor = ten_times(number, i)
        if (factor != -1):
            return (factor)

if __name__=='__main__':
    f = open(argv[1], "r")
    for line in f:
        n = int(line)
        q = factorize(n)
        p = n // q
        print("{}={}*{}".format(n, p, q))
    f.close()
