#include "stdafx.h"
#include "CppUnitTest.h"

#include "../cpp-works/src/backup/test1.h"
#include "cc150/c5_3.h"
#include "cc150/c5_7.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unit_test
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			C5_3 c;
			int a = 16;
			string s = c.BinaryString(a);
			int fns = c.FindNextLargest(a);
			string t = c.BinaryString(fns);
		}


		TEST_METHOD(TestMethod2) {
			C5_7 c;
			int arr[] = { 0, 1, 2, 3, 4, 5, 6, 8, 9, 7, 11, 12 };
			int result = c.FindMissing(arr, 12);
			printf("");
		}
	};
}