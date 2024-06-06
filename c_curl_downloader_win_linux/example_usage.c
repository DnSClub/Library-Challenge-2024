#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "curl_downloader_alt.h"

int main() {
    const char* url_str = "https://lumpology.com/wp-content/uploads/2023/06/dnsclub.png";
    const char* file_output_name = "downloaded_file.png";
    if (curl_download(file_output_name, url_str)) {
        printf("File %s was downloaded!\n", file_output_name);
    } else {
        printf("File %s was not downloaded\n", file_output_name);
    }
    return 0;
}
