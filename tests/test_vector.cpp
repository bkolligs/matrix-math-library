#include "vector.h"
#include "gtest/gtest.h"

TEST(VectorTest, TestAddition){
	mm::Vector3 v1 {1.0, 0.0, 0.0};
	mm::Vector3 v2 {0.0, 2.0, 0.0};
	mm::Vector3 compare {1.0, 2.0, 0.0};
	ASSERT_TRUE(mm::isApprox(v1+v2, compare));
	v1 = {-5.0, 1.0, 0.5};
	v2 = {0.0, -2.0, 0.75};
	compare = {-5.0, -1.0, 1.25};
	ASSERT_TRUE(mm::isApprox(v1+v2, compare));

	v1 = {0.0, 0.0, 0.0};
	compare = {5.0, 5.0, 5.0};
	ASSERT_TRUE(mm::isApprox(5.0 + v1, compare));
}

TEST(VectorTest, TestSubtraction){
	mm::Vector3 v1 {1.0, 0.0, 0.0};
	mm::Vector3 v2 {0.0, 2.0, 0.0};
	mm::Vector3 compare {1.0, -2.0, 0.0};
	ASSERT_TRUE(mm::isApprox(v1-v2, compare));
	v1 = {-5.0, 1.0, 0.5};
	v2 = {0.0, -2.0, 0.75};
	compare = {-5.0, 3.0, -0.25};
	ASSERT_TRUE(mm::isApprox(v1-v2, compare));

	v1 = {0.0, 0.0, 0.0};
	compare = {5.0, 5.0, 5.0};
	ASSERT_TRUE(mm::isApprox(5.0 - v1, compare));
}

int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
