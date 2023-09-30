#include <stdio.h>
#include <stdint.h>

void set(void *buffer, size_t offset, int32_t value)
{
    printf("set: %lu = %i\n", offset, value);

    *(((char*)buffer) + offset) = (char)value;

    return true;
}
