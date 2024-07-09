class CustomServer(private val port: Int): SocketConnection("Server")
{
    private lateinit var serverSocket: ServerSocket
    private lateinit var clientSocket: Socket

    public override fun establishConnection() {
        println("${this.name}: awaiting clients...")
        try {
            serverSocket = ServerSocket(port)
            clientSocket = serverSocket.accept()
            reader = BufferedReader(InputStreamReader(clientSocket.getInputStream()))
            writer = PrintWriter(clientSocket.getOutputStream(), true)
            println("${this.name}: connection established")
            connectionEstablished = true
        } catch (e: Exception)
        {
            e.printStackTrace()
        }
    }

    override fun closeSockets() {
        serverSocket.close()
        clientSocket.close()
    }
}