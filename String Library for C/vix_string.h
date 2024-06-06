#define VIX_STRING_HEADER_GUARD
#include <stdlib.h>
#include <string.h>

//string structure implementation
typedef struct {
    char* data;
    size_t length;
} vix_string;

//create a new string from a C string pointer
vix_string* create_string(const char* cstr) {
    vix_string* str = (vix_string*)malloc(sizeof(vix_string));
    if (str) {
        str->length = strlen(cstr);
        str->data = (char*)malloc(str->length + 1);
        if (str->data) {
            strcpy(str->data, cstr);
        } else {
            free(str);
            str = NULL;
        }
    }
    return str;
}

// Get the length of a string
size_t get_string_length(const vix_string* str) {
    return str->length;
}

//merge two strings
vix_string* merge_strings(const vix_string* str1, const vix_string* str2) {
    size_t new_length = str1->length + str2->length;
    vix_string* new_string = (vix_string*)malloc(sizeof(vix_string));
    if (new_string) {
        new_string->length = new_length;
        new_string->data = (char*)malloc(new_length + 1);
        if (new_string->data) {
            strcpy(new_string->data, str1->data);
            strcat(new_string->data, str2->data);
        } else {
            free(new_string);
            new_string = NULL;
        }
    }
    return new_string;
}

char* get_string(const vix_string* str) {
    return str->data;
}

//free the data from a string
void free_string(vix_string* str) {
    free(str->data);
    free(str);
}
