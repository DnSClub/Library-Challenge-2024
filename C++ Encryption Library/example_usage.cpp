#include <iostream>
#include <string>
#include "encryption_with_key.hpp"

int main() {
	std::string input_string = "Hello World";
	std::string input_key = "DnS Club";
	
	std::cout<<"Original String: "<<input_string<<"\n";

	vix::cryption(input_string, input_key);

	std::cout<<"Encrypted String: "<<input_string<<"\n";

	vix::cryption(input_string, input_key);

	std::cout<<"Decrypted String: "<<input_string<<std::endl;
	return 0;
}
