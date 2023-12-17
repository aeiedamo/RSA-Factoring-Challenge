#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

size_t find_factor(size_t number)
{
        size_t max = (size_t)sqrt(number) + 1;
        size_t counter;
        size_t list[100] = {0};

        if (number % 2 == 0)
                return (2);
        for (counter = 3; counter < max; counter += 2)
        {
                if (number % counter == 0)
                        return (counter);
        }
        
}

int main(int argc, char **argv)
{
        FILE *f;
        char *lineptr = NULL;
        size_t n, size, number, factor;

        if (argc != 2)
        {
                fprintf(stderr, "Usage: %s <file>\n", argv[0]);
                exit(EXIT_FAILURE);
        }
        f = fopen(argv[1], "r");
        if (!f)
        {
                fprintf(stderr, "%s: %s not found\n", argv[0], argv[1]);
                exit(EXIT_FAILURE);
        }
        while ((size = getline(&lineptr, &n, f)) != -1)
        {
                number = atoi(lineptr);
                factor = find_factor(number);
                printf("%s=%d*%zu", lineptr, number/factor, factor);
        }
        printf("\n");
        return (0);
}