#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include "type.h"
#include "object.h"

void object_destroy(const Object *self) {
    self->type->destroy(self);
}

bool object_equals(const Object *self, const Object *other) {
    assert(self->type == other->type);
    return self->type->cmp(self, other) == 0;
}

bool object_gt(const Object *self, const Object *other) {
    assert(self->type == other->type);
    return self->type->cmp(self, other) > 0;
}
