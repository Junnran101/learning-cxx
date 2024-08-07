#include "../exercise.h"
#include <iostream>

// READ: Trivial type <https://learn.microsoft.com/zh-cn/cpp/cpp/trivial-standard-layout-and-pod-types?view=msvc-170>

struct FibonacciCache {
	unsigned long long cache[16];
	int cached;
};

// TODO: ʵ����ȷ�Ļ����Ż�쳲���������
static unsigned long long fibonacci(FibonacciCache &cache, int i) {
	cache.cache[0] = 0;
	cache.cache[1] = 1;
	cache.cached = 2;

	if (i < cache.cached) {
		return cache.cache[i];
	}

	for (int j = cache.cached; j <= i; ++j) {
		cache.cache[j] = cache.cache[j - 1] + cache.cache[j - 2];
	}

	return cache.cache[i];
}

int main(int argc, char **argv) {
	// TODO: ��ʼ������ṹ�壬ʹ������ȷ
	// NOTICE: C/C++ �У���ȡδ��ʼ���ı����������ṹ���������δ������Ϊ
	// READ: ��ʼ���ĸ���д�� <https://zh.cppreference.com/w/cpp/language/initialization>
	FibonacciCache fib;
	ASSERT(fibonacci(fib, 10) == 55, "fibonacci(10) should be 55");
	std::cout << "fibonacci(10) = " << fibonacci(fib, 10) << std::endl;
	return 0;
}
