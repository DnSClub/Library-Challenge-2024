#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_file_exist(const char* input) {
    FILE* file_check = fopen(input, "r");
    if (file_check != NULL) {
        fclose(file_check);
        return 1;
    }
    return 0;
}

int curl_download(const char* input, const char* url) {
    char combined_express[256];
    snprintf(combined_express, sizeof(combined_express), "curl -o \"%s\" \"%s\"", input, url);
    int reporter = system(combined_express);
    if (reporter == 0) {
        return check_file_exist(input);
    } else {
        return 0;
    }
}
