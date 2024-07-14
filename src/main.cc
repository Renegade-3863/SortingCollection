#include "mySort.hpp"
#include "RandomArray.h"
#include <memory>
#include <assert.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    // 使用智能指针，避免使用new分配内存最后忘记释放，同时限定对于当前排序器只有一个指针可以指向
    std::unique_ptr<mySort::mySorter> s = std::make_unique<mySort::mySorter>();
    std::unique_ptr<randomArray::ArrayGenerator> generator = std::make_unique<randomArray::ArrayGenerator>();
    // 选择排序部分
    std::vector<int> test1;
    srand(time(0));
    generator->getArray(test1);
    std::cout << "------selection test-------\n\n";
    std::vector<int> test(test1.size());
    std::copy(test1.begin(), test1.end(), test.begin());
    std::sort(test.begin(), test.end());
    std::cout << "Before sorting, the array is like: \n";
    for(int i = 0; i < test1.size(); ++i)
        std::cout << test1[i] << " ";
    std::cout << "\n";
    // 进行排序
    s->selection<int>(test1);
    for(int i = 0; i < test1.size(); ++i)
    {
        assert(test1[i] == test[i]);
    }
    std::cout << "After sorting, the array turns out to be: \n";
    for(int i = 0; i < test1.size(); ++i)
        std::cout << test1[i] << " ";
    std::cout << "\n\n";

    sleep(1);

    // 冒泡排序部分
    std::vector<int> test2;
    srand(time(0));
    generator->getArray(test2);
    std::cout << "------bubble test-------\n\n";
    test.resize(test2.size());
    std::copy(test2.begin(), test2.end(), test.begin());
    std::sort(test.begin(), test.end());
    std::cout << "Before sorting, the array is like: \n";
    for(int i = 0; i < test2.size(); ++i)
        std::cout << test2[i] << " ";
    std::cout << "\n";
    // 进行排序
    s->bubble<int>(test2);
    for(int i = 0; i < test2.size(); ++i)
    {
        assert(test2[i] == test[i]);
    }
    std::cout << "After sorting, the array turns out to be: \n";
    for(int i = 0; i < test2.size(); ++i)
        std::cout << test2[i] << " ";
    std::cout << "\n\n";

    sleep(1);

    // 插入排序部分
    std::vector<int> test3;
    srand(time(0));
    generator->getArray(test3);
    std::cout << "------insertion test-------\n\n";
    test.resize(test3.size());
    std::copy(test3.begin(), test3.end(), test.begin());
    std::sort(test.begin(), test.end());
    std::cout << "Before sorting, the array is like: \n";
    for(int i = 0; i < test3.size(); ++i)
        std::cout << test3[i] << " ";
    std::cout << "\n";
    // 进行排序
    s->insertion<int>(test3);
    for(int i = 0; i < test3.size(); ++i)
    {
        assert(test3[i] == test[i]);
    }
    std::cout << "After sorting, the array turns out to be: \n";
    for(int i = 0; i < test3.size(); ++i)
        std::cout << test3[i] << " ";
    std::cout << "\n\n";

    sleep(1);

    // 希尔排序部分
    std::vector<int> test4;
    srand(time(0));
    generator->getArray(test4);
    std::cout << "------shell test-------\n\n";
    test.resize(test4.size());
    std::copy(test4.begin(), test4.end(), test.begin());
    std::sort(test.begin(), test.end());
    std::cout << "Before sorting, the array is like: \n";
    for(int i = 0; i < test4.size(); ++i)
        std::cout << test4[i] << " ";
    std::cout << "\n";
    // 进行排序
    s->insertion<int>(test4);
    for(int i = 0; i < test4.size(); ++i)
    {
        assert(test4[i] == test[i]);
    }
    std::cout << "After sorting, the array turns out to be: \n";
    for(int i = 0; i < test4.size(); ++i)
        std::cout << test4[i] << " ";
    std::cout << "\n\n";

    sleep(1);

    // 快速排序部分
    std::vector<int> test5;
    srand(time(0));
    generator->getArray(test5);
    std::cout << "------quick test-------\n\n";
    test.resize(test5.size());
    std::copy(test5.begin(), test5.end(), test.begin());
    std::sort(test.begin(), test.end());
    std::cout << "Before sorting, the array is like: \n";
    for(int i = 0; i < test5.size(); ++i)
        std::cout << test5[i] << " ";
    std::cout << "\n";
    // 进行排序
    s->insertion<int>(test5);
    for(int i = 0; i < test5.size(); ++i)
    {
        assert(test5[i] == test[i]);
    }
    std::cout << "After sorting, the array turns out to be: \n";
    for(int i = 0; i < test5.size(); ++i)
        std::cout << test5[i] << " ";
    std::cout << "\n\n";

    sleep(1);

    // 归并排序部分
    std::vector<int> test6;
    srand(time(0));
    generator->getArray(test6);
    std::cout << "------merge test-------\n\n";
    test.resize(test6.size());
    std::copy(test6.begin(), test6.end(), test.begin());
    std::sort(test.begin(), test.end());
    std::cout << "Before sorting, the array is like: \n";
    for(int i = 0; i < test6.size(); ++i)
        std::cout << test6[i] << " ";
    std::cout << "\n";
    // 进行排序
    s->insertion<int>(test6);
    for(int i = 0; i < test6.size(); ++i)
    {
        assert(test6[i] == test[i]);
    }
    std::cout << "After sorting, the array turns out to be: \n";
    for(int i = 0; i < test6.size(); ++i)
        std::cout << test6[i] << " ";
    std::cout << "\n\n";
    
    sleep(1);

    // 堆排序部分
    std::vector<int> test7;
    srand(time(0));
    generator->getArray(test7);
    std::cout << "------heap test-------\n\n";
    test.resize(test7.size());
    std::copy(test7.begin(), test7.end(), test.begin());
    std::sort(test.begin(), test.end());
    std::cout << "Before sorting, the array is like: \n";
    for(int i = 0; i < test7.size(); ++i)
        std::cout << test7[i] << " ";
    std::cout << "\n";
    // 进行排序
    s->heap<int>(test7);
    for(int i = 0; i < test7.size(); ++i)
    {
        assert(test7[i] == test[i]);
    }
    std::cout << "After sorting, the array turns out to be: \n";
    for(int i = 0; i < test7.size(); ++i)
        std::cout << test7[i] << " ";
    std::cout << "\n\n";

    sleep(1);

    // 计数排序部分
    std::vector<int> test8;
    srand(time(0));
    generator->getArray(test8);
    std::cout << "------count test-------\n\n";
    test.resize(test8.size());
    std::copy(test8.begin(), test8.end(), test.begin());
    std::sort(test.begin(), test.end());
    std::cout << "Before sorting, the array is like: \n";
    for(int i = 0; i < test8.size(); ++i)
        std::cout << test8[i] << " ";
    std::cout << "\n";
    // 进行排序
    s->count<int>(test8);
    for(int i = 0; i < test8.size(); ++i)
    {
        assert(test8[i] == test[i]);
    }
    std::cout << "After sorting, the array turns out to be: \n";
    for(int i = 0; i < test8.size(); ++i)
        std::cout << test8[i] << " ";
    std::cout << "\n\n";

    sleep(1);

    // 基数排序部分
    std::vector<int> test9;
    srand(time(0));
    generator->getArray(test9);
    std::cout << "------radix test-------\n\n";
    test.resize(test9.size());
    std::copy(test9.begin(), test9.end(), test.begin());
    std::sort(test.begin(), test.end());
    std::cout << "Before sorting, the array is like: \n";
    for(int i = 0; i < test9.size(); ++i)
        std::cout << test9[i] << " ";
    std::cout << "\n";
    // 进行排序
    s->count<int>(test9);
    for(int i = 0; i < test9.size(); ++i)
    {
        assert(test9[i] == test[i]);
    }
    std::cout << "After sorting, the array turns out to be: \n";
    for(int i = 0; i < test9.size(); ++i)
        std::cout << test9[i] << " ";
    std::cout << "\n\n";

    sleep(1);

    // 桶排序部分
    std::vector<int> test10;
    srand(time(0));
    generator->getArray(test10);
    std::cout << "------bucket test-------\n\n";
    test.resize(test10.size());
    std::copy(test10.begin(), test10.end(), test.begin());
    std::sort(test.begin(), test.end());
    std::cout << "Before sorting, the array is like: \n";
    for(int i = 0; i < test10.size(); ++i)
        std::cout << test10[i] << " ";
    std::cout << "\n";
    // 进行排序
    s->count<int>(test10);
    for(int i = 0; i < test10.size(); ++i)
    {
        assert(test10[i] == test[i]);
    }
    std::cout << "After sorting, the array turns out to be: \n";
    for(int i = 0; i < test10.size(); ++i)
        std::cout << test10[i] << " ";
    std::cout << "\n\n";

    return 0;
}