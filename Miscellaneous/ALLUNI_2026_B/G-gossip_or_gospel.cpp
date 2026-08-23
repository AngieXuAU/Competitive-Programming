#include <iostream>
#include <unordered_map>
// #include <unordered_set>

using namespace std;

struct Person {
    string name;
    string truth;
    int num_lies = {};

    vector<string> unsures;

    explicit Person(string name, string truth = "", int num_lies = 0)
        : name{name}, truth{truth}, num_lies{num_lies} {}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num_msgs;
    cin >> num_msgs;

    unordered_map<string, Person> all_names;

    int gog;
    string name, statement;
    for (int i = 0; i < num_msgs; i++) {
        cin >> gog >> name >> statement;

        // new person if needed
        if (!all_names.count(name)) {
            all_names[name] = Person{name};
        }
        Person &person = all_names[name];

        // situation 1: new truth established
        if (gog == 2) {
            person.truth = statement;
            continue;
        }

        // situation 2: new statement contradicts truth
        if (person.truth != "" && statement != person.truth) {
            person.num_lies++;
            continue;
        }

        // situation 3: unsure of truth, new statement emerges
        if (person.truth == "") {
            person.unsures.push_back(statement);
        }
    }

    // left with 2 cases
    // 1 - truth established but saved rumours inputted before truth
    // 2 - unsure of truth, only have rumours rn

    for (auto pair : all_names) {
        Person &person = pair.second;

        if (person.truth != "") { // truth established
            for (string rumour : person.unsures) {
                if (rumour != person.truth) {
                    person.num_lies++;
                }
            }
        } else { // unsure of truth
            unordered_map<string, int> state_count;
            for (string rumour : person.unsures) {
                state_count.at(rumour)++;
            }
        }

        // TODO: lowkenuinely realised that instead of what I'm doing at the
        // moment, I should
        // create a map key = statement, value = count if truth
        // unestablished, find max count --> establish truth using truth, same
        // algo for every person to find number of lies
    }
    return 0;
}