#include "../exercise.h"
#include <vector>

// READ: std::vector <https://zh.cppreference.com/w/cpp/container/vector_bool>
// READ: 模板特化 <https://zh.cppreference.com/w/cpp/language/template_specialization>

// TODO: 将下列 `?` 替换为正确的代码
int main(int argc, char **argv) {
	std::vector<bool> vec(100, true); // Initialize with 100 elements, all set to true
	ASSERT(vec[0], "Make this assertion pass.");
	ASSERT(vec[99], "Make this assertion pass.");
	ASSERT(vec.size() == 100, "Make this assertion pass.");
	ASSERT(sizeof(vec) == sizeof(std::vector<bool>), "Fill in the correct value."); // Size of the vector object itself

	{
		vec[20] = false;
		ASSERT(!vec[20], "Fill in `vec[20]` or `!vec[20]`."); // vec[20] should be false
	}

	{
		vec.push_back(false);
		ASSERT(vec.size() == 101, "Fill in the correct value."); // Size should be 101 after push_back
		ASSERT(!vec[100], "Fill in `vec[100]` or `!vec[100]`."); // Last element should be false
	}

	{
		auto ref = vec[30];
		ASSERT(ref, "Fill in `ref` or `!ref`"); // ref should be true initially
		ref = false;
		ASSERT(!ref, "Fill in `ref` or `!ref`"); // ref should be false after assignment
		ASSERT(!vec[30], "Fill in `vec[30]` or `!vec[30]`."); // vec[30] should be false after modification via ref
	}
	return 0;
}
