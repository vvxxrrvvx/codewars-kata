from preloaded import TEXT2HEX

class HexCipher:
    @classmethod
    def encode(cls, s, n):
        # Apply encoding n times
        encoded = s
        for _ in range(n):
            encoded = ''.join(TEXT2HEX.get(c, c) for c in encoded)

        return encoded

    @classmethod
    def decode(cls, s, n):
        # Apply decoding n times
        decoded = s
        for _ in range(n):
            decoded = ''.join(chr(int(decoded[i:i+2], 16)) if decoded[i:i+2] in TEXT2HEX.values() else decoded[i:i+2] for i in range(0, len(decoded), 2))

        return decoded