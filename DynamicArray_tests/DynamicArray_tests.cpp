#include "pch.h"
#include "CppUnitTest.h"
#include "../lab1 (3 sem)/lab1 (3 sem).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
	TEST_CLASS(UnitTest2)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			DynamicArray<int> arr1(5);
			DynamicArray<int> arrr(std::move(arr1));
			int arr1_size_expected = 0;
			int arrr_size_expected = 5;
			int arr1_size_actual = arr1.get_size();
			int arrr_size_actual = arrr.get_size();
			Assert::AreEqual(arrr_size_expected, arrr_size_actual);
		}
		TEST_METHOD(TestMethod2)
		{
			DynamicArray<int> arr1(5);
			DynamicArray<int> arrr(std::move(arr1));
			int arr1_size_expected = 0;
			int arrr_size_expected = 5;
			int arr1_size_actual = arr1.get_size();
			int arrr_size_actual = arrr.get_size();
			Assert::AreEqual(arr1_size_expected, arr1_size_actual);
		}
		TEST_METHOD(TestMethod3)
		{
			DynamicArray<int> arr1(5);
			int elem_actual;
			arr1.set(0, 0);
			elem_actual = arr1.get(0);
			int elem_expected = 0;
			Assert::AreEqual(elem_expected, elem_actual);
		}
		TEST_METHOD(TestMethod4)
		{
			DynamicArray<int> arr1(5);
			int size_expected = 5;
			int size_actual = arr1.get_size();
			Assert::AreEqual(size_expected, size_actual);
		}
		TEST_METHOD(TestMethod5)
		{
			DynamicArray<int> arr1(5);
			arr1[0] = 6;
			int elem_expected = 6;
			int elem_actual = arr1.get(0);
			Assert::AreEqual(elem_expected, elem_actual);
		}
		TEST_METHOD(TestMethod6)
		{
			DynamicArray<int> arr1(5);
			arr1.resize(4);
			int elem_expected = 4;
			int elem_actual = arr1.get_size();
			Assert::AreEqual(elem_expected, elem_actual);
		}
		TEST_METHOD(TestMethod7)
		{
			int items[] = { 24,5,13,246,2094 };
			DynamicArray<int> arr1(items, 5);
			arr1.remove_first();
			int elem_expected = 5;
			int elem_actual = arr1.get(0);
			Assert::AreEqual(elem_expected, elem_actual);
		}
	};
}
