#include <limits>
#include "AudioClip.h"

namespace audioWarping
{
	using MarkerIter = AudioClip::MarkerIter;
	using MarkerIterConst = AudioClip::MarkerIterConst;

	AudioClip::AudioClip() : endTempo { 0 }
	{

	}

	void AudioClip::setEndTempo(double tempo) 
	{ 
		endTempo = tempo; 
	}

	double AudioClip::getEndTempo() const
	{
		return endTempo;
	}

	const std::set<WarpMarker>& AudioClip::getWarpMarkers() const
	{ 
		return markers; 
	}

	const std::pair<MarkerIter, bool> AudioClip::addWarpMarker(double beatTime, double sampleTime)
	{
		return markers.emplace(beatTime, sampleTime);
	}

	const std::pair<MarkerIter, bool> AudioClip::addWarpMarker(const WarpMarker& marker)
	{
		return markers.emplace(marker);
	}

	double AudioClip::getBeatTime(double sampleTime)
	{
		// get marker that is past or equal to the sampleTime
		// (using max double value for beatTime ensures that we get marker that has equal or greater sampleTime)
		std::set<WarpMarker>::iterator endMarker = markers.lower_bound(WarpMarker(std::numeric_limits<double>::max(), sampleTime));
		return convert(endMarker, sampleTime, calcBeatTime);
	}

	double AudioClip::getSampleTime(double beatTime)
	{
		// get marker that is past or equal to the beatTime
		// (using max double value for sampleTime ensures that we get marker that has equal or greater beatTime)
		std::set<WarpMarker>::iterator endMarker = markers.lower_bound(WarpMarker(beatTime, std::numeric_limits<double>::max()));
		return convert(endMarker, beatTime, calcSampleTime);
	}

	double AudioClip::convert(MarkerIterConst endMarker, double time, double calc(MarkerIterConst, double, double))
	{
		// if time is past the last marker, then endMarker is equal to past the end value;
		// get last marker and make convertion using stored endTempo
		if (endMarker == markers.end())
		{
			endMarker--;
			return calc(endMarker, time, endTempo);
		}

		MarkerIterConst startMarker = endMarker;

		// if time is less than first marker in the set,
		// we need to consider two subsequent markers after it
		if (endMarker == markers.begin())
		{
			endMarker++;

			// if there is only one marker in the set
			// make convertion using stored endTempo
			if (endMarker == markers.end())
			{
				return calc(startMarker, time, endTempo);
			}
		}
		// else if time is between two markers
		// decrement startMarker to make it precede time value
		else
			startMarker--;

		return calc(startMarker, time, getTempoBetweenTwoMarkers(startMarker, endMarker));
	}

	double AudioClip::getTempoBetweenTwoMarkers(MarkerIterConst start, MarkerIterConst end)
	{
		if (*start > *end) 
			return 0.0;

		return (end->getBeatTime() - start->getBeatTime()) / (end->getSampleTime() - start->getSampleTime());
	}

	double AudioClip::calcBeatTime(MarkerIterConst marker, double sampleTime, double tempo)
	{
		return marker->getBeatTime() + (sampleTime - marker->getSampleTime()) * tempo;
	}

	double AudioClip::calcSampleTime(MarkerIterConst marker, double beatTime, double tempo)
	{
		return marker->getSampleTime() + (beatTime - marker->getBeatTime()) / tempo;
	}
}