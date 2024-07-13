import com.google.zxing.BarcodeFormat
import com.google.zxing.EncodeHintType
import com.google.zxing.qrcode.QRCodeWriter
import com.google.zxing.qrcode.decoder.ErrorCorrectionLevel
import java.awt.Color
import java.awt.Graphics2D
import java.awt.image.BufferedImage
import java.io.File
import javax.imageio.ImageIO
import javax.swing.ImageIcon
import javax.swing.JFrame
import javax.swing.JLabel

class QRCodeGenerator {
    // based on code found at: https://www.digitalocean.com/community/tutorials/java-qr-code-generator-zxing-example

    // used in setErrorCorrectionLevel()
    private val nameToLevelMap = mapOf('l' to ErrorCorrectionLevel.L, 'm' to ErrorCorrectionLevel.M, 'q' to ErrorCorrectionLevel.Q, 'h' to ErrorCorrectionLevel.H)

    // a map to specify the error correction level
    private var hintMap = mutableMapOf(EncodeHintType.ERROR_CORRECTION to ErrorCorrectionLevel.H)

    // QRCode renderer
    private val qrCodeWriter = QRCodeWriter()

    // set how much of the pixels can be damaged while keeping the QR readable (will increase image size)
    // L: ~7% M: ~15% Q: ~25% H: ~30%
    fun setErrorCorrectionLevel(newLevel: Char): Boolean {
        if (nameToLevelMap.containsKey(newLevel.lowercaseChar())) {
            hintMap[EncodeHintType.ERROR_CORRECTION] = nameToLevelMap[newLevel.lowercaseChar()]!!
            return true
        }
        return false
    }

    // creates & saves the square QR image based on the details provided
    fun generateQRImg(qrCodeText: String, imageSize: Int): BufferedImage {
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
        for (i in 0..<matrixDim) {
            for (j in 0..<matrixDim) {
                if (bitMatrix.get(i, j)) {
                    graphics.fillRect(i, j, 1, 1)
                }
            }
        }

        return image
    }

    // save the QR image
    fun saveQRImg(image: BufferedImage, fileType: String, qrFile: File) = ImageIO.write(image, fileType, qrFile)

    // show the image in a JFrame
    fun showQRImg(image: BufferedImage)
    {
        val imgFrame = JFrame("QR Code")    // frame to be shown
        imgFrame.defaultCloseOperation = JFrame.EXIT_ON_CLOSE
        imgFrame.setSize(image.width, image.height)
        imgFrame.add(
            // label with the ImageIcon containing the image, centered in the display
            JLabel(
                ImageIcon(image)
            )
        )
        imgFrame.pack() // packs the window to the sizes of its components
        imgFrame.isVisible = true
    }

}