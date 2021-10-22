#include "stats.h"

struct computed
{
    float average;
    float max;
    float min;
    computed()
    {
        average = 0;
        max = 0;
        min = 0;
    }
};

Stats Statistics::ComputeStatistics(const std::vector<___>& ) {
    computed obj;
    float sum = 0;
    for(float vec:src)
    {
        if(obj.max<vec)
            obj.max = vec;
        if(obj.min>vec)
        {
            obj.min = vec;
        }
        sum+=vec;
    }
    if(src.size())
    {
        obj.average = sum/src.size();
    }
    return obj;
}
