#include "pch.h"
#include "CppUnitTest.h"
#include "../lab1 (3 sem)/lab1 (3 sem).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LinkedListSequencetests
{
	TEST_CLASS(LinkedListSequencetests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int* symb = new int[4];
			symb[0] = 1;
			symb[1] = 2;
			symb[2] = 65;
			symb[3] = 8;
			LinkedListSequence<int> list11(symb, 4);
			delete[] symb;
			int size_expected = 4;
			int size_actual = list11.get_length();
			Assert::AreEqual(size_expected, size_actual);
		}
		TEST_METHOD(TestMethod2)
		{
			int* symb = new int[4];
			symb[0] = 1;
			symb[1] = 2;
			symb[2] = 65;
			symb[3] = 8;
			LinkedListSequence<int> list11(symb, 4);
			delete[] symb;
			int elem_expected = 1;
			int elem_actual = list11.get_first();
			Assert::AreEqual(elem_expected, elem_actual);
		}
		TEST_METHOD(TestMethod3)
		{
			int* symb = new int[4];
			symb[0] = 1;
			symb[1] = 2;
			symb[2] = 65;
			symb[3] = 8;
			LinkedListSequence<int> list11(symb, 4);
			delete[] symb;
			int elem_expected = 8;
			int elem_actual = list11.get_last();
			Assert::AreEqual(elem_expected, elem_actual);
		}
		TEST_METHOD(TestMethod4)
		{
			int* symb = new int[4];
			symb[0] = 1;
			symb[1] = 2;
			symb[2] = 65;
			symb[3] = 8;
			LinkedListSequence<int> list11(symb, 4);
			list11.prepend(12);
			delete[] symb;
			int elem_expected = 12;
			int elem_actual = list11.get_first();
			Assert::AreEqual(elem_expected, elem_actual);
		}
		TEST_METHOD(TestMethod5)
		{
			int* symb = new int[4];
			symb[0] = 1;
			symb[1] = 2;
			symb[2] = 65;
			symb[3] = 8;
			LinkedListSequence<int> list11(symb, 4);
			list11.append(12);
			delete[] symb;
			int elem_expected = 12;
			int elem_actual = list11.get_last();
			Assert::AreEqual(elem_expected, elem_actual);
		}
		TEST_METHOD(TestMethod6)
		{
			int* symb = new int[4];
			symb[0] = 1;
			symb[1] = 2;
			symb[2] = 65;
			symb[3] = 8;
			LinkedListSequence<int> list11(symb, 4);
			list11.insert_at(3, 1);
			delete[] symb;
			int elem_expected = 3;
			int elem_actual = list11.get(1);
			Assert::AreEqual(elem_expected, elem_actual);
		}
		TEST_METHOD(TestMethod7)
		{
			int* symb = new int[4];
			symb[0] = 1;
			symb[1] = 2;
			symb[2] = 65;
			symb[3] = 8;
			LinkedListSequence<int> list11(symb, 4);
			delete[] symb;
			list11.set(7, 2);
			int expected = 7;
			int actual = list11.get(2);
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(TestMethod8)
		{
			int* symb = new int[4];
			symb[0] = 1;
			symb[1] = 2;
			symb[2] = 65;
			symb[3] = 8;
			LinkedListSequence<int> arr(symb, 4);
			delete[] symb;
			arr.remove_first();
			int expected = 2;
			int actual = arr.get(0);
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(TestMethod9)
		{
			int* symb = new int[4];
			symb[0] = 1;
			symb[1] = 2;
			symb[2] = 65;
			symb[3] = 8;
			LinkedListSequence<int> arr(symb, 4);
			LinkedListSequence<int> arr1(symb, 2);
			Sequence<int>* seq = &arr;
			delete[] symb;
			arr1.concat(*seq);
			int expected = 2;
			int actual = arr1.get(3);
			Assert::AreEqual(expected, actual);
		}
	};
}
