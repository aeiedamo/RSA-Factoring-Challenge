#!/usr/bin/python3
#cython: language_level=3
from math import *
from sys import *

def primes(number):
        primenums = []
        if number % 2 == 0:
                primenums.append(2)
        for i in range(3, number + 1, 2):
                if len(primenums) >= 1:
                        return (primenums)
                prime = False
                for j in primenums:
                        if i % j == 0:
                                prime = True
                                break
                if prime == False and number % i == 0:
                        primenums.append(i)
        return (primenums)

if __name__ == "__main__":
        if (len(argv) != 2):
                print("Usage: {} <file>".format(argv[0]))
                exit(1)
        file = open(argv[1], 'r')
        for line in file:
                intline = int(line)
                primelst = (primes(intline))[0]
                print("{}={}*{}".format(intline, intline//primelst, primelst))
        file.close()