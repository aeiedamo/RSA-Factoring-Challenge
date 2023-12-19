#include <stdio.h>
#include <gmp.h>

int main()
{
        mpz_t num1;

        mpz_init(num1);
        mpz_init_set_str(num1, "28957093857032957802397093457", 10);

        gmp_printf("%Zd\n", num1);
        return (0);
}