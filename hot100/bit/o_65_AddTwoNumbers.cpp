class Solution{
    public:
        int add(int a, int b){
            int sum, carry;
            do{
                sum = a ^ b;
                carry = unsigned(a & b) << 1;
//c++中的位运算要用unsigned
                a = sum;
                b = carry;
            }while(carry != 0);
            return sum;
        }
        
};

class Solution2{
    public:
        int add(int a, int b){
            while(b != 0){
                int c = unsigned(a & b) << 1;
//c++中的位运算要用unsigned
                a ^= b;
// a表示的是做加法之后不考虑进位的表示，c表示进位与位
                b = c;
            }
            return a;
        }
        
};