#include "../exercise.h"

// READ: <https://stackoverflow.com/questions/156767/whats-the-difference-between-an-argument-and-a-parameter>
// THINK: ����������Щ���ݷ�ʽ�����ѡ�񴫵ݷ�ʽ��

void func(int);

// TODO: Ϊ���� ASSERT ��д��ȷ��ֵ
int main(int argc, char **argv) {
	auto arg = 99;
	ASSERT(arg == 99, "arg should be 99");
	std::cout << "befor func call: " << arg << std::endl;
	func(arg);
	ASSERT(arg == 99, "arg should be 99");
	std::cout << "after func call: " << arg << std::endl;
	return 0;
}

// func���������ܵ���arg��ֵ��Ϊ����=>argֵ��һ����������param
// func�ڣ��Ըá�������param���κβ�����������Ӱ��arc

// TODO: Ϊ���� ASSERT ��д��ȷ��ֵ
void func(int param) {
	ASSERT(param == 99, "param should be 99");
	std::cout << "befor add: " << param << std::endl;
	param += 1;
	ASSERT(param == 100, "param should be 100");
	std::cout << "after add: " << param << std::endl;
}
