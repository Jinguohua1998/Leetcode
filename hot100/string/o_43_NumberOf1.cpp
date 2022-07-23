class Solution {
public:
    int countDigitOne(int n) {
        unsigned int digit = 1, res = 0;
//digit是10的n次方，每次循环中*10，res是最终要返回的结果
//用unsigned int：表示范围更大
        int high = n/10, cur = n % 10, low = 0;
//cur是遍历的那一位数，high是高于该位的数字，low是低于该位的数字 

        while(high != 0 || cur != 0){
//如果high==0&&cur==0则跳出循环
            if(cur == 0)
                res += high * digit;
            else if(cur == 1)
                res += high * digit + low + 1;//注意 ： 这里是low+1
            else
                res += (high + 1) * digit;
                
            low += cur * digit;
            cur = high % 10;
            high /= 10;
            digit *= 10;
       
        }
        return res;
    }
};

