#include <stdio.h>
#include <math.h>
#include <stdlib.h>

size_t factorize(size_t number)
{
    size_t i;

    if (number % 2 == 0)
        return (2);

    for (i = 3; i <= (size_t)sqrt(number); i += 2)
        if (number % i == 0)
            return (i);
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