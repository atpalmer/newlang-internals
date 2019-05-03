#ifndef OBJECT_H
#define OBJECT_H

#include <stdbool.h>
#include "type.h"

typedef struct object {
    union {
        long Integer;
        const char *String;
    } data;
    Type *type;
} Object;

void object_destroy(const Object *self);
const Object *object_invoke(const Object *self, const char *attr_name);
bool object_equals(const Object *self, const Object *other);
bool object_gt(const Object *self, const Object *other);
bool object_lt(const Object *self, const Object *other);

#endif
