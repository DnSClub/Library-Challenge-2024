#define ENCRYPTION_W_KEY_LIB
#pragma once
#include <string>

namespace vix {

	inline void cryption(std::string& input, const std::string& key) {
		const size_t key_size = key.size();
		const size_t input_size = input.size();
		
		for (size_t i = 0; i < input_size; i++) {
			input[i] ^= key[i % key_size];
		}
	}

}
