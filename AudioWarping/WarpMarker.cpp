#include <limits>
#include <cstdlib>
#include <algorithm>
#include "WarpMarker.h"

namespace audioWarping
{
	// absolute error convenient for milliseconds comparison
	static const double abs_err = 1e-4;

	bool operator<(const WarpMarker& lhs, const WarpMarker& rhs)
	{
		return rhs.beatTime - lhs.beatTime > abs_err 
			&& rhs.sampleTime - lhs.sampleTime > abs_err;
	}

	bool operator>(const WarpMarker& lhs, const WarpMarker& rhs) { return  rhs < lhs; }
	bool operator<=(const WarpMarker& lhs, const WarpMarker& rhs) { return !(lhs > rhs); }
	bool operator>=(const WarpMarker& lhs, const WarpMarker& rhs) { return !(lhs < rhs); }

	bool operator==(const WarpMarker& lhs, const WarpMarker& rhs)
	{
		return std::abs(lhs.beatTime - rhs.beatTime) < abs_err 
			&& std::abs(lhs.sampleTime - rhs.sampleTime) < abs_err;
	}

	bool operator!=(const WarpMarker& lhs, const WarpMarker& rhs) { return !(lhs == rhs); }

	double WarpMarker::getBeatTime() const { return beatTime; }
	double WarpMarker::getSampleTime() const { return sampleTime; }
}
