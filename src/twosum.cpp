#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:

    // 碝т皚いㄢ计单 target ま
    vector<int> twoSum(vector<int>& nums, int target) {

        /*
            unordered_map ノㄓ纗
            
            key   = 计セō
            value = 赣计┮ index
            
            ㄒ
            nums = {2,7,11,15}

            numMap ず甧
            {
                2 : 0,
                7 : 1
            }
        */
        unordered_map<int, int> numMap;


        // 眔皚
        int n = nums.size();


        // 硋ǐ砐 nums
        for(int i = 0; i < n; i++){

            /*
                Two Sum み阀├

                安砞
                nums[i] + ? = target

                ê或
                ? = target - nums[i]

                硂 ? 碞暗 complement (干计)

                ㄒ
                nums[i] = 7
                target = 9

                complement = 9 - 7 = 2

                и惠璶絋粄ぇ玡琌筁 2
            */
            int complement = target - nums[i];


            /*
                count() ノㄓ浪琩 unordered_map 琌琘 key

                狦
                numMap 柑Τ complement

                ぇ玡竒笿筁皌癸计
            */
            if(numMap.count(complement)){


                /*
                    肚ㄢ计竚

                    numMap[complement]
                    -> ぇ玡计 index

                    i
                    -> 瞷计 index
                */
                return {numMap[complement], i};
            }


            /*
                狦⊿Τт皌癸

                盢ヘ玡计 map

                key   = nums[i]
                value = i

                よ獽计琩高
            */
            numMap[nums[i]] = i;
        }


        /*
            狦俱皚禲Ч常⊿Τт氮

            肚 vector
        */
        return {};
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