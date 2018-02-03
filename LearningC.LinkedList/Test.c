#include "stdafx.h"
#include "Test.h"
#include "LinkedListTest.h"

void Test() {

	/*0-linkedlist-create*/
	//TestCreateByTailConsole();
	TestCreateByHead();
	TestCreateByTailWithHead();
	TestCreateByTail();

	/*1-linkedlist-print*/
	TestPrint();

	/*2-linkedlist-insert*/
	TestInsertAtTail();
	TestInsertAtHead();
	TestInsertNth();

	/*3-linkedlist-delete*/
	TestDeleteNth();

	/*4-linkedlist-reverse*/
	TestReversePrint();
	TestReverse();
	TestReverseList();
	TestSwitchNode();

	/*5-linkedlist-compare*/
	TestCompareLists();

	/*6-linkedlist-merge*/
	TestMergeLists();
	TestMergeTwoSorted();

	/*7-linkedlist-get*/
	TestGetNthFromTail();

	/*8-linkedlist-distinct*/
	TestRemoveDuplicates();
	TestRemoveDuplicates2();

	/*9-linkedlist-cycle-detection*/
	TestHasCycle();
	TestHasCycle2();

	/*10-linkedlist-find-merge-point*/
	TestFindMergeNode1();
	TestFindMergeNode2();
	TestFindMergeNode3();
	TestFindMergeNode4();

	/*11-linkedlist-split*/
	TestSplitToEvenOdd();

	/*12-linkedlist-intersect*/
	TestIntersect();

	/*13-linkedlist-diff*/
	TestDiff();
}
