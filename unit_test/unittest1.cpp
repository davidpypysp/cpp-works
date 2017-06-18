#include "stdafx.h"
#include "CppUnitTest.h"

#include "../cpp-works/src/backup/test1.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unit_test
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: Your test code here
			Assert::AreNotEqual(93, 3);
		}


		TEST_METHOD(TestMethod2) {
			int a = 1;
			int b = 1;
			Assert::AreEqual(a, b);
		}
	};
}