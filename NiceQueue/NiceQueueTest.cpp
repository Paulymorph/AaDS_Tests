#include "../src/NiceQueue.h"

#include "gtest/gtest.h"

TEST(NiceQueueTest, simple1) {
    NiceQueue<int> q(3);
}

TEST(NiceQueueTest, enqSize1) {
    NiceQueue<int> q(3);
    EXPECT_EQ(q.size(), 0);

    q.enq(1);
    EXPECT_EQ(q.size(), 1);

    q.enq(2);
    EXPECT_EQ(q.size(), 2);

    q.enq(3);
    EXPECT_EQ(q.size(), 3);

    EXPECT_THROW(q.enq(0), out_of_range);
}

TEST(NiceQueueTest, deq1) {
    NiceQueue<int> q(3);

    q.enq(1);
    q.enq(2);
    q.enq(3);

    EXPECT_EQ(q.deq(), 1);
    EXPECT_EQ(q.size(), 2);

    EXPECT_EQ(q.deq(), 2);
    EXPECT_EQ(q.size(), 1);

    EXPECT_EQ(q.deq(), 3);
    EXPECT_EQ(q.size(), 0);

    EXPECT_THROW(q.deq(), out_of_range);

    q.enq(-1);
    q.enq(-2);
    EXPECT_EQ(q.deq(), -1);
    
    q.enq(-3);
    EXPECT_EQ(q.deq(), -2);

    EXPECT_EQ(q.deq(), -3);
}

TEST(NiceQueueTest, minimum1) {
    NiceQueue<int> q(3);

    q.enq(3);
    EXPECT_EQ(q.getMinimum(), 3);

    q.enq(1);
    EXPECT_EQ(q.getMinimum(), 1);

    q.enq(2);
    EXPECT_EQ(q.getMinimum(), 1);

    q.deq();
    EXPECT_EQ(q.getMinimum(), 1);

    q.deq();
    EXPECT_EQ(q.getMinimum(), 2);
}