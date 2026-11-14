#include <queue>
#include <utility>
#include <vector>

using namespace std;
using Entry = std::pair<int, int>;
// first: index in points
// second: distance

struct Compare {
    bool operator()(const Entry &a, const Entry &b) const {
        return a.second < b.second; // min-heap (or '<' for max-heap)
    }
};

class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
        std::priority_queue<Entry, std::vector<Entry>, Compare> pq;

        // iterate through points
        for (int i = 0; i < points.size(); i++) {
            // calculate distance
            int d = points[i][0] * points[i][0] + points[i][1] * points[i][1];

            // add to queue and remove if needed
            pq.push({i, d});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        // construct the solution
        vector<vector<int>> results;
        while (!pq.empty()) {
            Entry tmp = pq.top();
            results.push_back(points.at(tmp.first));
            pq.pop();
        }

        return results;
    }
};