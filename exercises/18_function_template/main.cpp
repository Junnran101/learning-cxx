#include "../exercise.h"
#include <cmath>

// READ: ����ģ�� <https://zh.cppreference.com/w/cpp/language/function_template>
// TODO: ���������ģ�廯
template<typename T>
T plus(T a, T b) {
	return a + b;
}

template<typename T>
bool areAlmostEqual(T a, T b, T epsilon = static_cast<T>(1e-10)) {
	return std::fabs(a - b) < epsilon;
}

template<typename T>
typename std::enable_if<std::is_floating_point<T>::value, bool>::type
ams(T a, T b, T epsilon = static_cast<T>(1e-10)) {
	return std::fabs(a - b) < epsilon;
}

int main(int argc, char **argv) {
	float f_a = plus(1.25f, 2.5f);
	double f_b = plus(1.25, 2.5);
	ASSERT(plus(1, 2) == 3, "Plus two int");
	ASSERT(plus(1u, 2u) == 3u, "Plus two unsigned int");

	// THINK: ��������ʱ�����ж� ==����ʱ�����жϲ�ֵ��
	ASSERT(areAlmostEqual(f_a, 3.75f), "Plus two float");
	ASSERT(areAlmostEqual(f_b, 3.75), "Plus two double");
	// TODO: �޸��ж�����ʹ����ͨ��
	ASSERT(ams(plus(0.1, 0.2), 0.3), "How to make this pass?");

	return 0;
}
