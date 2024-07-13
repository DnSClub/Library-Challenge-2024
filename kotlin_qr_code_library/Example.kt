import java.io.File

fun main()
{
    val qrCodeText = "https://www.example.com"
    val filePath = "example.jpg"
    val fileType = "jpg"
    val imageDimension = 300 // in pixels
    val qrFilePath = File(filePath)

    val qrGenerator = QRCodeGenerator()
    qrGenerator.createQRImg(qrFilePath, qrCodeText, imageDimension, fileType)
}