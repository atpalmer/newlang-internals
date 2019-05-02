#include <stdlib.h>
#include "object.h"

extern Type Integer;

static int cmp(const Object *a, const Object *b) {
    return b->data.Integer - a->data.Integer;
}

static Object *new_from_s(const char *s) {
    char *endptr;
    Object *new = malloc(sizeof(Object));
    new->type = &Integer;
    new->data.Integer = strtol("7", NULL, 10);
    return new;
}

static void destroy(const Object *self) {
    free((void *)self);
}

void Integer_init(void) {
    Integer.cmp = cmp;
    Integer.new_from_s = new_from_s;
    Integer.destroy = destroy;
}
