import java.io.File

fun main()
{
    val qrCodeText = "https://www.example.com"
    val filePath = "example.jpg"
    val fileType = "jpg"
    val imageDimension = 300 // in pixels
    val qrFile = File(filePath)

    val qrGenerator = QRCodeGenerator()
    qrGenerator.setErrorCorrectionLevel('l')
    val qr = qrGenerator.generateQRImg(qrCodeText, imageDimension)
    qrGenerator.saveQRImg(qr, fileType, qrFile)
    qrGenerator.showQRImg(qr)
}