#include <cmath>
#include <string>

using namespace std;

class Solution {
  public:
    void read_digit(long &num, char &c) {
        int x = ((int)c) - 48;
        num = num * 10 + x;
    }

    int myAtoi(const string &s) {
        // trivial edge case
        if (s.size() == 0) {
            return 0;
        }

        long num = 0;
        bool positive = true, whitespaces_over = false;
        int i = 0; // index
        char c;    // character of string

        while (i < s.size()) {
            c = s[i];

            // encounter letters or '.'
            if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || c == '.') {
                break;
            }

            // signs
            if (c == '-' || c == '+') {
                if (whitespaces_over == true) { // already seen a sign or digit
                    break;
                } else { // first non-whitespace
                    if (c == '-') {
                        positive = false;
                    }
                    whitespaces_over = true;
                    i++;
                    continue;
                }
            }

            // digits
            if ('0' <= c && c <= '9') {
                whitespaces_over = true;
                read_digit(num, c);
            }

            if (c == ' ' && whitespaces_over == true) {
                break;
            }

            // check if we've reached integer limit
            if (num > pow(2, 31) - 1) {
                if (positive) {
                    num = pow(2, 31) - 1;
                    break;
                } else {                         // negative numbers
                    if (num == pow(2, 31) - 1) { // exact edge case
                        i++;
                        continue;
                    } else {
                        num = (-1) * pow(2, 31);
                        break;
                    }
                }
            }
            i++;
        }

        num = (positive ? num : num * (-1));

        return num;
    }
};