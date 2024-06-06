#include <cstdlib>
#include <cstdio>
#include <string>
#include <fstream>
#include <iostream>

namespace vix{
	bool check_file_exist (const std::string & input) {
    	std::ifstream file_check(input.c_str());
    	return file_check.good();
	}

	bool curl_download(const std::string & input, const std::string & url) {
		std::string combined_express = "curl -o \"" + input + "\" \"" + url + "\"";
		bool reporter = std::system(combined_express.c_str()); 
		if (!reporter) {
			return check_file_exist(input);
		} else {
			return false;
		}
	}
}
