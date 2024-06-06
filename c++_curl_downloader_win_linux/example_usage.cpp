#include <iostream>
#include <string>
#include "curl_downloader_alt.hpp"

int main() {
	std::string url_str = "https://lumpology.com/wp-content/uploads/2023/06/dnsclub.png";
	std::string file_output_name = "downloaded_file.png";
	if (vix::curl_download(file_output_name, url_str)) {
		std::cout<<"File "<<file_output_name<<" was downloaded!"<<std::endl;
	} else {
		std::cout<<"File "<<file_output_name<< "was not downloaded"<<std::endl;
	}
	return 0;
}
