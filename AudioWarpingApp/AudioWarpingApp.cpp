#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include "AudioClip.h"

using audioWarping::AudioClip;

int main()
{
	AudioClip clip;
	std::string inputType;
	double beatTime, sampleTime, endTempo;
	std::vector<double> convertions;

	std::cout << "Please enter input data:" << std::endl;

	// read from standart input
	while (std::cin >> inputType)
	{
		const char* cInputType = inputType.c_str();

		if (std::strcmp(cInputType, "marker") == 0)
		{
			std::cin >> beatTime >> sampleTime;
			clip.addWarpMarker(beatTime, sampleTime);
		}
		else if (std::strcmp(cInputType, "end_tempo") == 0)
		{
			std::cin >> endTempo;
			clip.setEndTempo(endTempo);
		}
		else if (std::strcmp(cInputType, "b2s") == 0)
		{
			std::cin >> beatTime;
			convertions.push_back(clip.getSampleTime(beatTime));
		}
		else if (std::strcmp(cInputType, "s2b") == 0)
		{
			std::cin >> sampleTime;
			convertions.push_back(clip.getBeatTime(sampleTime));
		}
	}

	// print convertion values
	for (auto c : convertions)
		std::cout << c << std::endl;

	return 0;
}