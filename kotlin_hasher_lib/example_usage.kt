import dns_hasher.dns_hasher

fun main() {
    val str = "examples"
    println("SETHASH: ${dns_hasher.setHash(str)}")
}
