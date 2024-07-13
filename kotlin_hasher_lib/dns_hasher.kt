package dns_hasher

object dns_hasher {
    private const val FNV_OFFSET_BASIS = 2166136261u
    private const val FNV_PRIME = 16777619u

    fun uirn(s: String, count: Int): UInt {
        return if (count > 0) {
            (uirn(s, count - 1) xor s[count - 1].code.toUInt()) * FNV_PRIME
        } else {
            FNV_OFFSET_BASIS
        }
    }

    fun setHash(s: String): UInt {
        return uirn(s, s.length)
    }
}
