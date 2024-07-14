#include "RandomArray.h"

void randomArray::ArrayGenerator::getArray(std::vector<int>& v)
{
    // 生成一个长度为1-100的数组
    size_t n = rand() % (100) + 1; 
    v.resize(n);
    for(int i = 0; i < n; ++i)
    {
        // 每个值在-10000-10000之间
        v[i] = rand() % (20001)-10000;
    }
}