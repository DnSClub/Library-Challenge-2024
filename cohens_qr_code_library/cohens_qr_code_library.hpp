#include "deps/qrcodegen.hpp"
#include "deps/EasyBMP.h"

#define COHENS_QR_CODE

namespace vix {
	void generate_qr_code(std::string input_for_encoding, std::string output_file_name = "default.bmp") {

	    // Generate the QR code
	    qrcodegen::QrCode qrCode = qrcodegen::QrCode::encodeText(input_for_encoding.c_str(), qrcodegen::QrCode::Ecc::MEDIUM);

	    // Determine the size of the QR code
	    int qrSize = qrCode.getSize();

	    // Set the BMP image dimensions
	    int imageSize = qrSize * 10; // Increase the size for better visibility

	    // Create a BMP image object
	    BMP bmp;
	    bmp.SetSize(imageSize, imageSize);
	    bmp.SetBitDepth(24); // 24-bit color depth

	    // Set white color for the entire image
	    RGBApixel whitePixel;
	    whitePixel.Red = 255;
	    whitePixel.Green = 255;
	    whitePixel.Blue = 255;
	    for (int y = 0; y < imageSize; ++y) {
	        for (int x = 0; x < imageSize; ++x) {
	            bmp.SetPixel(x, y, whitePixel);
	        }
	    }

	    // Set black color for QR code modules
	    RGBApixel blackPixel;
	    blackPixel.Red = 0;
	    blackPixel.Green = 0;
	    blackPixel.Blue = 0;
	    for (int y = 0; y < qrSize; ++y) {
	        for (int x = 0; x < qrSize; ++x) {
	            if (qrCode.getModule(x, y)) {
	                // Scale the QR code modules to fit the BMP image
	                for (int dy = 0; dy < 10; ++dy) {
	                    for (int dx = 0; dx < 10; ++dx) {
	                        bmp.SetPixel(x * 10 + dx, y * 10 + dy, blackPixel);
	                    }
	                }
	            }
	        }
	    }

	    // Save the BMP image
	    output_file_name += ".bmp";
	    bmp.WriteToFile(output_file_name.c_str());
	}
}
