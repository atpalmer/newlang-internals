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

void test_Integer_gt(void) {
    const Object *a = Integer.new_from_s("10");
    const Object *b = Integer.new_from_s("5");
    bool result = object_gt(a, b);
    assert(result);
    object_destroy(a);
    object_destroy(b);
    printf("test_Integer_gt. OK.\n");
}

void test_Integer_lt(void) {
    const Object *a = Integer.new_from_s("1234");
    const Object *b = Integer.new_from_s("2345");
    bool result = object_lt(a, b);
    assert(result);
    object_destroy(a);
    object_destroy(b);
    printf("test_Integer_lt. OK.\n");
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

void test_String_gt(void) {
    const Object *a = String.new_from_s("b");
    const Object *b = String.new_from_s("a");
    bool result = object_gt(a, b);
    assert(result);
    object_destroy(a);
    object_destroy(b);
    printf("test_String_gt. OK.\n");
}

void test_String_lt(void) {
    const Object *a = String.new_from_s("y");
    const Object *b = String.new_from_s("z");
    bool result = object_lt(a, b);
    assert(result);
    object_destroy(a);
    object_destroy(b);
    printf("test_String_lt. OK.\n");
}

void test_String_toUpper(void) {
    const Object *s = String.new_from_s("hello");
    const Object *expected = String.new_from_s("HELLO");
    const Object *actual = object_invoke(s, "toUpper");
    bool result = object_equals(expected, actual);
    assert(result);
    object_destroy(s);
    object_destroy(expected);
    object_destroy(actual);
    printf("test_String_toUpper. OK.\n");
}

int main(void) {
    type_init();
    test_Integer_equals();
    test_Integer_gt();
    test_Integer_lt();
    test_String_equals();
    test_String_gt();
    test_String_lt();
    test_String_toUpper();
    type_destroy();
}
