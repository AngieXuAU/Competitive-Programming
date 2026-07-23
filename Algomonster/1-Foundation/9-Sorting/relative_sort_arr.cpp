
#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_set>
#include <vector>

std::vector<int> relative_sort_array(std::vector<int> &arr1,
                                     std::vector<int> &arr2) {
    std::vector<int> head, tail;
    std::unordered_set<int> seen;
    std::map<int, int> order;

    // convert arr1 to map: key = val, value = og index
    for (int i = 0; i < arr1.size(); i++) {
        int x = arr1[i];
        if (seen.count(x)) {
            continue;
        }

        seen.insert(x);
        order[x] = i;
    }

    // construct the head and tail of arr2
    for (int x : arr2) {
        if (seen.count(x)) {
            head.push_back(x);
        } else {
            tail.push_back(x);
        }
    }
    // then sort the head
    std::sort(head.begin(), head.end(), [&order](const auto &a, const auto &b) {
        return (order[a] < order[b]);
    });

    // and sort the tail
    std::sort(tail.begin(), tail.end(),
              [](const auto &a, const auto &b) { return (a < b); });

    // if a and b not in then return a < b, elif a or b not in seen then return
    // the one in seen, else prioritise the one with the lower index
    // question: does c++ treat this stuff 'symmetrically' ie.
    head.insert(head.end(), tail.begin(), tail.end());

    return head;
}

void pprint(std::vector<int> result) {
    for (int i = 0; i < result.size() - 1; i++) {
        std::cout << result[i] << ", ";
    }
    std::cout << result[result.size() - 1] << std::endl;
}

int main() {
    std::vector<int> arr1 = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19};
    std::vector<int> arr2 = {2, 1, 4, 3, 9, 6};

    std::vector<int> result = relative_sort_array(arr1, arr2);

    pprint(arr1);

    return 0;
}