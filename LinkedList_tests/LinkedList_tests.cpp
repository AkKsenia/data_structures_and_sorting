#include "pch.h"
#include "CppUnitTest.h"
#include "../lab1 (3 sem)/lab1 (3 sem).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LinkedListtests
{
	TEST_CLASS(LinkedListtests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			LinkedList<int> list1;
			list1.prepend(0);
			list1.prepend(1);
			int elem_expected = 0;
			int elem_actual;
			elem_actual = list1.get_last();
			Assert::AreEqual(elem_expected, elem_actual);
		}
		TEST_METHOD(TestMethod2)
		{
			LinkedList<int> list1;
			list1.append(0);
			list1.append(1);
			int elem_expected = 1;
			int elem_actual;
			elem_actual = list1.get_last();
			Assert::AreEqual(elem_expected, elem_actual);
		}
		TEST_METHOD(TestMethod3)
		{
			LinkedList<int> list1;
			int elem_actual;
			list1.insert_at(2, 0);
			elem_actual = list1.get(0);
			int elem_expected = 2;
			Assert::AreEqual(elem_expected, elem_actual);
		}
		TEST_METHOD(TestMethod4)
		{
			LinkedList<int> list1;
			list1.append(0);
			list1.append(1);
			int size_expected = 2;
			int size_actual = list1.get_length();
			Assert::AreEqual(size_expected, size_actual);
		}
		TEST_METHOD(TestMethod5)
		{
			LinkedList<int> list1;
			list1.append(0);
			list1.append(1);
			int size_expected = 2;
			int size_actual = list1.get_length();
			Assert::AreEqual(size_expected, size_actual);
		}
		TEST_METHOD(TestMethod6)
		{
			LinkedList<int> list1;
			list1.append(0);
			list1.append(1);
			int elem_expected = 0;
			int elem_actual = list1.get_first();
			Assert::AreEqual(elem_expected, elem_actual);
		}
		TEST_METHOD(TestMethod7)
		{
			LinkedList<int> list1;
			list1.append(0);
			list1.append(1);
			list1.set(2, 1);
			int elem_expected = 2;
			int elem_actual = list1.get(1);
			Assert::AreEqual(elem_expected, elem_actual);
		}
		TEST_METHOD(TestMethod8)
		{
			LinkedList<int> list1;
			LinkedList<int>* list2;
			list1.append(0);
			list1.append(1);
			list1.append(23);
			list1.append(15);
			list2 = list1.get_sub_list(1, 3);
			int elem_expected = 15;
			int elem_actual = list2->get(2);
			Assert::AreEqual(elem_expected, elem_actual);
		}
		TEST_METHOD(TestMethod9)
		{
			LinkedList<int> list1;
			LinkedList<int> list2;
			LinkedList<int>* list3;
			list1.append(0);
			list1.append(1);
			list2.append(23);
			list2.append(15);
			list3 = list1.concat(list2);
			int elem_expected = 1;
			int elem_actual = list3->get(1);
			Assert::AreEqual(elem_expected, elem_actual);
		}
		TEST_METHOD(TestMethod10)
		{
			LinkedList<int> list1;
			list1.append(0);
			list1.append(1);
			list1.append(23);
			list1.append(15);
			list1.remove_first();
			int elem_expected = 1;
			int elem_actual = list1.get(0);
			Assert::AreEqual(elem_expected, elem_actual);
		}
	};
}
