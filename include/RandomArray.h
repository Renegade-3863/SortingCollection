// 用于生成随机的数组进行测试的头文件
#include <random>
#include <iostream>
#include <vector>
#include <time.h>

namespace randomArray {
class ArrayGenerator {
public:
    ArrayGenerator() = default;
    ~ArrayGenerator() = default;

    void getArray(std::vector<int>& v);
};
}