#include <gtest/gtest.h>
#include <cpps/Nullable.h>

using namespace cpps;

TEST(NullableTest, CheckIsNull) {
	Nullor<int> obj(25);
	Nullor<int> null_obj;

	EXPECT_FALSE(obj.IsNull());
	EXPECT_TRUE(null_obj.IsNull());
}

TEST(NullableTest, resolve) {
	Nullor<int> empty;
	Nullor<int> full(23);

	int empty_value = (empty) ? empty.Resolve() : -1;
	int full_value = (full) ? full.Resolve() : -1;

	// Resolve moves the data from the Nullor shell into a real dest.
	// Resolving from null returns a null constructed object.
	EXPECT_EQ(empty.Resolve(), 0);
	EXPECT_EQ(empty_value, -1);
	EXPECT_EQ(full_value, 23);
}

// need to write a moveresolve test.