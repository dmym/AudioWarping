#pragma once

namespace audioWarping
{
	class WarpMarker
	{
	public:
		WarpMarker(double beatTime, double sampleTime)
			: beatTime(beatTime), sampleTime(sampleTime)
		{}

		double getBeatTime() const;
		double getSampleTime() const;

	private:
		double beatTime;
		double sampleTime;

		friend bool operator==(const WarpMarker& lhs, const WarpMarker& rhs);
		friend bool operator!=(const WarpMarker& lhs, const WarpMarker& rhs);
		friend bool operator< (const WarpMarker& lhs, const WarpMarker& rhs);
		friend bool operator> (const WarpMarker& lhs, const WarpMarker& rhs);
		friend bool operator<=(const WarpMarker& lhs, const WarpMarker& rhs);
		friend bool operator>=(const WarpMarker& lhs, const WarpMarker& rhs);
	};
}
