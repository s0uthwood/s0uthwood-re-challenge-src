cipher = [88, 142, 83, 138, 106, 79, 101, 112, 84, 136, 89, 88, 110, 119, 96, 132, 82, 146, 86, 137, 115]                                       

res = [0] * len(cipher)                                                 

for i in range(len(cipher)): 
    res[i] = (cipher[i] ^ (i % 3)) - i 
    res[len(cipher) - i - 1] = (cipher[len(cipher) - i - 1] ^ (i % 3)) - i 

for i in range(len(res)): 
    print (chr(res[i] ^ (0x20 if i % 2 == 0 else 0x10)), end='') 
                                                                        
# flag{Python_Bytecode}
