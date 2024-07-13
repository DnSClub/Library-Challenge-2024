import com.google.zxing.BarcodeFormat
import com.google.zxing.EncodeHintType
import com.google.zxing.qrcode.QRCodeWriter
import com.google.zxing.qrcode.decoder.ErrorCorrectionLevel
import java.awt.Color
import java.awt.Graphics2D
import java.awt.image.BufferedImage
import java.io.File
import javax.imageio.ImageIO

class QRCodeGenerator {
    fun createQRImg(qrFile: File, qrCodeText: String, imageSize: Int, fileType: String) {
        // need a map to specify the error correction level:
        // L: ~7% M: ~15% Q: ~25% H: ~30%
        val hintMap: Map<EncodeHintType, ErrorCorrectionLevel> = mapOf(EncodeHintType.ERROR_CORRECTION to ErrorCorrectionLevel.H)

        val qrCodeWriter = QRCodeWriter()

        // create bit matrix that has the encoded text in QR code format, with the specified error correction level
        val bitMatrix = qrCodeWriter.encode(qrCodeText, BarcodeFormat.QR_CODE, imageSize, imageSize, hintMap)

        // specify matrix dimensions... here the same width & height are used so the generated image is square
        val matrixDim = bitMatrix.width
        // image with an associated buffer that has the specified dimensions and type
        val image = BufferedImage(matrixDim, matrixDim, BufferedImage.TYPE_INT_RGB)

        // graphics2D object for 2D rendering
        val graphics = image.graphics as Graphics2D
        graphics.color = Color.WHITE    // start with white for background
        graphics.fillRect(0, 0, matrixDim, matrixDim)   // draw white background
        graphics.color = Color.BLACK    // change to black for contents of the code
        for (i in 0..< matrixDim) {
            for (j in 0..< matrixDim) {
                if (bitMatrix.get(i, j))
                {
                    graphics.fillRect(i, j, 1, 1)
                }
            }
        }

        // write the image to the specified destination with the given type
        ImageIO.write(image, fileType, qrFile)
    }
}