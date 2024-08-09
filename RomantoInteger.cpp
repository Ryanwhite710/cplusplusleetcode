#include <iostream>
#include <map>

using namespace std;

class Solution {
    public:
        int romanToInt(string s) {
            map<char,int>roman_map;
            roman_map = {
                {'I', 1 },
                {'V', 5 },
                {'X', 10 },
                {'L', 50 },
                {'C', 100 },
                {'D', 500 },
                {'M', 1000 }
            };
            int t = 0;
            for (int i = 0; i < s.size(); i++ ){
                char m = s[i];
                
                if (roman_map.find(m) != roman_map.end()) {
                    int v = roman_map[m];
                    if (i + 1 < s.size() && roman_map[s[i]] < roman_map[s[i+1]]) {
                        t-=v;
                    } else {
                        t += v;
                    }
                    
                    cout << "m: " << m << "\n";
                    cout << "map: " << v << "\n" << "total: " << t << "\n";
            }
        }
        return t;
        }
};


int main() {
    Solution solution;

    string s1 = "III";
    int result1 = solution.romanToInt(s1);
    cout <<" Result 1: "<< result1 << "\n";
    string s2 = "LVIII";
    int result2 = solution.romanToInt(s2);
    cout <<" Result 2: "<< result2 << "\n";
    string s3 = "MCMXCIV";
    int result3 = solution.romanToInt(s3);
    cout <<" Result 3: "<< result3 << "\n";

    return 0;
}