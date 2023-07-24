#pragma once
#include <vector>


namespace Statistics {
    // define the Stats structure here. See the tests to infer its properties
	struct Stats
	{
		float average;
		float maximum;
		float minimum;

		Stats() :average(0.0), maximum(0.0), minimum(0.0)
		{

		}
		
	};
    Stats ComputeStatistics(const std::vector<float>& data );

	

}
class IAlerter {
public:
	virtual ~IAlerter() {}
	virtual void alert() = 0;
};


class EmailAlert : public IAlerter {
public:
	bool emailSent = false;
	void alert();
};

class LEDAlert : public IAlerter {
public:
	bool ledGlows = false;
	void alert();
};

class StatsAlerter {
private:
	const float maxThreshold;
	std::vector<IAlerter*> alerters;

public:
	StatsAlerter(float threshold, const std::vector<IAlerter*>& alerters)
		: maxThreshold(threshold), alerters(alerters) {}
	void checkAndAlert(const std::vector<float>& data);
};
