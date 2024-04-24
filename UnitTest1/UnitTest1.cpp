#include "pch.h"
#include "CppUnitTest.h"
#include "..//AP Lab 12.7/AP Lab 12.7.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual(3, calcstages(8, 0));
		}
	};
}
