#include <vector>
#include <iostream>

using namespace std;

void heapify(vector<int>& nums, int n, int i)
//对有一定顺序的堆，
//当前第i个结点取根左右的最大值（这个操作称heapfiy）
{
    int l = i * 2 + 1, r = i * 2 + 2;
    int max = i;
    if (l<n && nums[l]>nums[max])
        max = l;
    if (r<n && nums[r]>nums[max])
        max = r;
    if (max != i)
    {
        swap(nums[max], nums[i]);
        heapify(nums, n, max);
    }
}

void heapify_build(vector<int>& nums, int n)
// 建立大顶堆，从树的倒数第二层倒数第一个结点开始，对它每个结点进行heapify操作，然后向上走
// 堆最后一个节点索引是n-1，所以倒数第二层倒数第一个索引是((n-1)-1)/2
{
    int temp = (n - 2) / 2;
    for (int i = temp; i >= 0; i--)
        heapify(nums, n, i);

    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";
    cout << endl;
}

void heapify_sort(vector<int>& nums, int n)
//建立大根堆之后，每次交换最后一个结点和根节点（最大值），
//对交换后的根节点继续进行heapify（此时堆的最后一位是最大值，因此不用管他，n变为n-1）
{
    heapify_build(nums, n);
    for (int i = 0; i < n; i++)
    {
        swap(nums.front(), nums[n - i - 1]);
        heapify(nums, n - i - 1, 0);
    }
}