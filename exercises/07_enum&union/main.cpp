#include "../exercise.h"

// READ: ö������ <https://zh.cppreference.com/w/cpp/language/enum>

// `enum` �� C �ļ������ͣ����������Ӧ���͵ĳ�����
// �� `enum` �ж����ʶ���ȼ��ڶ��� constexpr ������
// ��Щ��ʶ������Ҫǰ׺������ֱ�����á�
// ��� `enum` �������Ⱦ�����ռ䡣
enum ColorEnum : unsigned char {
	COLOR_RED = 31,
	COLOR_GREEN,
	COLOR_YELLOW,
	COLOR_BLUE,
};

// ��������ö������ C++ ��������Ͱ�ȫö�١�
// ���ڲ���ʶ����Ҫ��ǰ׺���ã��� `Color::Red`��
// ������ö���Ϳ��Ա��������ռ���Ⱦ�����ṩ���Ͱ�ȫ��֤��
enum class Color : int {
	Red = COLOR_RED,
	Green,
	Yellow,
	Blue,
};

ColorEnum convert_by_pun(Color c) {
	// READ: <https://zh.cppreference.com/w/cpp/language/union>
	// `union` ��ʾ��ͬһ�ڴ�λ�ô洢�Ĳ�ͬ���͵�ֵ��
	// �䳣���÷���ʵ������˫��ת��������һ�����͵�ֵת��Ϊ��һ���޹����͵�ֵ��
	// ������д��ʵ���Ͻ��� C ���������壬�� C++ ����δ������Ϊ��
	// ���ǱȽ��ټ��� C++ ���� C ���ּ��ݵ����ԡ�
	// READ: ����˫�� <https://tttapa.github.io/Pages/Programming/Cpp/Practices/type-punning.html>
	union TypePun {
		ColorEnum e;
		Color c;
	};

	TypePun pun;
	// TODO: ��ȫ����˫��ת��
	pun.c = c;
	return pun.e;
}

int main(int argc, char **argv) {
	ASSERT(convert_by_pun(Color::Red) == COLOR_RED, "Type punning conversion");
	ASSERT(convert_by_pun(Color::Green) == COLOR_GREEN, "Type punning conversion");
	ASSERT(convert_by_pun(Color::Yellow) == COLOR_YELLOW, "Type punning conversion");
	ASSERT(convert_by_pun(Color::Blue) == COLOR_BLUE, "Type punning conversion");
	return 0;
}
