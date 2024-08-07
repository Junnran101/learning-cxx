#include "../exercise.h"

// READ: ������ <https://zh.cppreference.com/w/cpp/language/derived_class>

struct X {
	int x;

	X(int x_) : x(x_) {
		std::cout << "X(" << x << ')' << std::endl;
	}
	X(X const &other) : x(other.x) {
		std::cout << "X(X const &) : x(" << x << ')' << std::endl;
	}
	~X() {
		std::cout << "~X(" << x << ')' << std::endl;
	}
};

struct A {
	int a;

	A(int a_) : a(a_) {
		std::cout << "A(" << a << ')' << std::endl;
	}
	A(A const &other) : A(other.a) {
		std::cout << "A(A const &) : a(" << a << ')' << std::endl;
	}
	~A() {
		std::cout << "~A(" << a << ')' << std::endl;
	}
};

struct B : public A {
	X x;

	B(int b) : A(1), x(b) {
		std::cout << "B(" << a << ", X(" << x.x << "))" << std::endl;
	}
	B(B const &other) : A(other.a), x(other.x) {
		std::cout << "B(B const &) : A(" << a << "), x(X(" << x.x << "))" << std::endl;
	}
	~B() {
		std::cout << "~B(" << a << ", X(" << x.x << "))" << std::endl;
	}
};

int main(int argc, char **argv) {
	X x = X(1);
	A a = A(2);
	B b = B(3);

	// TODO: ��ȫ�������͵Ĵ�С
	static_assert(sizeof(X) == sizeof(int), "There is an int in X");
	static_assert(sizeof(A) == sizeof(int), "There is an int in A");
	static_assert(sizeof(B) == sizeof(A) + sizeof(X), "B is an A with an X");

	std::cout << std::endl
	          << "-------------------------" << std::endl
	          << std::endl;

	// ���ǲ����ܵģ�A �޷��ṩ B ���ӵĳ�Ա������ֵ
	// B ba = A(4);

	// ��Ҳ�ǲ����ܵģ���Ϊ A �� B ��һ���֣��ͺ��񲻿��԰�����??�����Ž��ڲ��
	A ab = B(5);// Ȼ�����������Ա�������У�
	// THINK: �۲��ӡ������Ϣ���Ʋ�Ѵ���Ž�����ּ�����
	// THINK: �����Ĵ����ǡ���ȫ������
	// NOTICE: ��ʵ�����в�̫���ܳ��������Ĵ���

	return 0;
}
