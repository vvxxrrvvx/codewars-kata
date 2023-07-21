class VigenereCipher(object):
    def __init__(self, key, alphabet):
        self.key = key
        self.alphabet = alphabet

    def encode(self, text):
        encoded_text = ""
        key_length = len(self.key)

        for i, char in enumerate(text):
            if char not in self.alphabet:
                encoded_text += char
            else:
                shift = self.alphabet.index(self.key[i % key_length])
                encoded_char = self.alphabet[(self.alphabet.index(char) + shift) % len(self.alphabet)]
                encoded_text += encoded_char

        return encoded_text

    def decode(self, text):
        decoded_text = ""
        key_length = len(self.key)

        for i, char in enumerate(text):
            if char not in self.alphabet:
                decoded_text += char
            else:
                shift = self.alphabet.index(self.key[i % key_length])
                decoded_char = self.alphabet[(self.alphabet.index(char) - shift) % len(self.alphabet)]
                decoded_text += decoded_char

        return decoded_text