#include "stats.h"

Stats Statistics::ComputeStatistics(const std::vector<float>& src) 
{
	Stats obj;
	float sum = 0;
	if(src.size())
	{
		obj.min = src[0];
	}
	for(auto vec:src)
	{
		if(obj.max<vec)
			obj.max = vec;
		if(obj.min>vec)
			obj.min = vec;
		sum+=vec;
	}
	if(src.size())
	{
		obj.average = sum/src.size();
	}
	return obj;
}

IAlerter::IAlerter()
{
ledGlows = false;
emailSent = false;
}

StatsAlerter::StatsAlerter(float maxThreshold, std::vector<IAlerter*> vecIAlerter)
{
    m_maxThreshold = maxThreshold;
    m_vecIAlerter = vecIAlerter;
}

void StatsAlerter::checkAndAlert(const std::vector<float>& vecData)
{
   float maxElement = 0;
   for(auto ele:vecData)
      if(maxElement<ele)
         maxElement = ele;
   if(maxElement>m_maxThreshold)
   {
       for(auto IAleterEle:m_vecIAlerter)
       {
           IAleterEle->emailSent = true;
           IAleterEle->ledGlows = true;
        }
   }
}
