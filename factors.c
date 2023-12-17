#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

size_t find_factor(size_t number)
{
        size_t i;

        if (number % 2 == 0)
                return (2);

        for (i = 3; i < (size_t)sqrt(number); i+=2)
                if (number % i == 0)
                        return (i);
        return (1);
}

int main(int argc, char **argv)
{
        FILE *f;
        int len = 255;
        char lineptr[255] = {0};
        size_t number, factor;
        char *newline;

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
        while (fgets(lineptr, len, f))
        {
                if ((newline = strchr(lineptr, '\n')))
                        *newline = '\0';
                number = atoi(lineptr);
                factor = find_factor(number);
                printf("%s=%ld*%ld\n", lineptr, number/factor, factor);
        }
        fclose(f);
        return (0);
}