
using namespace std;

// 约瑟夫环
// 反推，最后只剩一个数字，它的索引就是0
// 之后，每次都补上m个位置，然后模上当时的数组大小i
class Solution {
public:
    int lastRemaining(int n, int m) {
        int res = 0;
        for(int i = 2; i <= n; ++i)
            res = (res+m) % i;
        return res;
    }
};