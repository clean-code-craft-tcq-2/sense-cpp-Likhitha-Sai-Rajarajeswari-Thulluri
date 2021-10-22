#include <vector>

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
}

namespace Statistics {
    Stats ComputeStatistics(const std::vector<___>& src);
}
