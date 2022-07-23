//反转一半数字
class Solution{
    public:
        bool isPalindrome(int x){
            if(x < 0 || (x != 0 && x%10 == 0))
            // 要注意末尾的0
                return false;
            int revertedNum = 0;
            while(revertedNum < x){
                revertedNum = revertedNum*10 + x%10;
                x /= 10;
            }
            return revertedNum == x || x == revertedNum / 10;
        }
};