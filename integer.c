#include <assert.h>
#include <stdlib.h>
#include "object.h"

extern Type Integer;

static int cmp(const Object *a, const Object *b) {
    assert(a->type == &Integer && b->type == &Integer);
    return a->data.Integer - b->data.Integer;
}

static Object *new_from_s(const char *s) {
    assert(s != NULL);
    char *endptr;
    Object *new = malloc(sizeof(Object));
    new->type = &Integer;
    new->data.Integer = strtol(s, NULL, 10);
    return new;
}

static void destroy(const Object *self) {
    assert(self->type == &Integer);
    free((void *)self);
}

void Integer_init(void) {
    Integer.cmp = cmp;
    Integer.new_from_s = new_from_s;
    Integer.destroy = destroy;
}
