#include "../exercise.h"

// READ: �ƶ����캯�� <https://zh.cppreference.com/w/cpp/language/move_constructor>
// READ: �ƶ���ֵ <https://zh.cppreference.com/w/cpp/language/move_assignment>
// READ: ��������� <https://zh.cppreference.com/w/cpp/language/operators>

class DynFibonacci {
		size_t *cache;
		int capacity;
		int cached;

	public:
		// TODO: ʵ�ֶ�̬���������Ĺ�����
		DynFibonacci(int capacity): cache(new size_t[capacity]), capacity(capacity), cached(2) {
			cache[0] = 0;
			cache[1] = 1;
		}

		// TODO: ʵ���ƶ�������
		DynFibonacci(DynFibonacci &&other) noexcept : cache(other.cache), capacity(other.capacity), cached(other.cached) {
			other.cache = nullptr;
		}

		// TODO: ʵ���ƶ���ֵ
		// NOTICE: ? ע���ƶ����������� ?
		DynFibonacci &operator=(DynFibonacci &&other) noexcept {
			if (this != &other) {
				delete[] cache;

				cache = other.cache;
				capacity = other.capacity;
				cached = other.cached;

				other.cache = nullptr;
			}
			return *this;
		}

		// TODO: ʵ�����������ͷŻ���ռ�
		~DynFibonacci() {
			delete[] cache;
		}

		// TODO: ʵ����ȷ�Ļ����Ż�쳲���������
		size_t &operator[](int i) {
			if (i > cached) {
				for (int j = cached; j <= i && j < capacity; ++j) {
					cache[j] = cache[j - 1] + cache[j - 2];
				}
				cached = std::min(i + 1, capacity);
			}
			return cache[i];
		}

		size_t operator[](int i) const {
			if (i >= cached) {
				// Provide an error message or handle out-of-range access
				ASSERT(false, "Index out of range for const access");
			}
			return cache[i];
		}

		// NOTICE: ��Ҫ�޸��������
		bool is_alive() const {
			return cache != nullptr;
		}
};

int main(int argc, char **argv) {
	DynFibonacci fib(12);
	ASSERT(fib[10] == 55, "fibonacci(10) should be 55");

	DynFibonacci const fib_ = std::move(fib);
	ASSERT(!fib.is_alive(), "Object moved");
	ASSERT(fib_[10] == 55, "fibonacci(10) should be 55");

	DynFibonacci fib0(6);
	DynFibonacci fib1(12);

	fib0 = std::move(fib1);
	fib0 = std::move(fib0);
	ASSERT(fib0[10] == 55, "fibonacci(10) should be 55");

	return 0;
}
