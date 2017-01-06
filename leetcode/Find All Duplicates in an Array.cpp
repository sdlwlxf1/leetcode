#include <iostream>
#include <vector>

using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
    vector<int> res;
    int i = 0;
    while(i < nums.size()) {
        if (nums[i] != nums[nums[i]-1])
            swap(nums[i], nums[nums[i]-1]);
        else
            i++;
    }
    for(i = 0; i < nums.size(); i++){
        if (nums[i] != i + 1)
            res.push_back(nums[i]);
    }
    return res;
}

int main() {
    vector<int> nums = {4,3,2,7,8,2,3,1};
    vector<int> res = findDuplicates(nums);
    return 0;
}
