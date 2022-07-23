class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = x;
        while(left <= right){
            int mid = (left+right) / 2;
            if((long)mid*mid == x)
                return mid;
            else if((long)mid*mid < x){
//这里的类型转换需要注意，(long)(mid*mid)则无法转化
                if((long)(mid+1)*(mid+1) > x)
                    return mid;
                else
                    left = mid+1;
            }else{
                right = mid-1;
            }   
        }
        return -1;
    }
};