
#include "stats.h"
#include <vector>
#include <algorithm>
#include <limits>
#define CUSTOM_NAN (std::numeric_limits<double>::quiet_NaN())

Statistics::Stats Statistics::ComputeStatistics(const std::vector<float>& data)
{
	//Implement statistics here
	Statistics::Stats stats;
	if (data.empty())
	{
		stats.average = CUSTOM_NAN;
		stats.maximum = CUSTOM_NAN;
		stats.minimum = CUSTOM_NAN;
	}
	else
	{
		// Calculate the average
		float sum = 0.0f;
		for (float value : data)
		{
			sum += value;
		}
		stats.average = sum / static_cast<float>(data.size());

		// Find the maximum and minimum values
		stats.maximum = *std::max_element(data.begin(), data.end());
		stats.minimum = *std::min_element(data.begin(), data.end());
	}
	return stats;
}

void EmailAlert::alert()
{
	emailSent = true;
}

void LEDAlert::alert()
{
	ledGlows = true;
}

void StatsAlerter::checkAndAlert(const std::vector<float>& data)
{
	for (float value : data)
	{
		if (value > maxThreshold)
		{
			for (IAlerter* alerter : alerters)
			{
				alerter->alert();
			}
			break;
		}
	}
}

