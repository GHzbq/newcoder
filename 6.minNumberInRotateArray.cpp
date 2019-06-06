// 旋转数组的最小数字
// nowcoder: https://www.nowcoder.com/practice/9f3231a991af4f55b95579b44b7a01ba?tpId=13&tqId=11159&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking&tPage=1
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        /**
         * 先来搞一个取巧的办法呗，把这个数组排个序，然后返回 rotateArray[0] 不就好了嘛
         * 但是考虑一个效率问题，即使用效率较高的快速排序，时间复杂度也是 O(nlgn)
         * 
         */
#if 0
        sort(rotateArray.begin(),rotateArray.end());
        return rotateArray[0];
#endif
        /**
         * 考虑本题的特性，其实这个数组就是两部分已经有序的数组嘛，只要找到那个突变的点就可以了
         * 或者直接理解为一趟选择排序，找最小的那个元素就好了
         */
        // NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
        if (rotateArray.empty())
        {
            return 0;
        }
        // 一遍遍历找到那个最小的元素
        int min = rotateArray[0];
        for(size_t i = 0; i < rotateArray.size(); ++i)
        {
            if (rotateArray[i] < min)
            {
                min = rotateArray[i];
            }
        }
        
        return min;
        // 目前不知道会不会有其他更神奇的操作，我真的想不到了，毕竟不是完全有序的，遍历一遍数组就得O(n)的时间复杂度
    }
};
