#include <stdio.h>
#include <stdint.h>

void set(void *buffer, size_t offset, int32_t value)
{
    *(((char*)buffer) + offset) = (char)value;
}
