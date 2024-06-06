#include <stdio.h>
#include "vix_string.h"

int main() {
    vix_string* str1 = create_string("Hello ");
    vix_string* str2 = create_string("World");

    vix_string* str3 = merge_strings(str1, str2);

    printf("Combined string: %s\n", get_string(str3));
    printf("Length of the combined string: %zu\n", get_string_length(str3));

    free_string(str1);
    free_string(str2);
    free_string(str3);

    return 0;
}
