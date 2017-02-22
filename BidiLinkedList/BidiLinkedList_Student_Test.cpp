//
// Created by Paul Danilin on 20/02/2017.
//

#include <gtest/gtest.h>

#include "../src/BidiLinkedList.h"

/** \brief Type alias for a list of integers */
typedef BidiLinkedList<int> IntBidiList;
typedef IntBidiList::Node IntBidiListNode;

TEST(StudentBidiListInt, lastNode1) {
    IntBidiList list;
    EXPECT_EQ(list.getLastNode(), nullptr);
}

TEST(StudentBidiListInt, insertNodesAfter1) {
    IntBidiList list;
    list.appendEl(1);
    list.appendEl(2);
    list.appendEl(3);
    list.appendEl(4); // beg
    list.appendEl(5); // end

    BidiLinkedList<int>::Node* beg = list.getHeadNode();
    beg = beg->getNext()->getNext()->getNext();
    BidiLinkedList<int>::Node* end = beg->getNext();

    list.cutNodes(beg, end);


    IntBidiListNode* start = list.getHeadNode();
    EXPECT_EQ(start->getValue(), 1);
    EXPECT_EQ(start->getNext()->getValue(), 2);
    EXPECT_EQ(start->getNext()->getNext()->getValue(), 3);

    list.insertNodesAfter(nullptr, beg, end);
    start = list.getHeadNode();
    EXPECT_EQ(start->getValue(), 1);
    EXPECT_EQ(start->getNext()->getValue(), 2);
    EXPECT_EQ(start->getNext()->getNext()->getValue(), 3);
    EXPECT_EQ(start->getNext()->getNext()->getNext()->getValue(), 4);
    EXPECT_EQ(start->getNext()->getNext()->getNext()->getNext()->getValue(), 5);

    list.cutNodes(beg, end);
    start = list.getHeadNode();
    EXPECT_EQ(start->getValue(), 1);
    EXPECT_EQ(start->getNext()->getValue(), 2);
    EXPECT_EQ(start->getNext()->getNext()->getValue(), 3);

    list.insertNodesAfter(list.getLastNode(), beg, end);
    start = list.getHeadNode();
    EXPECT_EQ(start->getValue(), 1);
    EXPECT_EQ(start->getNext()->getValue(), 2);
    EXPECT_EQ(start->getNext()->getNext()->getValue(), 3);
    EXPECT_EQ(start->getNext()->getNext()->getNext()->getValue(), 4);
    EXPECT_EQ(start->getNext()->getNext()->getNext()->getNext()->getValue(), 5);

    list.cutNodes(beg, end);
    start = list.getHeadNode();
    EXPECT_EQ(start->getValue(), 1);
    EXPECT_EQ(start->getNext()->getValue(), 2);
    EXPECT_EQ(start->getNext()->getNext()->getValue(), 3);

    list.insertNodesAfter(list.getHeadNode()->getNext(), beg, end);
    start = list.getHeadNode();
    EXPECT_EQ(start->getValue(), 1);
    EXPECT_EQ(start->getNext()->getValue(), 2);
    EXPECT_EQ(start->getNext()->getNext()->getValue(), 4);
    EXPECT_EQ(start->getNext()->getNext()->getNext()->getValue(), 5);
    EXPECT_EQ(start->getNext()->getNext()->getNext()->getNext()->getValue(), 3);

    list.cutNodes(beg, end);
    start = list.getHeadNode();
    EXPECT_EQ(start->getValue(), 1);
    EXPECT_EQ(start->getNext()->getValue(), 2);
    EXPECT_EQ(start->getNext()->getNext()->getValue(), 3);

    list.insertNodesAfter(list.getHeadNode(), beg, end);
    start = list.getHeadNode();
    EXPECT_EQ(start->getValue(), 1);
    EXPECT_EQ(start->getNext()->getValue(), 4);
    EXPECT_EQ(start->getNext()->getNext()->getValue(), 5);
    EXPECT_EQ(start->getNext()->getNext()->getNext()->getValue(), 2);
    EXPECT_EQ(start->getNext()->getNext()->getNext()->getNext()->getValue(), 3);
}

TEST(StudentBidiListInt, clear1) {
    IntBidiList list;
    list.appendEl(1);
    list.appendEl(2);
    list.appendEl(3);

    list.clear();

    EXPECT_EQ(list.getSize(), 0);
    EXPECT_EQ(list.getHeadNode(), nullptr);
}