// https://www.geeksforgeeks.org/cpp-program-for-inserting-a-node-in-a-linked-list/
#include <iostream>
using namespace std;

class Solution {
    public:
        bool isPalindrome(int x) {
            if (x < 0) {
                return false;
            }
            long y = x;
            long s = 0;
            while (x != 0) {
                int z = x % 10;
                s = (s * 10) + z;
                x /= 10;
            }
            return y == s;
        }
};

int main() {
    Solution solution;
    int x;
    cout << "Input number: ";
    cin >> x ;
    bool result = solution.isPalindrome(x);
    cout << (result ? "True" : "False") << endl;
    return 0;
}
