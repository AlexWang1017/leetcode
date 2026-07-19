#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        int n = nums.size();

        for(int i=0; i<n; i++){
            int complement = target - nums[i];
            if(numMap.count(complement)){
                return {numMap[complement],i};
            }
            numMap[nums[i]] = i;
        }
        return{};
    }
};

void test(vector<int> nums, int target){
    Solution sol;
    vector<int> ans = sol.twoSum(nums,target);

    cout << "nums = { ";
    for(int x : nums)
        cout << x << " ";
    cout << "}, target = " << target << endl;

    if(ans.empty()){
        cout << "No solution\n";
    }
    else{
        cout << "Result: [" << ans[0] << ", " << ans[1] << "]\n";
    }
}

int main(){
    test({2, 7, 11, 15}, 9);
    test({3, 2, 4}, 6);
    test({3, 3}, 6);
    test({1, 5, 3, 8}, 9);
    test({1, 2, 3}, 10);
    
    cin.get();
    return 0;
}