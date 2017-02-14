#include "../src/NiceStack.h"

#include "gtest/gtest.h"

TEST(NiceStackTest, simple1) {
    NiceStack<int> stack(3);
}

TEST(NiceStackTest, pushSize1) {
    NiceStack<int> stack(3);
    EXPECT_EQ(stack.size(), 0);

    stack.push(1);
    EXPECT_EQ(stack.size(), 1);

    stack.push(2);
    EXPECT_EQ(stack.size(), 2);

    stack.push(3);
    EXPECT_EQ(stack.size(), 3);

    EXPECT_THROW(stack.push(0), out_of_range);
}

TEST(NiceStackTest, pushPopSize1) {
    NiceStack<int> stack(3);

    stack.push(1);
    stack.push(2);
    stack.push(3);

    EXPECT_EQ(stack.pop(), 3);
    EXPECT_EQ(stack.size(), 2);

    EXPECT_EQ(stack.pop(), 2);
    EXPECT_EQ(stack.size(), 1);

    EXPECT_EQ(stack.pop(), 1);
    EXPECT_EQ(stack.size(), 0);

    EXPECT_THROW(stack.pop(), out_of_range);

    stack.push(-1);
    stack.push(-2);
    stack.push(-3);

    EXPECT_EQ(stack.pop(), -3);
    EXPECT_EQ(stack.pop(), -2);
    EXPECT_EQ(stack.pop(), -1);
}

TEST(NiceStackTest, min1) {
    NiceStack<int> stack(3);

    EXPECT_THROW(stack.getMinimum(), out_of_range);

    stack.push(1);
    EXPECT_EQ(stack.getMinimum(), 1);

    stack.push(2);
    EXPECT_EQ(stack.getMinimum(), 1);

    stack.push(3);
    EXPECT_EQ(stack.getMinimum(), 1);

    stack.pop();
    EXPECT_EQ(stack.getMinimum(), 1);

    stack.pop();
    EXPECT_EQ(stack.getMinimum(), 1);

    stack.pop();

    stack.push(2);
    EXPECT_EQ(stack.getMinimum(), 2);

    stack.push(3);
    EXPECT_EQ(stack.getMinimum(), 2);

    stack.push(1);
    EXPECT_EQ(stack.getMinimum(), 1);

    stack.pop();
    EXPECT_EQ(stack.getMinimum(), 2);

    stack.pop();
    EXPECT_EQ(stack.getMinimum(), 2);
}