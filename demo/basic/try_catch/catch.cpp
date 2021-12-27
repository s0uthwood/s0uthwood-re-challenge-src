#include <cstdio>
#include <exception>
#include <cstring>
#include <string>

using namespace std;

struct MyException1: public exception {
private:
	string message;
public:
	MyException1(): message("MyException1"){}
	~MyException1() throw(){}
};

struct MyException2: public exception {
private:
	string message;
public:
	MyException2(): message("MyException2"){}
	~MyException2() throw(){}
};

struct MyException3: public exception {
private:
	string message;
public:
	MyException3(): message("MyException3"){}
	~MyException3() throw(){}
};

char cipher[] = {0x54, 0x5e, 0x53, 0x55, 0x69, 0x31, 0x42, 0x5e, 0x67, 0x61, 0x31, 0x53, 0x66, 0x51, 0x5a, 0x6f};

int main(){
	char input[0x20];
	printf("Hello challenger, tell me the flag to prove that you reverse me:\n");

	for (int i = 0; i < 3; i++) {
		try {
			switch(i) {
				case 0:
					throw MyException1();
				case 1:
					throw MyException2();
				case 2:
					throw MyException3();
			}
		} catch (MyException2& e) {
			for (int j = 0; j < 0x10; j++) {
				input[j] ^= 66;
				input[j] += 0x30;
			}
		} catch (MyException1& e) {
			scanf("%20s", input);
			if (strlen(input) != 0x10)
				return 1;
		} catch (MyException3& e) {
			int res = 0;
			for (int j = 0; j < 0x10; j++) {
				res |= cipher[j] ^ input[j];
			}
			if (res == 0) {
				printf("Good!\n");
				return 0;
			} else {
				return 1;
			}
		}
	}
	return 0;
}
