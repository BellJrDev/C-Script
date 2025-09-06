#include <gtest/gtest.h>
#include <cpps/Nullable.h>

using namespace cpps;


TEST(NullableTest, default_construct) {
	Nullor<char> obj;

	EXPECT_TRUE(obj.IsNull());
}

TEST(NullableTest, init_construct) {
	Nullor<int> obj(25);

	EXPECT_FALSE(obj.IsNull());
}

TEST(NullableTest, copy_construct) {
	Nullor<int> first(55);
	Nullor<int> second(first);

	int value = (second) ? *(second.Content()) : 0;
	EXPECT_FALSE(second.IsNull());
	EXPECT_EQ(value, 55);
}

TEST(NullableTest, move_construct)
{
	// This is basically the same test concept as the copy constructor test.
	// But it's a more low-level apporach, since this method moves a raw buffer

	alignas(Nullor<int>) unsigned char storage[sizeof(Nullor<int>)];
	Nullor<int>* obj = new(storage) Nullor<int>(42);

	alignas(Nullor<int>) unsigned char storage2[sizeof(Nullor<int>)];
	Nullor<int>* movedTo = new(storage2) Nullor<int>(std::move(*obj));
	int value = movedTo->Resolve();

	// Verify memory is valid and object behaves correctly
	EXPECT_TRUE(movedTo->IsNull());
	EXPECT_TRUE(obj->IsNull());
	EXPECT_EQ(value, 42);

	// Cleanup
	obj->~Nullor();
	movedTo->~Nullor();
}

TEST(NullableTest, value_move_construct)
{
	std::string source = "Hello";
	Nullor<std::string> movedIn(std::move(source));
	std::string value = (movedIn) ? *(movedIn.Content()) : "";

	EXPECT_FALSE(movedIn.IsNull());
	EXPECT_EQ(value, "Hello");

	// This is a move -- not a copy.
	EXPECT_TRUE(source.empty());
}