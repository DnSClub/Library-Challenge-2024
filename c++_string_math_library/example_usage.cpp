#include <iostream>
#include <string>

#include "string_math_library.hpp"

int main() {
    std::string num1, num2;
    std::cout << "Enter two positive integer strings: ";
    std::cin >> num1 >> num2;

    //Addition
    std::string sum = vix::add_strings(num1, num2);
    std::cout << "Added Strings: " << sum << std::endl;

    //Subtraction
    std::string diff = vix::subtract_strings(num1, num2);
    std::cout << "Subtracted Strings: " << diff << std::endl;

    //Multiplication
    std::string product = vix::multiply_strings(num1, num2);
    std::cout << "Multiplied Strings: " << product << std::endl;

    //Division
    std::string quotient, remainder;
    //quotient = vix::divide_strings(num1, num2, remainder);
    quotient = vix::long_division(num1, num2, remainder);
    std::cout << "Divided Strings: " << quotient << ", Strings Remainder: " << remainder << std::endl;

    return 0;
}

