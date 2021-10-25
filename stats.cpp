#include "stats.h"
#include <algorithm>
#include <numeric>
Stats Statistics::ComputeStatistics(const std::vector<float>& vecData) 
{
   Stats statsObj;
   if(vecData.empty())
   {
       statsObj.min = NAN;
       statsObj.max = NAN;
       statsObj.average = NAN;
       return statsObj;
   }
   statsObj.min = *min_element(vecData.begin(), vecData.end());
   statsObj.max = *max_element(vecData.begin(), vecData.end());
   statsObj.average = accumulate(vecData.begin(), vecData.end(), 0.0)/vecData.size();
   return statsObj;
}

IAlerter::IAlerter():emailSent(false) ,ledGlows(false)
{
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
      m_vecIAlerter[0]->emailSent = true;
      m_vecIAlerter[1]->ledGlows = true;
   }
}
