
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> directory;
vector<int> sub_total;
// could also iterate backwards to implement a dp rather than DFS
// solution to avoid stack overflow
int count_subs(int id) {
    if (directory[id].empty()) {
        sub_total[id] = 0;
        return 0;
    }

    int subs = 0;
    for (int employee : directory[id]) {
        subs += count_subs(employee);
        subs++;
    }
    sub_total[id] = subs;
    return subs;
}

int main() {
    // input
    int total;
    cin >> total;

    // ind = employee number, vec = subordinates
    directory.resize(total + 1);
    sub_total.resize(total + 1);
    int boss;
    for (int i = 2; i <= total; i++) {
        cin >> boss;
        directory[boss].push_back(i);
    }

    count_subs(1);
    int j;
    for (j = 1; j < directory.size() - 1; j++) {
        // check input accuracy
        // cout << "\nEmployee number: " << j
        //      << " has the following subordinates: " << "\n";
        // for (int sub : directory[j]) {
        //     cout << sub << '\t';
        // }
        cout << sub_total[j] << " ";
    }
    cout << sub_total[j];

    return 0;
}

// Given the structure of a company, your task is to calculate for each employee
// the number of their subordinates.

// Input
// The first input line has an integer n: the number of employees. The employees
// are numbered 1,2,\dots,n, and employee 1 is the general director of the
// company. After this, there are n-1 integers: for each employee 2,3,\dots,n
// their direct boss in the company.

// Output
// Print n integers: for each employee 1,2,\dots,n the number of their
// subordinates.