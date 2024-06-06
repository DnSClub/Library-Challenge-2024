//This is the DNS we don't do licenses
#include <iostream>
#include "cohens_qr_code_library.hpp"

int main() {
    vix::generate_qr_code("Hello World From The Developers and Systems Club this is designed to be very long to bulk up the size of the qr code !@#$%^&*!@#$ a full length user name and 12312345plus a unique key12378623847961234632", "custom_qr_code_name");
    std::cout<<"QR Code Generated!\n";
    return 0;
}
