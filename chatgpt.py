#!/usr/bin/python3
def factorize_to_two_numbers(n):
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            # i is a factor
            factor1 = i
            factor2 = n // i
            return factor1, factor2
    # If no factor is found, the number is prime
    return None

# Replace this with the number you want to factorize
number_to_factorize = 2497885147362973

result = factorize_to_two_numbers(number_to_factorize)

if result:
    factor1, factor2 = result
    print(f"The factors of {number_to_factorize} are: {factor1} and {factor2}")
else:
    print(f"{number_to_factorize} is a prime number.")