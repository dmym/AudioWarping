#pragma once

#include <set>
#include <utility>
#include <string>
#include "WarpMarker.h"

namespace audioWarping 
{
	// This class holds tempo and markers information related to specific audio sample
	// and implements functinality to get beat time from sample time and vice versa
	class AudioClip
	{
	public:
		AudioClip();

		typedef std::set<WarpMarker>::iterator MarkerIter;
		typedef std::set<WarpMarker>::const_iterator MarkerIterConst;

		void setEndTempo(double tempo);
		double getEndTempo() const;

		const std::pair<MarkerIter, bool> addWarpMarker(double beatTime, double sampleTime);
		const std::pair<MarkerIter, bool> addWarpMarker(const WarpMarker& marker);
		const std::set<WarpMarker>& getWarpMarkers() const;

		double getBeatTime(double sampleTime);
		double getSampleTime(double beatTime);

	private:
		double endTempo;
		std::set<WarpMarker> markers;

		// Returns converted time value using specified function - @calc.
		// @calc function should implement convertion from beat time to sample time or vice versa.
		double convert(MarkerIterConst endMarker, double time, double calc(MarkerIterConst, double, double));
		
		// Gets tempo between to markers. 
		// For proper calculation @start marker must be less than @end marker.
		double getTempoBetweenTwoMarkers(MarkerIterConst start, MarkerIterConst end);

		// Calculates beat time using preceding marker, sample time and tempo
		static double calcBeatTime(MarkerIterConst marker, double sampleTime, double tempo);

		// Calculates sample time using preceding marker, beat time and tempo
		static double calcSampleTime(MarkerIterConst marker, double beatTime, double tempo);
	};	
}
