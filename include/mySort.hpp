// 主程序使用的sorting函数所在的头文件，注意CMakeLists.txt文件中要
// 包含这个目录进行编译: (${PROJECT_SOURCE_DIR}/include)
#include <iostream>
#include <vector>
#include <random>
#include <functional>
#include <algorithm>

namespace mySort {
    // 排序器类，用可排序的元素种类进行区分
    class mySorter
    {
    public:
        // 回顾，构造函数不能作为虚函数，原因是虚函数在工作时需要用到RTTI运行时信息
        // 排序器类不会用到任何的自身数据，只需要提供不同排序算法的函数接口，因而只用默认构造函数即可
        mySorter() = default;
        // 析构函数也只用默认即可，这里用上虚函数机制是预备将来可能的排序器功能拓展，不过大概率用不到
        virtual ~mySorter() = default;

        // 以下为几种主要的排序函数的接口

        // 选择排序
        template<typename T>
        void selection(std::vector<T>&);

        // 冒泡排序
        template<typename T>
        void bubble(std::vector<T>&);

        // 插入排序
        template<typename T>
        void insertion(std::vector<T>&);

        // 希尔排序
        template<typename T>
        void shell(std::vector<T>&);

        // 快速排序
        template<typename T>
        void quick(std::vector<T>&);

        // 归并排序
        template<typename T>
        void merge(std::vector<T>&);

        // 堆排序
        template<typename T>
        void heap(std::vector<T>&);

        // 计数排序
        template<typename T>
        void count(std::vector<T>&);

        // 基数排序
        template<typename T>
        void radix(std::vector<T>&);

