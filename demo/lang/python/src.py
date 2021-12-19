import dis

# flag{Python_Bytecode}

def main():
    flag = input("Input your license:\n")
    if len(flag) < 21:
        return
    flag = [ord(i) for i in flag]
    res = [0] * len(flag)
    for i in range(len(flag)):
        flag[i] ^= (0x20 if i % 2 == 0 else 0x10)
    for i in range(len(flag)):
        res[i] = (flag[i] + i) ^ (i % 3)
        res[len(flag) - i - 1] = (flag[len(flag) - i - 1] + i) ^ (i % 3)
    # print (res)
    cipher = [88, 142, 83, 138, 106, 79, 101, 112, 84, 136, 89, 88, 110, 119, 96, 132, 82, 146, 86, 137, 115]
    c = 0
    for i in range(len(cipher)):
        c |= cipher[i] ^ res[i]
    print ("Good" if c == 0 else "Wrong")

# main()
print (dis.dis(main))