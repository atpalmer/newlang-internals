#ifndef TYPE_H
#define TYPE_H

struct object;

typedef const struct object *(*attr_func)(const struct object *self, void *data);

struct type_attribute {
    const char *name;
    attr_func invoke;
};

typedef struct {
    struct object *(*new_from_s)(const char *s);
    void (*destroy)(const struct object *self);
    int (*cmp)(const struct object *self, const struct object *other);
    struct type_attribute *attrs;
} Type;

void type_init(void);
void type_destroy(void);

#include "integer.h"
#include "string.h"

#endif