        // 桶排序
        template<typename T>
        void bucket(std::vector<T>&);
    };


// 选择排序的具体实现
/**
 * @param v 要排序的数组
 */
/*
    一句话总结选择排序：
    每次把未排序部分中最小的一个值放到未排序部分的头部
*/
template<typename T>
void mySort::mySorter::selection(std::vector<T>& v) 
{
    size_t n = v.size();
    // 选择出每个位置上应放置的数字
    for(unsigned int i = 0; i < n; ++i) 
    {
        // 从还未排好序的子段进行最小值的选取
        unsigned int minimum = i;
        for(unsigned int j = i; j < n; ++j)
        {   
            // 如果找到一个更小的值，就对最小值下标进行更新
            if(v[j] < v[minimum])
                minimum = j;
        }
        // 如果最小的不是当前正在检查的待填位上的数字，就进行交换，保证当前位置是未排序序列中的最小值
        if(minimum != i)
            std::swap(v[minimum], v[i]);
    }
    // 循环结束后，整个数组就是已排序的了
}

// 冒泡排序的具体实现
/**
 * @param v 要排序的数组
 */
/*
    一句话总结冒泡排序：
    每次把未排序部分中最大的数不断冒泡，最终放到未排序部分的末尾(可以看成是选择排序的反向操作)
*/
template<typename T>
void mySort::mySorter::bubble(std::vector<T>& v)
{
    size_t n = v.size();
    for(unsigned int i = n-1; i >= 0; --i)
    {
        // 优化操作：如果当前"未排序"部分已经没有任何交换，说明该部分已经有序了，可以直接结束排序
        bool swaped = false;
        for(unsigned int j = 0; j < i; ++j)
        {
            // 把大数不断向后"冒泡"
            if(v[j] > v[j+1]) {
                std::swap(v[j], v[j+1]);
                swaped = true;
            }
        }
        if(!swaped) break;
    }
}

// 插入排序
/**
 * @param v 待排序的数组
 */
/*
    一句话总结插入排序：
    每轮排序将未排序的部分的第一个元素插入到已排序部分中的正确位置
    (启发自打牌的时候整理手牌的流程)
    (常用作一些高级排序算法的候补优化算法)
*/
template<typename T>
void mySort::mySorter::insertion(std::vector<T>& v)
{
    size_t n = v.size();
    T val;
    for(int i = 0; i < n; ++i)
    {
        // std::cout << i << std::endl;
        // 用val记录当前位置上的元素
        val = v[i];
        // 倒序遍历整个有序部分
        int j = i-1;
        // 如果当前有序部分的最大值是大于当前位置的元素，就"腾出"一个位置
        // 即把大于的数往后移动一位
        while(j >= 0 && v[j] > val) 
        {
            v[j+1] = v[j];
            --j;
        }
        // 结束条件：要么是j == -1，要么是v[j] <= val
        // j == -1代表当前元素应该放到有序序列的最前面
        // 否则当前元素应该放到j的下一个位置上
        // 二者可以合并写，即v[j+1] = val
        // std::cout << i << std::endl;

        v[j+1] = val;
    }
}

// 希尔排序实现
/**
 * @param v 待排序的数组
 */
/*
    一句话概括希尔排序：
    本质是一种分治的插入排序，按不是1的间隔分割原数组，按更小的子序列进行排序，最后才按已经部分有序的数组进行原版的插入排序
*/
template<typename T>
void mySorter::shell(std::vector<T>& v)
{
    size_t n = v.size();
    // 确定初始的跨度值gap
    unsigned int gap = n/2;
    while(gap > 0)
    {
        // 进行一次插入排序
        for(int i = gap; i < n; ++i)
        {
            // 空出当前数的位置
            T val = v[i];
            int j = i-gap;
            while(j >= 0 && v[j] > val) {
                v[j+gap] = v[j];
                j -= gap;
            }
            v[j+gap] = val;
        }
        gap /= 2;
    }
}

// 快速排序实现(附带随机化)
/**
 * @param v 待排序的数组
 */
/* 
    一句话概括快速排序：
    理解了很简单，就是每次选一个值放到最后有序数组中它的位置上，维护这个位置左侧的元素严格不大于它，右侧的元素严格大于它，之后递归地对左右两侧再进行快排
*/
template<typename T>
void mySorter::quick(std::vector<T>& v)
{
    std::function<int(std::vector<T>&, int, int, int)> partition 
    = [](std::vector<T>& v, int left, int right, int pivot) {
        std::swap(v[right], v[pivot]);
        int i = left-1;
        for(int j = left; j < right; ++j)
        {
            if(v[j] <= v[right])
                std::swap(v[++i], v[j]);
        }
        std::swap(v[++i], v[right]);
        return i;
    };
    std::function<void(std::vector<T>&, int, int)> quickSort 
    = [&](std::vector<T>& v, int left, int right) {
        if(left >= right) return;
        int pivot = rand() % (right-left+1)+left;
        int pos = partition(v, left, right, pivot);
        quickSort(v, left, pos);
        quickSort(v, pos+1, right);
        return;
    };
    quickSort(v, 0, v.size()-1);
}

// 归并排序实现
/**
 * @param v 待排序的数组
 */
/*
    一句话概括归并排序：
    本质和快排一样都是分治，但是归并是先排序左右两端，再进行合并，不像快排是先确定一个分界值再递归排序
*/
template<typename T>
void mySorter::merge(std::vector<T>& v)
{
    std::function<void(std::vector<T>&, int, int, int)> combine
    = [](std::vector<T>& v, int left, int right, int mid) {
        // right只存v的右半边
        std::vector<T> rHalf(v.begin()+mid+1, v.end());
        // i指针和j指针分别指向全数组和右半数组的末尾
        // k指针指向要排序的部分的末尾
        int k = right, i = mid, j = right-mid-1;
        while(i >= 0 && j >= 0) 
        {
            if(v[i] > rHalf[j])
            {
                v[k--] = v[i--];
            }
            else
            {
                v[k--] = rHalf[j--];
            }
        }
        while(i >= 0)
        {
            v[k--] = v[i--];
        }
        while(j >= 0)
        {
            v[k--] = rHalf[j--];
        }
    };
    std::function<void(std::vector<T>&, int, int)> mergeSort
    = [&](std::vector<T>& v, int left, int right) {
        if(left >= right) return;
        // 归并中点
        int mid = ((right-left)>>1)+left;
        mergeSort(v, left, mid);
        mergeSort(v, mid+1, right);
        combine(v, left, right, mid);
    };

    mergeSort(v, 0, v.size()-1);
}

// 堆排序实现
/**
 * @param v 待排序的数组
 */
/*
    一句话总结堆排序：
    emm，感觉一句话总结不太出来，堆这东西里面还有优先队列的内容，还是到代码内部去理解吧。。。
*/
template<typename T>
void mySorter::heap(std::vector<T>& v)
{
    // 获取左右孩子节点的辅助函数(内联)
    std::function<int(int)> lChild 
    = [](int i) {
        return 2*i+1;
    };
    std::function<int(int)> rChild
    = [](int i) {
        return 2*i+2;
    };

    // 额外需要一个堆大小参数
    std::function<void(std::vector<T>&, int, int)> max_heapify
    = [&](std::vector<T>& v, int i, int heap_size) {
        if(i >= heap_size)
            perror("max_heapify");
        int left = lChild(i), right = rChild(i);
        int maximum = i;
        if(left < heap_size && v[left] > v[maximum]) 
        {
            maximum = left;
        }
        if(right < heap_size && v[right] > v[maximum])
        {
            maximum = right;
        }
        if(maximum != i) 
        {
            std::swap(v[i], v[maximum]);
            // 递归维护最大堆性质
            max_heapify(v, maximum, heap_size);
        }
    };

    // 依据给定的数组建立最大堆
    std::function<void(std::vector<T>&, int)> build_maxHeap
    = [&](std::vector<int>& v, int heap_size) {
        for(int i = heap_size/2-1; i >= 0; --i)
        {
            max_heapify(v, i, heap_size);
        }
    };

    std::function<void(std::vector<T>&, int)> heap_sort
    = [&](std::vector<T>& v, int heap_size) {
        // 利用循环，每次把堆顶的最大值放到堆尾的下一个位置
        // 并相应动态更新合法的最大堆大小
        for(int i = heap_size-1; i > 0; --i)
        {   
            // 把当前堆中最大的值和堆中最后一个元素交换
            std::swap(v[0], v[i]);
            // 堆大小要先-1
            max_heapify(v, 0, --heap_size);
        }
    };

    build_maxHeap(v, v.size());
    heap_sort(v, v.size());
    return;
}

// 计数排序实现
/**
 * @param v 待排序的数组
 */
/*
    一句话总结计数排序：
    线性排序算法，问题在于如果排序的值域很大，那么排序需要的计数数组也会很大
    如果要排序的对象和数组下标不匹配(比如出现了负数，或者本身是字符串，需要额外对数据本身做预处理(归一化))
*/
template<typename T>
void mySorter::count(std::vector<T>& v)
{
    // 分别记录取值范围的上下界
    T maximum = v[0];
    T minimum = v[0];
    size_t n = v.size();
    for(unsigned int i = 0; i < n; ++i) 
    {
        if(v[i] > maximum)
            maximum = v[i];
        if(v[i] < minimum)
            minimum = v[i];
    }
    T d = maximum - minimum;
    std::vector<int> counts(d+1, 0);
    for(unsigned int i = 0; i < n; ++i)
    {
        ++counts[v[i] - minimum];
    }
    for(unsigned int i = 1; i < d+1; ++i)
    {
        counts[i] = counts[i] + counts[i-1];
    }
    std::vector<T> sorted(v.begin(), v.end());
    for(int i = n-1; i >= 0; --i)
    {
        int idx = counts[v[i] - minimum]-1;
        sorted[idx] = v[i];
        --counts[v[i]-minimum]; 
    }
    std::copy(sorted.begin(), sorted.begin()+n, v.begin());
}

// 基数排序实现
/**
 * @param v 待排序的数组
 */
/*
    一句话总结基数排序：
    同样是线性排序算法，比计数排序多了一个数位个数常数因子，不过影响不大，依赖底层的单个数位排序算法(硬性要求是这个底层排序必须是稳定的)
    稳定排序算法：两个相同的值进行排序，原来在前面的值，排序结束后还在前面
*/
template<typename T>
void mySorter::radix(std::vector<T>& v)
{
    // 这里适配的是数字类型(特别的，整型；如果要排序的元素是字符串类型，digits应该代表最长的字符串的长度，相应的求解方法也应该更改)
    T maximum = *std::max_element(v.begin(), v.end());
    int maxdigit = 0;
    while(maximum)
    {
        maximum /= 10;
        ++maxdigit;
    }
    size_t n = v.size();
    // 每个位计数排序一轮
    for(int i = 1; i <= maxdigit; i *= 10)
    {
        int ma = v[0] / i % 10;
        int mi = v[0] / i % 10;
        for(int j = 0; j < n; ++j)
        {
            if(v[j] / i % 10 > ma)
                ma = v[j] / i % 10;
            if(v[j] / i % 10 < mi)
                mi = v[j] / i % 10;
        }
        int d = ma - mi;
        std::vector<int> counts(d+1, 0); 
        for(int j = 0; j < n; ++j)
        {
            ++counts[v[j] / i % 10 - mi];
        }
        for(unsigned int j = 1; j < d+1; ++j)
        {
            counts[j] += counts[j-1];
        }
        std::vector<T> sorted(v.begin(), v.end());
        for(int j = n-1; j >= 0; --j)
        {
            int idx = counts[v[j] / i % 10]-1;
            sorted[idx] = v[j] / i % 10;
            --counts[v[j] / i % 10 - mi];
        }
        std::copy(sorted.begin(), sorted.begin()+n, v.begin());
    }
}

// 桶排序实现
/**
 * @param v 待排序的数组
 */
/*
    一句话总结桶排序：
    本质上是把原数组的取值区间进行切分，切分成若干个等范围的桶，把原数组中的数放入按值放入对应的区间中，再进行桶内排序
    最后依次取出每个桶内的值即为有序数组
*/
template<typename T>
void mySorter::bucket(std::vector<T>& v)
{
    size_t n = v.size();
    T maximum = *std::max_element(v.begin(), v.end());
    T minimum = *std::min_element(v.begin(), v.end());
    // 分10个桶
    const int bucketcnt = 10;
    std::vector<std::vector<int>> buckets(bucketcnt, std::vector<int>());
    // 求出每个桶的覆盖区间大小
    int blockSize = (maximum-minimum+1) / bucketcnt + bucketcnt;
    for(int i = 0; i < n; ++i)
    {
        // 分桶
        int idx = v[i] / blockSize;
        buckets[idx].emplace_back(v[i]);
    }
    for(int i = 0; i < bucketcnt; ++i)
    {
        // 对每一个桶进行插入排序
        insertion(buckets[i]);
    }
    std::vector<T> sorted;
    for(int i = 0; i < bucketcnt; ++i)
    {
        for(int j = 0; j < buckets[i].size(); ++j)
        {
            sorted.emplace_back(buckets[i][j]);
        }
    }
    std::copy(sorted.begin(), sorted.end(), v.begin());
}
}
