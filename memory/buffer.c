#include <stddef.h>
#include <stdlib.h>

void *empty()
{
    return 0;
}

int isEmpty(void *buffer)
{
    return buffer == 0;
}

void *alloc(size_t size)
{
    void *data = malloc(size + sizeof(size));

    memcpy(data, &size, sizeof(size));

    return data;
}
