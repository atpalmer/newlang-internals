#include <assert.h>
#include <ctype.h>
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

static const Object *to_upper(const Object *self, void *data) {
    char *new_string = strdup(self->data.String);
    char *p = new_string;
    while(*p = toupper(*p)) {
        ++p;
    }
    Object *result = new_from_s(new_string);
    free((void *)new_string);
    return result;
}

void String_init(void) {
    String.cmp = cmp;
    String.new_from_s = new_from_s;
    String.destroy = destroy;
    String.attrs = malloc(sizeof(struct type_attribute) * 2);
    String.attrs[0] = (struct type_attribute){ .name = "toUpper", .invoke = to_upper };
    String.attrs[1] = (struct type_attribute){ NULL, NULL };
}
