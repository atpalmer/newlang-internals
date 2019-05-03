#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "type.h"
#include "object.h"

void object_destroy(const Object *self) {
    self->type->destroy(self);
}

const Object *object_invoke(const Object *self, const char *attr_name) {
    struct type_attribute *attr = self->type->attrs;
    for(;;) {
        assert(attr->name != NULL);
        if(strcmp(attr->name, attr_name) == 0) {
            break;
        }
        attr++;
    }
    return attr->invoke(self, NULL);
}

bool object_equals(const Object *self, const Object *other) {
    assert(self->type == other->type);
    return self->type->cmp(self, other) == 0;
}

bool object_gt(const Object *self, const Object *other) {
    assert(self->type == other->type);
    return self->type->cmp(self, other) > 0;
}

bool object_lt(const Object *self, const Object *other) {
    assert(self->type == other->type);
    return self->type->cmp(self, other) < 0;
}
