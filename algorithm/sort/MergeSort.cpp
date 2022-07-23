#include <vector>
#include <iostream>

using namespace std;

//递归版本
void mergeSort(vector<int>& data, vector<int>&temp,int begin,int end) {
    if (begin >= end) return;

    int low1 = begin, high2 = end, mid = begin + (end - begin) / 2;
    int high1 = mid, low2 = mid + 1;

    mergeSort(temp, data, low1, high1);
    mergeSort(temp, data, low2, high2);
    // temp和data互换位置，省去了赋值操作

    int index = low1;
    while (low1 <= high1 && low2 <= high2) {
        temp[index++] = data[low1] < data[low2] ? data[low1++] : data[low2++];
    }
    while (low1 <= high1) {
        temp[index++] = data[low1++];
    }
    while (low2 <= high2) {
        temp[index++] = data[low2++];
    }

}

int main(){
    vector<int> nums = { 5,3,5,6,1,4,9,10,6,2};
    vector<int> temp(nums);
    mergeSort(nums,temp , 0, nums.size() - 1);
    nums.assign(temp.begin(),temp.end());
}


//迭代版本
void mergeSort(vector<int>& data) {
    int len = data.size();
    vector<int> dataTemp(len, 0);
    for (int seg = 1; seg < len; seg += seg) {
        for (int start = 0; start < len; start += seg + seg) {

            int low = start, mid = min(start + seg, len), high = min(start + seg + seg, len);
            int index = low, start1 = low, end1 = mid, start2 = mid, end2 = high;

            while (start1 < end1 && start2 < end2) {
                dataTemp[index++] = data[start1] < data[start2] ? data[start1++] : data[start2++];
            }

            while (start1 < end1) {
                dataTemp[index++] = data[start1++];
            }


            while (start2 < end2) {
                dataTemp[index++] = data[start2++];
            }

        }
        swap(data, dataTemp);
    }

    for (auto a : data)
        cout << a << " ";    
}
