#include <memzero.h>

void memzero(void *ptr, size_t size) {
    uint8_t *buf = (uint8_t *) ptr;
    for (size_t i = 0; i < size; i++) {
        buf[i] = 0;
    }
}