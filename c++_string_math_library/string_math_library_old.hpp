#include <iostream>
#include <string>
#include <algorithm>

#define VIX_STRING_MATH_LIB

namespace vix {

	//Function to add two positive integer strings
	std::string add_strings(const std::string& num1, const std::string& num2) {
	    std::string result;
	    int carry = 0;
	    int i = num1.length() - 1, j = num2.length() - 1;

	    while (i >= 0 || j >= 0 || carry > 0) {
		int sum = carry;
		if (i >= 0) {
		    sum += num1[i] - '0';
		    i--;
		}
		if (j >= 0) {
		    sum += num2[j] - '0';
		    j--;
		}
		carry = sum / 10;
		sum %= 10;
		result.push_back('0' + sum);
	    }

	    std::reverse(result.begin(), result.end());
	    return result;
	}

	//Function to subtract two positive integer strings (num1 >= num2)
	std::string subtract_strings(const std::string& num1, const std::string& num2) {
	    std::string result;
	    int borrow = 0;
	    int i = num1.length() - 1, j = num2.length() - 1;

	    while (i >= 0) {
		int digit = num1[i] - '0' - borrow;
		if (j >= 0) {
		    digit -= (num2[j] - '0');
		    j--;
		}
		if (digit < 0) {
		    digit += 10;
		    borrow = 1;
		} else {
		    borrow = 0;
		}
		result.push_back('0' + digit);
		i--;
	    }

	    //Remove leading zeros
	    while (result.length() > 1 && result.back() == '0') {
		result.pop_back();
	    }

	    std::reverse(result.begin(), result.end());
	    return result;
	}

	//Function to multiply a positive integer string by a single-digit integer
	std::string multiply_string_by_digit(const std::string& num, int digit) {
	    if (digit == 0) return "0";
	    
	    std::string result;
	    int carry = 0;

	    for (int i = num.length() - 1; i >= 0; i--) {
		int product = (num[i] - '0') * digit + carry;
		carry = product / 10;
		product %= 10;
		result.push_back('0' + product);
	    }

	    if (carry > 0) {
		result.push_back('0' + carry);
	    }

	    std::reverse(result.begin(), result.end());
	    return result;
	}

	//Function to multiply two positive integer strings
	std::string multiply_strings(const std::string& num1, const std::string& num2) {
	    if (num1 == "0" || num2 == "0") return "0";

	    std::string result = "0";
	    for (int i = num2.length() - 1; i >= 0; i--) {
		std::string partialResult = multiply_string_by_digit(num1, num2[i] - '0');
		for (int j = 0; j < num2.length() - 1 - i; j++) {
		    partialResult.push_back('0');
		}
		result = add_strings(result, partialResult);
	    }

	    return result;
	}

	//Function to divide a positive integer string by a single-digit integer
	std::string divide_string_by_digit(const std::string& num, int divisor, int& remainder) {
	    std::string result;
	    int idx = 0;
	    int dividend = num[idx] - '0';

	    while (idx < num.length()) {
		if (dividend < divisor) {
		    idx++;
		    dividend = dividend * 10 + (num[idx] - '0');
		    result.push_back('0');
		} else {
		    result.push_back('0' + dividend / divisor);
		    dividend = dividend % divisor;
		    idx++;
		}
	    }

	    remainder = dividend;
	    return result;
	}

	//Function to divide two positive integer strings
	std::string divide_strings(const std::string& num1, const std::string& num2, std::string& remainder) {
	    if (num2 == "0") {
		std::cout << "Error: Division by zero.\n";
		return "";
	    }

	    if (num1 == "0") {
		remainder = "0";
		return "0";
	    }

	    std::string result;
	    int idx = 0;
	    std::string currentDividend;

	    while (idx < num1.length()) {
		currentDividend.push_back(num1[idx]);
		int currentQuotient = 0;
		while (currentDividend >= num2) {
		    currentDividend = subtract_strings(currentDividend, num2);
		    currentQuotient++;
		}
		result.push_back('0' + currentQuotient);
		idx++;
	    }

	    //Remove leading zeros from the result
	    while (result.length() > 1 && result.front() == '0') {
		result.erase(result.begin());
	    }

	    remainder = currentDividend;
	    return result;
	}
}
