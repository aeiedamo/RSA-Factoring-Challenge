#include <stdio.h>
#include <math.h>
#include <stdlib.h>

size_t ten_times(size_t number, size_t first_prime)
{
    size_t max = (size_t)sqrt(first_prime) + 1;
    size_t i;

    if (first_prime == 1 || first_prime == 9)
        first_prime += 10;
    for (i = first_prime; i < max; i += 10)
    {
        if (number % i == 0)
            return (i);
    }
    return (0);
}


size_t factorize(size_t number)
{
    size_t i, modulo;
    char primes[4] = {0};
    size_t factor;

    if (number % 2 == 0)
        return (2);
    if (number % 5 == 0)
        return (5);
    modulo = number % 10;
    primes[0] = '3';
    if (modulo == 1)
    {
        primes[1] = '1';
        primes[2] = '9';
    }
    else if (modulo == 3 || modulo == 7)
        primes[1] = '7';
    else if (modulo == 9)
    {
        primes[1] = '1';
        primes[2] = '7';
    }

    for (i = 0; primes[i]; i++)
    {
        factor = ten_times(number, (primes[i]-'0'));
        if (factor != 0)
            return (factor);
    }
    return (0);
}

int main(int argc, char **argv)
{
    size_t number, factor, size;
    FILE *f;
    char line[100] = {0};

    if (argc != 2)
    {
        fprintf(stderr, "Usage: factors <file>\n");
        exit(EXIT_FAILURE);
    }
    f = fopen(argv[1], "r");
    if (!f)
    {
        fprintf(stderr, "%s: Couldn't open\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    while (fgets(line, sizeof(line), f))
    {
        number = atoi(line);
        factor = factorize(number);
        printf("%zu=%zu*%zu\n", number, number/factor, factor);
    }
    return (0);
}