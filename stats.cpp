#include <vector>

struct Stats
{
	float average;
	float max;
	float min;
	Stats()
	{
		average = 0;
		max = 0;
		min = 0;
	}
};

namespace Statistics {
    Stats ComputeStatistics(const std::vector<float>& );
}



class IAlerter
{
   public:
   IAlerter();

   bool emailSent;
   bool ledGlows;
};
class EmailAlert: public IAlerter
{
};
class LEDAlert: public IAlerter
{
};
class StatsAlerter
{
   public:
   StatsAlerter(float maxThreshold, std::vector<IAlerter*> vecIAlerter);
   void checkAndAlert(const std::vector<float>& vecData);
   private:
   float m_maxThreshold;
   std::vector<IAlerter*> m_vecIAlerter;
};
