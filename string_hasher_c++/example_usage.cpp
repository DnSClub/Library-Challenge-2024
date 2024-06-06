#include <string>
#include <iostream>
#include "hash_cpp.h"

int main() {
	std::string str = "this is a string";
	switch (GENHASH(str.c_str())) {
		case SETHASH("this is a string"):
			std::cout<<"Hash match was found\n";
			break;
		default:
			std::cout<<"No match found\n";
			break;
	}
	return 0;
}
