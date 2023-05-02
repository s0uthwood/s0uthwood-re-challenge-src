from chall import *

a = input()
a = a.encode()
b = crypt(a)
res = [69, 79, 66, 68, 88, 65, 66, 65, 90, 124, 83, 90, 71, 94]

if len(b) == len(res):
	for i in range(len(b)):
		if b[i] != res[i]:
			break
	else:
		print ("True")
		exit(0)

print ("False")