class Solution {
public:
    int mySqrt(int x) {
        if(!x)
            return 0;
        if(x < 4)
            return 1;
        int left = 0;
        int right = x / 2;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if((long)mid * mid == x)    // 类型转换需要注意
                return mid;
            else if((long)mid * mid > x)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return right;
    }
};