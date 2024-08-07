#include "../exercise.h"
#include <cmath>

enum class DataType {
	Float,
	Double,
};

/// @brief Tagged union 即标签化联合体，是联合体的一种常见应用。
///        Rust enum 在实现上就是标签化联合体。
struct TaggedUnion {
	DataType type;
	union {
		float f;
		double d;
	};

	// Default constructor
	TaggedUnion() : type(DataType::Float), f(0.0f) {}

	// Constructor for float
	TaggedUnion(DataType t, float val) : type(t), f(val) {}

	// Constructor for double
	TaggedUnion(DataType t, double val) : type(t), d(val) {}
};

// Template function to calculate sigmoid
template<typename T>
T sigmoid(T x) {
	return 1 / (1 + std::exp(-x));
}

TaggedUnion sigmoid_dyn(TaggedUnion x) {
	TaggedUnion ans;
	ans.type = x.type;  // Set type first
	switch (x.type) {
		case DataType::Float:
			ans.f = sigmoid(x.f);
			break;
		case DataType::Double:
			ans.d = sigmoid(x.d);
			break;
	}
	return ans;
}

// ---- 不要修改以下代码 ----
int main(int argc, char **argv) {
	TaggedUnion xf{DataType::Float, 5.f};
	auto yf = sigmoid_dyn(xf);
	ASSERT(yf.type == DataType::Float, "type mismatch");
	ASSERT(yf.f == 1 / (1 + std::exp(-5.f)), "sigmoid float");

	TaggedUnion xd{DataType::Double, 5.0};
	auto yd = sigmoid_dyn(xd);
	ASSERT(yd.type == DataType::Double, "type mismatch");
	ASSERT(yd.d == 1 / (1 + std::exp(-5.0)), "sigmoid double");
	return 0;
}
