#include <gtest/gtest.h>
#include <cpps/Nullable.h>

using namespace cpps;

TEST(NullableTest, copyAssignment) {
	Nullor<int> left(42);
	Nullor<int> right;

	right = left;

	int right_value = (right) ? right.Resolve() : -1;

	// Original should be unchanged
	EXPECT_TRUE(right.IsNull());
	EXPECT_FALSE(left.IsNull());
	EXPECT_EQ(right_value, 42);
}

TEST(NullableTest, moveAssignment) {
	Nullor<int> older(77);
	Nullor<int> newer;

	newer = std::move(older);

	int value = newer.Resolve();

	// Older object is now null
	EXPECT_TRUE(older.IsNull());
	EXPECT_EQ(value, 77);
}