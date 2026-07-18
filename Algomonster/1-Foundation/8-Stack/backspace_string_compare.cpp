#include <iostream>
#include <string>

int get_next_valid_index(const std::string &str, int index) {
    int counter = 0;

    while (index >= 0) {
        if (str[index] == '#') {
            counter++;
            index--;
        } else {
            if (counter > 0) {
                counter--;
                index--;
            } else {
                break;
            }
        }
    }

    return index;
}

bool backspace_string_compare(std::string &s, std::string &t) {
    int sptr = get_next_valid_index(s, s.size() - 1),
        tptr = get_next_valid_index(t, t.size() - 1);
    char x, y;

    while (sptr >= 0 || tptr >= 0) {
        if ((sptr < 0 && tptr >= 0) || (sptr >= 0 && tptr < 0)) {
            return false;
        }

        sptr = get_next_valid_index(s, sptr);
        tptr = get_next_valid_index(t, tptr);

        x = s.at(sptr);
        y = t.at(tptr);

        if (x != y) {
            return false;
        }

        sptr--;
        tptr--;
    }
    return true;
}

int main() {
    std::string s = "a##c", t = "#a#c";
    std::cout << backspace_string_compare(s, t);
    return 0;
}