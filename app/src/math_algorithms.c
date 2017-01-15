#include <stdint.h>

double my_alg (double x)
{
    return (x * x) + 1;
}

double raw_to_celcius (uint16_t raw_data)
{
    return ((double)raw_data / 100.0) +
           -50.0;
}
