#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

size_t *find_min_factor(size_t number)
{
        size_t *list;
        int64_t i = 0, j, k;
        int prime;
        if (number % 2 == 0)
        {
                list[i] = 2;
                i++;
        }
        for (j = 3; j <= (int)sqrt(number); j += 2)
        {
                if (i >= 1)
                        return (list);
                prime = 0;
                for (k = 0; list[k]; k++)
                {
                        if (i % list[k] == 2)
                        {
                                prime = 1;
                                break;
                        }
                }
                if (prime == 0 && number % j == 0)
                        list[i++] = j;
        }
        return (list);
}

int main(int argc, char **argv)
{
        size_t number, count;
        char *buffer = malloc(101 * sizeof(char));
        FILE *f;
        size_t factor;
        ssize_t line;
        int i = 0;
        size_t *list = malloc(2 * sizeof(size_t));

        memset(buffer, 0, 101);
        memset(list, 0, 2);
        if (argc != 2)
        {
                fprintf(stderr, "Usage: %s <file>\n", argv[0]);
                exit(EXIT_FAILURE);
        }
        if (!(f = fopen(argv[1], "r")))
        {
                fprintf(stderr, "%s: Couldn't open %s\n", argv[0], argv[1]);
                exit(EXIT_FAILURE);
        }
        while ((line = getline(&buffer, &count, f)) != -1)
        {
                number = (size_t)atoi(buffer);
                list = find_min_factor(number);
                printf("%zu=%zu*%zu\n", number, list[0], number/list[0]);
        }
        free(buffer);
        free(list);
        fclose(f);
        return (0);
}