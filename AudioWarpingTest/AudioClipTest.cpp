#include <utility>
#include "gtest/gtest.h"
#include "AudioClip.h"

using audioWarping::AudioClip;
using audioWarping::WarpMarker;

TEST(AudioClip, testAddingWarpMarker_resultCheck)
{
	AudioClip clip;
	std::pair<AudioClip::MarkerIter, bool> result = clip.addWarpMarker(1.0, 1.0);
	
	ASSERT_TRUE(result.second);
}

TEST(AudioClip, testAddingWarpMarker_valuesCheck)
{
	AudioClip clip;
	WarpMarker wm(1.0, 1.0);
	std::pair<AudioClip::MarkerIter, bool> result = clip.addWarpMarker(wm);
	
	ASSERT_EQ(wm, *(result.first));
}

TEST(AudioClip, testMarkersSize)
{
	int size = 2;
	
	AudioClip clip;
	clip.addWarpMarker(1.0, 3.0);
	clip.addWarpMarker(2.0, 4.0);

	ASSERT_EQ(size, clip.getWarpMarkers().size());
}

TEST(AudioClip, testEndTempo_Get_Set)
{
	double tempo = 2.0;

	AudioClip clip;
	clip.setEndTempo(tempo);
	
	ASSERT_DOUBLE_EQ(tempo, clip.getEndTempo());
}
