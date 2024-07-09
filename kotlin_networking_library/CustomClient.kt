class CustomClient(private val host: String, private val port: Int): SocketConnection("Client")
{

    private lateinit var socket: Socket

    public override fun establishConnection()
    {
        println("${this.name}: connection attempt...")
        try {
            socket = Socket(host, port)
            reader = BufferedReader(InputStreamReader(socket.getInputStream()))
            writer = PrintWriter(socket.getOutputStream(), true)
            connectionEstablished = true
            println("${this.name}: connected to server")
        } catch (e: Exception)
        {
            e.printStackTrace()
        }
    }

    override fun closeSockets() = socket.close()

}