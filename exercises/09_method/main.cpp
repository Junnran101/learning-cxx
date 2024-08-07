#include "../exercise.h"

struct Fibonacci {
	unsigned long long cache[128];
	int cached;

	// TODO: ʵ����ȷ�Ļ����Ż�쳲���������
	unsigned long long get(int i) {

		if (i < cached) {
			return cache[i];
		}

		for (int j = cached; j <= i; ++j) {
			cache[j] = cache[j - 1] + cache[j - 2];
		}
		return cache[i];
	}
};

void init(Fibonacci &cache) {
	cache.cache[0] = 0;
	cache.cache[1] = 1;
	cache.cached = 2;
}

int main(int argc, char **argv) {
	// TODO: ��ʼ������ṹ�壬ʹ������ȷ
	Fibonacci fib;
	init(fib);
	ASSERT(fib.get(10) == 55, "fibonacci(10) should be 55");
	std::cout << "fibonacci(10) = " << fib.get(10) << std::endl;
	return 0;
}
