
#include "gtest/gtest.h"
#include <cmath>
#include "stats.h"


TEST(Statistics, ReportsAverageMinMax)
{
	auto computedStats = Statistics::ComputeStatistics({ 1.5, 8.9, 3.2, 4.5 });
	float epsilon = 0.001;
	EXPECT_LT(abs(computedStats.average - 4.525), epsilon);
	EXPECT_LT(abs(computedStats.maximum - 8.9), epsilon);
	EXPECT_LT(abs(computedStats.minimum - 1.5), epsilon);
}

TEST(Statistics, AverageNaNForEmpty)
{
	auto computedStats = Statistics::ComputeStatistics({});

	EXPECT_TRUE(isnan(computedStats.average));
	EXPECT_TRUE(isnan(computedStats.maximum));
	EXPECT_TRUE(isnan(computedStats.minimum));
}

TEST(Alert, AlertsWhenMaxExceeds)
{
	EmailAlert emailAlert;
	LEDAlert ledAlert;
	std::vector<IAlerter*> alerters = { &emailAlert, &ledAlert };

	const float maxThreshold = 10.2;
	StatsAlerter statsAlerter(maxThreshold, alerters);
	statsAlerter.checkAndAlert({ 99.8, 34.2, 4.5, 6.7 });

	EXPECT_TRUE(emailAlert.emailSent);
	EXPECT_TRUE(ledAlert.ledGlows);
}
