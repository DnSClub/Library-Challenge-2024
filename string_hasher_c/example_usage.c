#include <stdio.h>
#include <string.h>
#include "hash_c_ver.h"

int main() {
    const char* str = "this is a string";
    if (GENHASH(str)==SETHASH("this is a string")) {
    	printf("Hash match was found\n");
    } else {
    	printf("No match found\n");
    }
    return 0;
}
