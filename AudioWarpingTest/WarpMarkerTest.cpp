#include "gtest/gtest.h"
#include "WarpMarker.h"

using audioWarping::WarpMarker;

TEST(WarpMarker, testConstruction)
{
	double beatTime = 1.0;
	double sampleTime = 0.5;
	
	WarpMarker m(beatTime, sampleTime);

	ASSERT_DOUBLE_EQ(m.getBeatTime(), beatTime);
	ASSERT_DOUBLE_EQ(m.getSampleTime(), sampleTime);
}

TEST(WarpMarker, testOperator_LT)
{
	WarpMarker m1(1.0, 1.0);
	WarpMarker m2(2.0, 1.1);
	ASSERT_LT(m1, m2);
}

TEST(WarpMarker, testOperator_LT_Negative)
{
	WarpMarker m1(1.0, 1.0);
	WarpMarker m2(2.0, 1.1);
	ASSERT_FALSE(m2 < m1);
}

TEST(WarpMarker, testOperator_LE)
{
	WarpMarker m1(1.0, 1.0);
	WarpMarker m2(1.5, 2.0);
	ASSERT_LE(m1, m2);
}

TEST(WarpMarker, testOperator_LE_Negative)
{
	WarpMarker m1(1.0, 1.0);
	WarpMarker m2(1.5, 2.0);
	ASSERT_FALSE(m2 <= m1);
}

TEST(WarpMarker, testOperator_GT)
{
	WarpMarker m1(2.0, 1.1);
	WarpMarker m2(1.0, 1.0);
	ASSERT_GT(m1, m2);
}

TEST(WarpMarker, testOperator_GT_Negative)
{
	WarpMarker m1(2.0, 1.1);
	WarpMarker m2(1.0, 1.0);
	ASSERT_FALSE(m2 > m1);
}

TEST(WarpMarker, testOperator_GE)
{
	WarpMarker m1(1.0, 1.0);
	WarpMarker m2(1.0, 1.0);
	ASSERT_GE(m1, m2);
}

TEST(WarpMarker, testOperator_GE_Negative)
{
	WarpMarker m1(1.0, 1.0);
	WarpMarker m2(1.1, 1.1);
	ASSERT_FALSE(m1 >= m2);
}

TEST(WarpMarker, testOperator_EQ)
{
	WarpMarker m1(1.0, 1.0);
	WarpMarker m2(1.0, 1.0);
	ASSERT_EQ(m1, m2);
}

TEST(WarpMarker, testOperator_EQ_Negative)
{
	WarpMarker m1(1.0, 1.0);
	WarpMarker m2(1.1, 1.1);
	ASSERT_FALSE(m1 == m2);
}

TEST(WarpMarker, testOperator_NE)
{
	WarpMarker m1(2.0, 1.2);
	WarpMarker m2(1.0, 1.1);
	ASSERT_NE(m1, m2);
}

TEST(WarpMarker, testOperator_NE_Negative)
{
	WarpMarker m1(1.1, 1.1);
	WarpMarker m2(1.1, 1.1);
	ASSERT_FALSE(m1 != m2);
}