#include "../exercise.h"

#include <iostream>
#include <array>

constexpr unsigned long long fibonacci(int i) {
	std::array<unsigned long long, 91> fib = {0};  // 91 以便存储 fibonacci(90)
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

	// TODO: 观察错误信息，修改一处，使代码编译运行
	// PS: 编译运行，但是不一定能算出结果……
	constexpr auto ANS_N = 90;
	constexpr auto ANS = fibonacci(ANS_N);
	std::cout << "fibonacci(" << ANS_N << ") = " << ANS << std::endl;

	return 0;
}
