#include <string>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    int romanToInt(string s) {
        long result = 0;
        int slow = 0, fast = 1;

        unordered_map<char, int> val = {{'I', 1},   {'V', 5},   {'X', 10},
                                        {'L', 50},  {'C', 100}, {'D', 500},
                                        {'M', 1000}};

        int tmp;
        while (fast <= s.size()) {
            int f = val[s[fast]], sl = val[s[slow]];

            // cout << "fast: " << f << " | " << "slow: " << sl << "\n";
            if (f <= sl) {
                tmp = sl;
            } else {
                tmp = f - sl;
                slow++, fast++;
            }
            result += tmp;
            slow++, fast++;
            // cout << result << "\n";
        }

        slow++;
        if (slow < s.size()) {
            result += val[s[slow]];
        }

        return result;
    }
};