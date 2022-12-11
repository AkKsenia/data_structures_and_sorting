#include "pch.h"
#include "CppUnitTest.h"
#include "../lab1 (3 sem)/lab1 (3 sem).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Sorttests
{
	TEST_CLASS(Sorttests)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			int items[] = { 5676, 35, 890, 334, 46, 1234, 24, 13, 672, 1 };
			LinkedListSequence<int> list(items, 10);
			Sequence<int>* seq = &list;
			seq->binary_insertion_sort_(comparator_ascending_order);
			int expected = 1;
			int actual = seq->get_first();
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(TestMethod2)
		{
			int items[] = { 5676, 35, 890, 334, 46, 1234, 24, 13, 672, 1 };
			LinkedListSequence<int> list(items, 10);
			Sequence<int>* seq = &list;
			seq->merge_sort_(comparator_ascending_order);
			int expected = 1;
			int actual = seq->get_first();
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(TestMethod3)
		{
			int items[] = { 5676, 35, 890, 334, 46, 1234, 24, 13, 672, 1 };
			LinkedListSequence<int> list(items, 10);
			Sequence<int>* seq = &list;
			seq->quick_sort_(comparator_ascending_order);
			int expected = 1;
			int actual = seq->get_first();
			Assert::AreEqual(expected, actual);
		}
	};
}
