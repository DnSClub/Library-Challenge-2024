/*
    Note: the main function below utilizes Kotlin coroutines instead of threads. It is highly recommended that you try them out :)
    An equivalent example has been provided for those of us who prefer threads
 */
fun main(): Unit = runBlocking {
    val server = CustomServer(15000)
    val client = CustomClient("localhost", 15000)

    // use a coroutine to start the server in a different thread,
    // otherwise it will block this thread while waiting for a client to accept
    launch (Dispatchers.Default) {
        server.establishConnection()
    }

    delay(1000L)    // give the server enough time to set up

    // some interaction
    client.establishConnection()
    client.sendMsg("Who are you?!")
    println(server.readMsg())
    server.sendMsg("I'm Batman")
    println(client.readMsg())

    // close sockets plus readers and writers
    client.closeConnection()
    server.closeConnection()
}

/*fun main() {
    val server = CustomServer(15000)
    val client = CustomClient("localhost", 15000)

    // set up & start server thread
    val serverInitializingThread = Thread { server.establishConnection() }
    serverInitializingThread.start()

    Thread.sleep(1000L) // give the server enough time to set up

    // some interaction
    client.establishConnection()
    client.sendMsg("Who are you?!")
    println(server.readMsg())
    server.sendMsg("I'm Batman")
    println(client.readMsg())

    // wait for the server initialization thread to release all its resources properly & watch for exceptions
    try {
        serverInitializingThread.join()
    } catch (e: Exception) { e.printStackTrace() }

    // close sockets plus readers and writers
    client.closeConnection()
    server.closeConnection()
}*/