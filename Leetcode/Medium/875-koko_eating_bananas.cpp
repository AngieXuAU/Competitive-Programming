#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool feasible(vector<int> &piles, int k, int h) {
    long hours_required = 0;
    for (int pile : piles) {
        hours_required += pile / k;
        if (pile % k != 0) {
            hours_required++;
        }

        if (hours_required > h) {
            return false;
        }
    }
    return (hours_required <= (long)h);
}

// int getMax(vector<int> &vec) {
//     int max = vec[0];
//     for (int i = 1; i < vec.size(); i++) {
//         if (vec[i] > max)
//             max = vec[i];
//     }
//     return max;
// }

int minEatingSpeed(vector<int> &piles, int h) {
    int min = 1;

    sort(piles.begin(), piles.end(),
         [](const auto &a, const auto &b) { return a < b; });

    // int max = getMax(piles);
    int max = piles[piles.size() - 1];
    int mid;
    int min_feasible = max;

    while (min <= max) {
        mid = min + (max - min) / 2;

        // cout << "checking\tmin: " << min << "\tmax: " << max << "\tmid: " <<
        // mid
        //      << "\n";
        if (feasible(piles, mid, h)) {
            max = mid - 1;
            min_feasible = mid;
            // cout << mid << " feasible\n";
        } else {
            min = mid + 1;
        }
    }

    return min_feasible;
}

int main() {
    vector<int> piles = {1, 4, 3, 2};
    // cout << minEatingSpeed(piles, 9) << "\n";
    // piles = {25, 10, 23, 4};
    // cout << minEatingSpeed(piles, 4) << "\n";
    // piles = {332484035, 524908576, 855865114, 632922376, 222257295,
    // 690155293,
    //          112677673, 679580077, 337406589, 290818316, 877337160,
    //          901728858, 679284947, 688210097, 692137887, 718203285,
    //          629455728, 941802184};
    // cout << minEatingSpeed(piles, 823855818) << "\n";
    // piles = {30, 11, 23, 4, 20};
    // cout << minEatingSpeed(piles, 6) << "\n";
    piles = {805306368, 805306368, 805306368};
    cout << minEatingSpeed(piles, 1000000000) << "\n";

    cout << feasible(piles, 1, 1000000000) << "\n";
}