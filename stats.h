#include <vector>

namespace Statistics {
    // define the Stats structure here. See the tests to infer its properties
	struct Stats
	{
		float average;
		float maximum;
		float minimum;

		Stats() :average(0.0), maximum(INT_MIN), minimum(INT_MAX)
		{

		}
		
	};
    Stats ComputeStatistics(const std::vector<float>& data );
}
