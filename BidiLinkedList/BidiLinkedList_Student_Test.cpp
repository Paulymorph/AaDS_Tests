//
// Created by Paul Danilin on 20/02/2017.
//

#include <gtest/gtest.h>

#include "../src/BidiLinkedList.h"

/** \brief Type alias for a list of integers */
typedef BidiLinkedList<int> IntBidiList;
typedef IntBidiList::Node IntBidiListNode;

// Paul Danilin
TEST(StudentBidiListInt, lastNode1) {
    IntBidiList list;
    EXPECT_EQ(list.getLastNode(), nullptr);
}

// Paul Danilin
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

// Paul Danilin
TEST(StudentBidiListInt, insertNodeBefore1) {
    IntBidiList list;
    list.appendEl(1);
    list.appendEl(2);
    list.appendEl(3);
    list.appendEl(4); // beg
    list.appendEl(5);

    BidiLinkedList<int>::Node* beg = list.getHeadNode();
    beg = beg->getNext()->getNext()->getNext();

    beg = list.cutNode(beg);

    IntBidiListNode* start = list.getHeadNode();
    EXPECT_EQ(start->getValue(), 1);
    EXPECT_EQ(start->getNext()->getValue(), 2);
    EXPECT_EQ(start->getNext()->getNext()->getValue(), 3);
    EXPECT_EQ(start->getNext()->getNext()->getNext()->getValue(), 5);

    list.insertNodeBefore(nullptr, beg);
    start = list.getHeadNode();
    EXPECT_EQ(start->getValue(), 4);
    EXPECT_EQ(start->getNext()->getValue(), 1);
    EXPECT_EQ(start->getNext()->getNext()->getValue(), 2);
    EXPECT_EQ(start->getNext()->getNext()->getNext()->getValue(), 3);
    EXPECT_EQ(start->getNext()->getNext()->getNext()->getNext()->getValue(), 5);

    beg = list.cutNode(beg);
    start = list.getHeadNode();
    EXPECT_EQ(start->getValue(), 1);
    EXPECT_EQ(start->getNext()->getValue(), 2);
    EXPECT_EQ(start->getNext()->getNext()->getValue(), 3);
    EXPECT_EQ(start->getNext()->getNext()->getNext()->getValue(), 5);

    list.insertNodeBefore(list.getLastNode(), beg);
    start = list.getHeadNode();
    EXPECT_EQ(start->getValue(), 1);
    EXPECT_EQ(start->getNext()->getValue(), 2);
    EXPECT_EQ(start->getNext()->getNext()->getValue(), 3);
    EXPECT_EQ(start->getNext()->getNext()->getNext()->getValue(), 4);
    EXPECT_EQ(start->getNext()->getNext()->getNext()->getNext()->getValue(), 5);

    beg = list.cutNode(beg);
    start = list.getHeadNode();
    EXPECT_EQ(start->getValue(), 1);
    EXPECT_EQ(start->getNext()->getValue(), 2);
    EXPECT_EQ(start->getNext()->getNext()->getValue(), 3);
    EXPECT_EQ(start->getNext()->getNext()->getNext()->getValue(), 5);

    list.insertNodeBefore(list.getHeadNode()->getNext(), beg);
    start = list.getHeadNode();
    EXPECT_EQ(start->getValue(), 1);
    EXPECT_EQ(start->getNext()->getValue(), 4);
    EXPECT_EQ(start->getNext()->getNext()->getValue(), 2);
    EXPECT_EQ(start->getNext()->getNext()->getNext()->getValue(), 3);
    EXPECT_EQ(start->getNext()->getNext()->getNext()->getNext()->getValue(), 5);

    beg = list.cutNode(beg);
    start = list.getHeadNode();
    EXPECT_EQ(start->getValue(), 1);
    EXPECT_EQ(start->getNext()->getValue(), 2);
    EXPECT_EQ(start->getNext()->getNext()->getValue(), 3);
    EXPECT_EQ(start->getNext()->getNext()->getNext()->getValue(), 5);

    list.insertNodeBefore(list.getHeadNode(), beg);
    start = list.getHeadNode();
    EXPECT_EQ(start->getValue(), 4);
    EXPECT_EQ(start->getNext()->getValue(), 1);
    EXPECT_EQ(start->getNext()->getNext()->getValue(), 2);
    EXPECT_EQ(start->getNext()->getNext()->getNext()->getValue(), 3);
    EXPECT_EQ(start->getNext()->getNext()->getNext()->getNext()->getValue(), 5);
}

