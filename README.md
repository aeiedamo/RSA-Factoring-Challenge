## RSA-Factoring-Challenge
A challenge to factor a number to 2 smaller numbers and prime numbers.

## 0. Factorize all the things!
In 'factors' I have used the trial factoring method which is pretty much direct.
It was written with python.

## 1. RSA Factoring Challenge
In 'rsa' file I have used the trial factoring method with some tweaking.
Since all prime numbers' first-right-digit are either 1, 3, 7 or 9 we can
use this fact to improve performance by moving 10 numbers at a time instead
of 2.

## Note
Since both programs were written in python, the performance took a hit and it
can be improved by using C, Rust or assembly.
