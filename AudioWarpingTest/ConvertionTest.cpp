#include "gtest/gtest.h"
#include "AudioClip.h"

using audioWarping::AudioClip;

class ConvertionOneMarkerTest : public ::testing::Test
{
protected:
	void SetUp() override {
		clip.addWarpMarker(1.0, 3.0);
		clip.setEndTempo(2.0);
	}

	AudioClip clip;
};

//===================================================================== B2S One Marker

TEST_F(ConvertionOneMarkerTest, testConvertion_B2S_BeforeMarker)
{
	double beatTime = 0.0;
	double sampleTime = 2.5;

	AudioClip clip;
	clip.addWarpMarker(1.0, 3.0);
	clip.setEndTempo(2.0);

	ASSERT_DOUBLE_EQ(sampleTime, clip.getSampleTime(beatTime));
}

TEST_F(ConvertionOneMarkerTest, testConvertion_B2S_AfterMarker)
{
	double beatTime = 2.0;
	double sampleTime = 3.5;

	AudioClip clip;
	clip.addWarpMarker(1.0, 3.0);
	clip.setEndTempo(2.0);

	ASSERT_DOUBLE_EQ(sampleTime, clip.getSampleTime(beatTime));
}

TEST_F(ConvertionOneMarkerTest, testConvertion_B2S_EqualToMarker)
{
	double beatTime = 1.0;
	double sampleTime = 3.0;

	ASSERT_DOUBLE_EQ(sampleTime, clip.getSampleTime(beatTime));
}

//===================================================================== S2B One Marker

TEST_F(ConvertionOneMarkerTest, testConvertion_S2B_BeforeMarker)
{
	double beatTime = -3.0;
	double sampleTime = 1.0;

	ASSERT_DOUBLE_EQ(beatTime, clip.getBeatTime(sampleTime));
}

TEST_F(ConvertionOneMarkerTest, testConvertion_S2B_AfterMarker)
{
	double beatTime = -5.0;
	double sampleTime = 0.0;

	ASSERT_DOUBLE_EQ(beatTime, clip.getBeatTime(sampleTime));
}

TEST_F(ConvertionOneMarkerTest, testConvertion_S2B_EqualToMarker)
{
	double beatTime = 5.0;
	double sampleTime = 5.0;

	ASSERT_DOUBLE_EQ(beatTime, clip.getBeatTime(sampleTime));
}

class ConvertionNMarkersTest : public ::testing::Test
{
protected:
	void SetUp() override
	{
		clip.addWarpMarker(2.0, 0.5);
		clip.addWarpMarker(4.0, 1.0);
		clip.addWarpMarker(8.0, 2.0);
		clip.setEndTempo(10.0);
	}

	AudioClip clip;
};

//======================================================================== B2S N Markers

TEST_F(ConvertionNMarkersTest, testConvertion_B2S_1)
{
	double beatTime = 2.5;
	double sampleTime = 0.625;

	ASSERT_DOUBLE_EQ(sampleTime, clip.getSampleTime(beatTime));
}

TEST_F(ConvertionNMarkersTest, testConvertion_B2S_2)
{
	double beatTime = 6.0;
	double sampleTime = 1.5;

	ASSERT_DOUBLE_EQ(sampleTime, clip.getSampleTime(beatTime));
}

TEST_F(ConvertionNMarkersTest, testConvertion_B2S_BeforeFirstMarker)
{
	double beatTime = -1.0;
	double sampleTime = -0.25;

	ASSERT_DOUBLE_EQ(sampleTime, clip.getSampleTime(beatTime));
}

TEST_F(ConvertionNMarkersTest, testConvertion_B2S_AfterLastMarker)
{
	double beatTime = 12.0;
	double sampleTime = 2.4;

	ASSERT_DOUBLE_EQ(sampleTime, clip.getSampleTime(beatTime));
}

TEST_F(ConvertionNMarkersTest, testConvertion_B2S_EqualToMarker)
{
	double beatTime = 4.0;
	double sampleTime = 1.0;

	ASSERT_DOUBLE_EQ(sampleTime, clip.getSampleTime(beatTime));
}

TEST_F(ConvertionNMarkersTest, testConvertion_B2S_AddingMarkerInFront)
{
	double beatTime = 0.0;
	double sampleTime = -0.5;

	clip.addWarpMarker(1.0, 0.0);

	ASSERT_DOUBLE_EQ(sampleTime, clip.getSampleTime(beatTime));
}

TEST_F(ConvertionNMarkersTest, testConvertion_B2S_AddingMarkerInTheMiddle)
{
	double beatTime = 5.0;
	double sampleTime = 1.1;

	clip.addWarpMarker(6.0, 1.2);

	ASSERT_DOUBLE_EQ(sampleTime, clip.getSampleTime(beatTime));
}

//======================================================================== S2B N Markers

TEST_F(ConvertionNMarkersTest, testConvertion_S2B_1)
{
	double beatTime = 3.0;
	double sampleTime = 0.75;

	ASSERT_DOUBLE_EQ(beatTime, clip.getBeatTime(sampleTime));
}

TEST_F(ConvertionNMarkersTest, testConvertion_S2B_2)
{
	double beatTime = 6.0;
	double sampleTime = 1.5;

	ASSERT_DOUBLE_EQ(beatTime, clip.getBeatTime(sampleTime));
}

TEST_F(ConvertionNMarkersTest, testConvertion_S2B_BeforeFirstMarker)
{
	double beatTime = -2.0;
	double sampleTime = -0.5;

	ASSERT_DOUBLE_EQ(beatTime, clip.getBeatTime(sampleTime));
}

TEST_F(ConvertionNMarkersTest, testConvertion_S2B_AfterLastMarker)
{
	double beatTime = 12.0;
	double sampleTime = 2.4;

	ASSERT_DOUBLE_EQ(beatTime, clip.getBeatTime(sampleTime));
}

TEST_F(ConvertionNMarkersTest, testConvertion_S2B_EqualToMarker)
{
	double beatTime = 4.0;
	double sampleTime = 1.0;

	ASSERT_DOUBLE_EQ(beatTime, clip.getBeatTime(sampleTime));
}

TEST_F(ConvertionNMarkersTest, testConvertion_S2B_AddingMarkerInFront)
{
	double beatTime = 5.0;
	double sampleTime = 1.1;

	clip.addWarpMarker(6.0, 1.2);

	ASSERT_DOUBLE_EQ(beatTime, clip.getBeatTime(sampleTime));
}

TEST_F(ConvertionNMarkersTest, testConvertion_S2B_AddingMarkerInTheMiddle)
{
	double beatTime = 0.0;
	double sampleTime = -0.5;

	clip.addWarpMarker(1.0, 0.0);

	ASSERT_DOUBLE_EQ(beatTime, clip.getBeatTime(sampleTime));
}