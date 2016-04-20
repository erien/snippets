#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> solution(int N, std::vector<int> &A) {
    std::vector<int> ret(N, 0);
    int maxCounter = 0;
    int fill = 0;
    
    for (auto &elem : A)
    {
        if (elem == N + 1)
        {
            fill = maxCounter;
        }
        if (elem <= N)
        {
            if (fill == maxCounter )
            {
                ret[elem - 1] = fill;
            }
            if (maxCounter < ret[elem - 1] + 1)
            {
                maxCounter = ret[elem - 1] + 1;
            }
            ++ret[elem - 1];
        }

    }
    std::for_each(ret.begin(), ret.end(), [fill](int &n){ if (n < fill) n = fill;});
    
    return ret;
}


int main()
{
  std::cout << "Counters test." << std::endl;
}
