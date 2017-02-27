#include "stdafx.h"
#include "CppUnitTest.h"
#include <FileSystemWrapper/FileSystemWrapper.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FileSystemWrapperUnitTest
{		
	TEST_CLASS(ExtensionFilterTests)
	{
	public:
		
		TEST_METHOD(TestMatches)
		{
			auto filter = FSW::ExtensionFilter{};
			filter.Add("jpeg");  //the dot will be inserted if missing
			filter.Add("bmp");
			filter.Add(".gif");

			Assert::IsTrue(filter.Match("test.jpeg"));
			Assert::IsTrue(filter.Match("test.bmp"));
			Assert::IsTrue(filter.Match("test.jpeg.jpeg"));
			Assert::IsTrue(filter.Match("test.jpeg.gif"));
		}

		TEST_METHOD(TestNonMatches)
		{
			auto filter = FSW::ExtensionFilter{};
			filter.Add("jpeg");  //the dot will be inserted if missing
			filter.Add("bmp");
			filter.Add(".gif");

			Assert::IsFalse(filter.Match("test.jpg"));
			Assert::IsFalse(filter.Match("testbmp"));
			Assert::IsFalse(filter.Match("jpeg"));
			Assert::IsFalse(filter.Match("gif"));
			Assert::IsFalse(filter.Match(""));
			Assert::IsFalse(filter.Match("1247248"));
		}

	};
}