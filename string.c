#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "object.h"

extern Type String;

static int cmp(const Object *a, const Object *b) {
    assert(a->type == &String && b->type == &String);
    return strcmp(a->data.String, b->data.String);
}

static Object *new_from_s(const char *s) {
    assert(s != NULL);
    Object *new = malloc(sizeof(Object));
    new->type = &String;
    new->data.String = strdup(s);
    return new;
}

static void destroy(const Object *self) {
    assert(self->type == &String);
    free((void *)self->data.String);
    free((void *)self);
}

void String_init(void) {
    String.cmp = cmp;
    String.new_from_s = new_from_s;
    String.destroy = destroy;
}
