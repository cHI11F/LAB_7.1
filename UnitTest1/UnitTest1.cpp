#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB_7.1/LAB_7.1.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(Create_GeneratesRandomValuesWithinRange) {
            const int rowCount = 4;
            const int colCount = 5;
            const int Low = -10;
            const int High = 20;
            int** Q = new int* [rowCount];
            for (int i = 0; i < rowCount; i++) {
                Q[i] = new int[colCount];
            }

            Create(Q, rowCount, colCount, Low, High);

            for (int i = 0; i < rowCount; i++) {
                for (int j = 0; j < colCount; j++) {
                    Assert::IsTrue(Q[i][j] >= Low);
                    Assert::IsTrue(Q[i][j] <= High);
                }
            }

            for (int i = 0; i < rowCount; i++) {
                delete[] Q[i];
            }
            delete[] Q;
        }
    };
}
