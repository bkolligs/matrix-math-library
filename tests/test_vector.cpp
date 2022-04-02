#include "gtest/gtest.h"
#include "vector.h"

TEST(VectorTest, TestAddition) {
    mm::Vector3 v1{1.0, 0.0, 0.0};
    mm::Vector3 v2{0.0, 2.0, 0.0};
    mm::Vector3 compare{1.0, 2.0, 0.0};
    ASSERT_TRUE(mm::isApprox(v1 + v2, compare));
    v1      = {-5.0, 1.0, 0.5};
    v2      = {0.0, -2.0, 0.75};
    compare = {-5.0, -1.0, 1.25};
    ASSERT_TRUE(mm::isApprox(v1 + v2, compare));

    v1      = {0.0, 0.0, 0.0};
    compare = {5.0, 5.0, 5.0};
    ASSERT_TRUE(mm::isApprox(5.0 + v1, compare));
}

TEST(VectorTest, TestSubtraction) {
    mm::Vector3 v1{1.0, 0.0, 0.0};
    mm::Vector3 v2{0.0, 2.0, 0.0};
    mm::Vector3 compare{1.0, -2.0, 0.0};
    ASSERT_TRUE(mm::isApprox(v1 - v2, compare));
    v1      = {-5.0, 1.0, 0.5};
    v2      = {0.0, -2.0, 0.75};
    compare = {-5.0, 3.0, -0.25};
    ASSERT_TRUE(mm::isApprox(v1 - v2, compare));

    v1      = {0.0, 0.0, 0.0};
    compare = {5.0, 5.0, 5.0};
    ASSERT_TRUE(mm::isApprox(5.0 - v1, compare));
}

TEST(VectorTest, TestDot) {
    mm::Vector3 v1{0.0, 1.0, 3.0};
    mm::Vector3 v2{1.0, 2.0, 2.5};
    float test    = v1 * v2;
    float compare = 0.0 + 2.0 + 7.5;
    ASSERT_DOUBLE_EQ(test, compare);
}

TEST(VectorTest, TestCross) {
    mm::Vector3 v1{1.2, 3.8, 9.1};
    mm::Vector3 v2{1.0, 0.0, 2.3};
    mm::Vector3 test = mm::cross(v1, v2);
    mm::Vector3 compare{8.74, 6.34, -3.8};
    ASSERT_TRUE(mm::isApprox(test, compare));
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
