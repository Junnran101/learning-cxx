#include "../exercise.h"

#include <iostream>
#include <array>

constexpr unsigned long long fibonacci(int i) {
	std::array<unsigned long long, 91> fib = {0};  // 91 �Ա�洢 fibonacci(90)
	fib[1] = 1;
	for (int j = 2; j <= i; ++j) {
		fib[j] = fib[j - 1] + fib[j - 2];
	}
	return fib[i];
}

int main(int argc, char **argv) {
	constexpr auto FIB20 = fibonacci(20);
	ASSERT(FIB20 == 6765, "fibonacci(20) should be 6765");
	std::cout << "fibonacci(20) = " << FIB20 << std::endl;

	// TODO: �۲������Ϣ���޸�һ����ʹ�����������
	// PS: �������У����ǲ�һ��������������
	constexpr auto ANS_N = 90;
	constexpr auto ANS = fibonacci(ANS_N);
	std::cout << "fibonacci(" << ANS_N << ") = " << ANS << std::endl;

	return 0;
}
