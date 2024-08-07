#include "../exercise.h"

// C++ �У�`class` �� `struct` ֮���**Ψһ����**��
// `class` Ĭ�Ϸ��ʿ��Ʒ��� `private`��
// `struct` Ĭ�Ϸ��ʿ��Ʒ��� `public`��
// READ: ����˵���� <https://zh.cppreference.com/w/cpp/language/access>

// ��� class �е��ֶα� private ���Σ�ֻ���� class �ڲ����ʡ�
// ��˱����ṩ����������ʼ���ֶΡ�
// READ: ������ <https://zh.cppreference.com/w/cpp/language/constructor>
class Fibonacci {
		size_t cache[16];
		int cached;

	public:
		// TODO: ʵ�ֹ�����
		// Fibonacci()
		Fibonacci() {
			cache[0] = 0;
			cache[1] = 1;
			cached = 2;
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
	// ��������ӵ���޲ι�����������ʱ��ֱ�ӵ��á�
	// ���д��������δ������Ϊ�ˡ�
	Fibonacci fib;
	ASSERT(fib.get(10) == 55, "fibonacci(10) should be 55");
	std::cout << "fibonacci(10) = " << fib.get(10) << std::endl;
	return 0;
}
