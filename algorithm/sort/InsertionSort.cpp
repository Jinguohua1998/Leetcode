#include <vector>

using namespace std;

// 也可以用swap写
void insertionSort(vector<int>& a, int n) {//{ 9,1,5,6,2,3 }
    for (int i = 1; i < n; ++i) {
        if (a[i] < a[i - 1]) {   //若第i个元素大于i-1元素，直接插入。小于的话，移动有序表后插入
            int j = i - 1;
            int x = a[i];     //复制为哨兵，即存储待排序元素
            //a[i] = a[i - 1];           //先后移一个元素，可以不要这一句，跟循环里面的功能重复了
            while (j >= 0 && x < a[j]) {   //查找在有序表的插入位置,还必须要保证j是>=0的 因为a[j]要合法
                a[j + 1] = a[j];
                j--;     //元素后移
            }
            a[j + 1] = x;     //插入到正确位置
        }
    }
}