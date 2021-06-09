#include "mem.h"

void *safe_malloc(usize size) {
    void *mem = malloc(size);
    if (mem) {
        return mem;
    }
    fprintf(stderr, "malloc failed.\n");
    exit(1);
}

void *safe_calloc(usize members, usize member_size) {
    void *mem = calloc(members, member_size);
    if (mem) {
        return mem;
    }
    fprintf(stderr, "calloc failed.\n");
    exit(1);
}

void *safe_realloc(void *mem, usize size) {
    mem = realloc(mem, size);
    if (mem) {
        return mem;
    }
    fprintf(stderr, "realloc failed.\n");
    exit(1);
}

void *safe_box(void *stack_struct, usize size) {
    void *mem = safe_malloc(size);
    memcpy(mem, stack_struct, size);
    return mem;
}
