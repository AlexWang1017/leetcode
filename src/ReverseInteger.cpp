#include <iostream>
#include <vector>
using namespace std;


class Solution{        //Time : o(logn)   Space: (1)

public:
    int reverse(int x){
        int r = 0;

        while (x != 0){
            int digit = x % 10; // 程计
            if (r > INT_MAX / 10 || (r == INT_MAX / 10 && digit > 7))    //INT_MAX =  2147483647
            return 0;

            if (r < INT_MIN / 10 || (r == INT_MIN / 10 && digit < -8))   //INT_MIN = -2147483648
                return 0;
            
            r = r * 10 + digit; 
            x /= 10; //彼程计
        }
        return r;
    }
};


void runTest(int input, int expected)
{
    Solution sol;

    int result = sol.reverse(input);

    cout << "Input: " << input << endl;
    cout << "Output: " << result << endl;
    cout << "Expected: " << expected << endl;

    if (result == expected)
        cout << "PASS\n";
    else
        cout << "FAIL\n";

    cout << "-------------------\n";
}


void runAllTests()
{
    runTest(123, 321);

    runTest(-123, -321);

    runTest(120, 21);

    runTest(0, 0);

    // overflow case
    runTest(1534236469, 0);

    runTest(-2147483648, 0);
}


int main(){
    runAllTests();

    cin.get();
    return 0;
}