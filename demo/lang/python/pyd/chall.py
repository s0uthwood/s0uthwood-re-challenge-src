def crypt(plain):
	cipher = b''
	for p in plain:
		cipher += (p ^ 0x23).to_bytes(1, 'little')
	return cipher