/**
 * 矩形覆盖
 * https://www.nowcoder.com/practice/72a5a919508a4251859fb2cfb987a0e6?tpId=13&tqId=11163&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
 * */

class Solution {
public:
    int rectCover(int number) {
        if(number < 1)
        {
            return 0;
        }
        
        if(number == 1 || number == 2)
        {
            return number;
        }
        
        
        return rectCover(number - 1) + rectCover(number - 2);
    }
};
