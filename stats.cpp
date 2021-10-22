#include "stats.h"

computed ComputeStatistics(const std::vector<___>& src) {
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
