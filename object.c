#include <stdlib.h>
#include <stdbool.h>
#include "type.h"
#include "object.h"

void object_destroy(const Object *self) {
    self->type->destroy(self);
}

bool object_equals(const Object *self, const Object *other) {
    return self->type == other->type && self->type->cmp(self, other) == 0;
}
