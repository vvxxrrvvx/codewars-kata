def ipv4_to_binary(ipv4_addr: str) -> str:
    octets = ipv4_addr.split('.')
    binary_octets = [format(int(octet), '08b') for octet in octets]
    return '.'.join(binary_octets)