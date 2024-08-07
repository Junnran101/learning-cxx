#include "../exercise.h"
#include <string>

// READ: �ַ��� <https://zh.cppreference.com/w/cpp/string/basic_string>

int main(int argc, char **argv) {
	// READ: �ַ��������� <https://zh.cppreference.com/w/cpp/string/basic_string/operator%22%22s>
	using namespace std::string_literals;
	auto hello = "Hello"s;
	auto world = "world";
	// READ: `decltype` ���ʽ <https://zh.cppreference.com/w/cpp/language/decltype>
	// READ: `std::is_same_v` Ԫ����б� <https://zh.cppreference.com/w/cpp/types/is_same>
	ASSERT((std::is_same_v<decltype(hello), std::string>), "Fill in the missing type.");
	ASSERT((std::is_same_v<decltype(world), const char *>), "Fill in the missing type.");
	// TODO: �� `?` �滻Ϊ��ȷ���ַ���
	ASSERT(hello + ", " + world + '!' == "Hello, world!", "Fill in the missing string.");
	return 0;
}
