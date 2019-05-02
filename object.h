#ifndef OBJECT_H
#define OBJECT_H

#include "type.h"

typedef struct object {
    union {
        long Integer;
        const char *String;
    } data;
    Type *type;
} Object;

void object_destroy(const Object *self);
bool object_equals(const Object *self, const Object *other);

#endif
