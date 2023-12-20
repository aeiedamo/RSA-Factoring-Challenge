#!/usr/bin/python3
from math import *
from sys import *

def ten_times(number, first_prime):
    if (first_prime == 1 or first_prime == 9):
        first_prime += 10
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
    modulo = number % 10
    if (modulo == 1):
        primes = [1, 3, 9]
    elif (modulo == 3 or 7):
        primes = [3, 7]
    elif (modulo == 9):
        primes = [1, 3, 7]
    for i in primes:
        factor = ten_times(number, i)
        if (factor != -1):
            return (factor)

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
