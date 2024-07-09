abstract class SocketConnection(protected val name: String) {
    protected lateinit var reader: BufferedReader
    protected lateinit var writer: PrintWriter
    protected var connectionEstablished = false

    protected abstract fun establishConnection()

    fun readMsg(): String? {
        return if (connectionEstablished) {
            reader.readLine()
        } else {
            null
        }
    }

    fun sendMsg(line: String) {
        if (connectionEstablished) {
            writer.println(line)
        }
    }

    fun closeConnection() {
        try {
            closeSockets()
            reader.close()
            writer.close()
            println("$name: connection closed")
        } catch (e: Exception) {
            e.printStackTrace()
        }
    }

    protected abstract fun closeSockets()
}