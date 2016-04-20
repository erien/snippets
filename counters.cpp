#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> solution(int N, std::vector<int> &A) {
    std::vector<int> ret(N, 0);
    int max = 0;
    int fill = 0;
    
    for (auto &elem : A)
    {
        if (elem == N + 1)
        {
            fill = max;
        }
        if (elem <= N)
        {
            if (fill > ret[elem - 1] )
            {
                ret[elem - 1] = fill;
            }
            ++ret[elem - 1];
            std::max(max, ret[elem - 1]);
        }

    }
    std::for_each(ret.begin(), ret.end(), [fill](int &n){ if (n < fill) n = fill;});
    return ret;
}
