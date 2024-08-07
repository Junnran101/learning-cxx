#include "../exercise.h"

// READ: �������� <https://zh.cppreference.com/w/cpp/language/destructor>

/// @brief ���⻺��������쳲��������͡�
/// @details �����ڹ���ʱ���뻺�������������Ҫ��̬���仺��ռ䡣
class DynFibonacci {
		size_t *cache;
		int capacity;
		int cached;

	public:
		// TODO: ʵ�ֶ�̬���������Ĺ�����
		DynFibonacci(int capacity): capacity(capacity), cached(2) {
			cache = new size_t[16];
			cache[0] = 0;
			cache[1] = 1;
		}

		// TODO: ʵ�����������ͷŻ���ռ�
		~DynFibonacci() {
			delete[] cache;
		}

		// TODO: ʵ����ȷ�Ļ����Ż�쳲���������
		size_t get(int i) {
			if (i < cached) {
				return cache[i];
			}

			for (int j = cached; j <= i && j < 16; ++j) {
				cache[j] = cache[j - 1] + cache[j - 2];
			}
			cached = std::min(i + 1, 16);

			return cache[i];
		}
};

int main(int argc, char **argv) {
	DynFibonacci fib(12);
	ASSERT(fib.get(10) == 55, "fibonacci(10) should be 55");
	std::cout << "fibonacci(10) = " << fib.get(10) << std::endl;
	return 0;
}
