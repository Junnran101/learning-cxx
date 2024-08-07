#include "../exercise.h"

// READ: ���ƹ��캯�� <https://zh.cppreference.com/w/cpp/language/copy_constructor>

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

		// TODO: ʵ�ָ��ƹ�����
		DynFibonacci(DynFibonacci const &other) = delete;

		// TODO: ʵ�����������ͷŻ���ռ�
		~DynFibonacci() {
			delete[] cache;
		}

		// TODO: ʵ����ȷ�Ļ����Ż�쳲���������
		size_t get(int i) {
			if (i < cached) {
				return cache[i];
			}

			for (int j = cached; j <= i && j < capacity; ++j) {
				cache[j] = cache[j - 1] + cache[j - 2];
			}
			cached = std::min(i + 1, capacity);

			return cache[i];
		}

		// NOTICE: ��Ҫ�޸��������
		// NOTICE: ������ͬ����Ҳ��ͬ���� const ���β�ͬ�ķ�����һ�����ط���������ͬʱ����
		//         �����ϣ������������� this �����ĺ���
		//         const ���������� this �ϣ��������ʵ���ϲ�����ͬ
		size_t get(int i) const {
			if (i <= cached) {
				return cache[i];
			}
			ASSERT(false, "i out of range");
		}
};

int main(int argc, char **argv) {
	DynFibonacci fib(12);
	ASSERT(fib.get(10) == 55, "fibonacci(10) should be 55");
	DynFibonacci const &fib_ref = fib;
	ASSERT(fib_ref.get(10) == fib.get(10), "Object cloned");
	return 0;
}
