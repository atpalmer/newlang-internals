#ifndef TYPE_H
#define TYPE_H

#include <stdbool.h>

struct object;

typedef struct {
    struct object *(*new_from_s)(const char *s);
    void (*destroy)(const struct object *self);
    bool (*equals)(const struct object *self, const struct object *other);
} Type;

void type_init(void);

#include "integer.h"
#include "string.h"

#endif
