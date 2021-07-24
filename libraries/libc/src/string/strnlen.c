#include <string.h>

size_t strnlen(const char *s, size_t maxlen)
{
    size_t len = 0;

    while (maxlen-- && *s++) {
        len++;
    }

    return len;
}
