#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include "type.h"
#include "object.h"

extern Type Integer;
extern Type String;

void test_Integer_equals(void) {
    const Object *a = Integer.new_from_s("7");
    const Object *b = Integer.new_from_s("7");
    bool result = object_equals(a, b);
    assert(result);
    object_destroy(a);
    object_destroy(b);
    printf("test_Integer_equals. OK.\n");
}

void test_String_equals(void) {
    const Object *a = String.new_from_s("Hello, world");
    const Object *b = String.new_from_s("Hello, world");
    bool result = object_equals(a, b);
    assert(result);
    object_destroy(a);
    object_destroy(b);
    printf("test_String_equals. OK.\n");
}

int main(void) {
    type_init();
    test_Integer_equals();
    test_String_equals();
}
