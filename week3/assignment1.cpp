#include <iostream>

int code(){
	return 0;
}

int data = 2; // 초기화한 전역변수. 따라서 데이터
int bss; // 초기화하지 않은 전역변수. 따라서 bss


int main(){
	static const int rodata = 2;
	int *heap = new int[2];
	int stack = 3; // 함수의 지역변수


	std::cout << "code\t" << (void*)code << std::endl;
	std::cout << "rodata\t" << (void*)&rodata << std::endl;
	std::cout << "data\t" << &data << std::endl;
	std::cout << "bss\t" << &bss << std::endl;
	std::cout << "heap\t" << heap << std::endl;
	std::cout << "stack\t" << &stack << std::endl;
	
	return 0;
}

