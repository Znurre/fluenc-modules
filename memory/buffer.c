#include <stddef.h>
#include <stdlib.h>
#include <string.h>

void *empty()
{
    return 0;
}

int isEmpty(void *buffer)
{
    return buffer == 0;
}

void *allocate(size_t size)
{
    void *data = malloc(size + sizeof(size));

    memcpy(data, &size, sizeof(size));

    return data;
}


void *reallocate(void* buffer, size_t size)
{
    void *data = realloc(buffer - sizeof(size), size + sizeof(size));

    memcpy(data, &size, sizeof(size));

    return data;
}
