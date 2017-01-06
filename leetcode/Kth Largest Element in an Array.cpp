#include <vector>
#include <iostream>

using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(vector<int>& nums, int p, int r, int k) {
    int x = nums[r];
    int i = p;
    int j = p;
    for(; j < r; ++j)
        if(nums[j] > x) {
            if(i != j)
                swap(&nums[i], &nums[j]);
            i++;
        }
    swap(&nums[i], &nums[j]);
    int g = -1;
    if (i + 1 == k)
        return i;
    else if (i + 1 > k)
    {
        g = partition(nums, p, i-1, k);
        if(g >= 0) return g;
    } else if (i + 1 < k) {
        g = partition(nums, i+1, r, k);
        if(g >= 0) return g;
    }
    return -1;
}



int findKthLargest(vector<int>& nums, int k) {
    return nums[partition(nums, 0, nums.size()-1, k)];
}
//
//int main() {
//    vector<int> nums = {3, 2, 1, 5, 6, 4};
//    int num = findKthLargest(nums, 2);
//    return 0;
//}
