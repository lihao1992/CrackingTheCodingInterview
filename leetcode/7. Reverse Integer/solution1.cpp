# include <iostream>
# include <math.h>
# include <climits>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        
        int res = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (res > INT_MAX/10 || (res == INT_MAX/10 && pop > 7)) return 0; // overflow
            if (res < INT_MIN/10 || (res == INT_MIN/10 && pop < -8)) return 0; // overflow
            res = res * 10 + pop;
        }
        
        return res;
    }
};

int main () {

    int num1 = 321;
    int num2 = -230;

    Solution solution;

    int res1 = solution.reverse(num1);
    int res2 = solution.reverse(num2);

    cout << "res1 :" << res1 << endl;
    cout << "res2 :" << res2 << endl;

    return 0;
}