// Paul Danilin
TEST(StudentBidiListInt, insertNodesBefore1) {
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

    list.insertNodesBefore(nullptr, beg, end);
    start = list.getHeadNode();
    EXPECT_EQ(start->getValue(), 4);
    EXPECT_EQ(start->getNext()->getValue(), 5);
    EXPECT_EQ(start->getNext()->getNext()->getValue(), 1);
    EXPECT_EQ(start->getNext()->getNext()->getNext()->getValue(), 2);
    EXPECT_EQ(start->getNext()->getNext()->getNext()->getNext()->getValue(), 3);

    list.cutNodes(beg, end);
    start = list.getHeadNode();
    EXPECT_EQ(start->getValue(), 1);
    EXPECT_EQ(start->getNext()->getValue(), 2);
    EXPECT_EQ(start->getNext()->getNext()->getValue(), 3);

    list.insertNodesBefore(list.getLastNode(), beg, end);
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

    list.insertNodesBefore(list.getHeadNode()->getNext(), beg, end);
    start = list.getHeadNode();
    EXPECT_EQ(start->getValue(), 1);
    EXPECT_EQ(start->getNext()->getValue(), 4);
    EXPECT_EQ(start->getNext()->getNext()->getValue(), 5);
    EXPECT_EQ(start->getNext()->getNext()->getNext()->getValue(), 2);
    EXPECT_EQ(start->getNext()->getNext()->getNext()->getNext()->getValue(), 3);

    list.cutNodes(beg, end);
    start = list.getHeadNode();
    EXPECT_EQ(start->getValue(), 1);
    EXPECT_EQ(start->getNext()->getValue(), 2);
    EXPECT_EQ(start->getNext()->getNext()->getValue(), 3);

    list.insertNodesBefore(list.getHeadNode(), beg, end);
    start = list.getHeadNode();
    EXPECT_EQ(start->getValue(), 4);
    EXPECT_EQ(start->getNext()->getValue(), 5);
    EXPECT_EQ(start->getNext()->getNext()->getValue(), 1);
    EXPECT_EQ(start->getNext()->getNext()->getNext()->getValue(), 2);
    EXPECT_EQ(start->getNext()->getNext()->getNext()->getNext()->getValue(), 3);
}

// Paul Danilin
TEST(StudentBidiListInt, clear1) {
    IntBidiList list;
    list.appendEl(1);
    list.appendEl(2);
    list.appendEl(3);

    list.clear();

    EXPECT_EQ(list.getSize(), 0);
    EXPECT_EQ(list.getHeadNode(), nullptr);
}

// Andrey Morozov
TEST(StudentBidiListInt, insNodesAfter0)
{
    IntBidiList lst;

    IntBidiListNode* nd0 =lst.appendEl(1);
    IntBidiListNode* nd1 = lst.appendEl(2);
    IntBidiListNode* beg = lst.appendEl(3);
    lst.appendEl(4);
    IntBidiListNode* end = lst.appendEl(5);

    lst.cutNodes(beg, end);
    EXPECT_EQ(lst.getLastNode(), nd1);
    EXPECT_EQ(lst.getSize(), 2);

    lst.insertNodesAfter(nd1, beg, end);
    EXPECT_EQ(lst.getLastNode(), end);
    EXPECT_EQ(lst.getSize(), 5);

    lst.cutNodes(nd0, end);
    EXPECT_EQ(lst.getHeadNode(), nullptr);
    EXPECT_EQ(lst.getLastNode(), nullptr);
    EXPECT_EQ(lst.getSize(), 0);

    lst.insertNodesAfter(nullptr, nd0, end);
    EXPECT_EQ(lst.getLastNode(), end);
    EXPECT_EQ(lst.getHeadNode(), nd0);
    EXPECT_EQ(lst.getSize(), 5);
}

// Andrey Morozov
TEST(StudentBidiListInt, Cut)
{
    IntBidiList lst;

    EXPECT_THROW(lst.cutNode(nullptr), std::invalid_argument);

    IntBidiListNode* beg = lst.appendEl(10);
    IntBidiListNode* sec =lst.appendEl(10);
    lst.appendEl(10);
    lst.appendEl(10);
    lst.appendEl(10);

    lst.cutNode(beg);
    EXPECT_EQ(lst.getSize(), 4);
    EXPECT_EQ(lst.getHeadNode(), sec);
    EXPECT_EQ(sec->getPrev(), nullptr);

    int s;
    lst.cutAll(sec, 10, s);
    EXPECT_EQ(lst.getLastNode(), nullptr);
    EXPECT_EQ(lst.getHeadNode(), nullptr);
    EXPECT_EQ(s, 4);
    EXPECT_EQ(lst.getSize(), 0);
}

// Andrey Morozov
TEST(StudentBidiListInt, InsBef)
{
    IntBidiList lst;

    IntBidiListNode* nd = new IntBidiListNode(10);
    lst.insertNodeBefore(nullptr, nd);

    EXPECT_EQ(lst.getHeadNode(), nd);
    EXPECT_EQ(lst.getLastNode(), nd);
    EXPECT_EQ(lst.getSize(), 1);

    IntBidiListNode* nd1 = new IntBidiListNode(20);
    lst.insertNodesBefore(nd, nd1, nd1);

    EXPECT_EQ(lst.getHeadNode(), nd1);
    EXPECT_EQ(lst.getLastNode(), nd);
    EXPECT_EQ(lst.getSize(), 2);
}