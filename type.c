#include <stdlib.h>
#include "type.h"

void type_init(void) {
    Integer_init();
    String_init();
}

void type_destroy(void) {
    free(String.attrs);
}
