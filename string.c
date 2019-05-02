#include <string.h>
#include <stdlib.h>
#include "object.h"

extern Type String;

static int cmp(const Object *a, const Object *b) {
    return strcmp(a->data.String, b->data.String);
}

static Object *new_from_s(const char *s) {
    Object *new = malloc(sizeof(Object));
    new->type = &String;
    new->data.String = strdup(s);
    return new;
}

static void destroy(const Object *self) {
    free((void *)self->data.String);
    free((void *)self);
}

void String_init(void) {
    String.cmp = cmp;
    String.new_from_s = new_from_s;
    String.destroy = destroy;
}
