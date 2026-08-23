#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num_riffs, num_notes, threshold;

    cin >> num_riffs >> num_notes >> threshold;

    unordered_map<string, int> songs;
    unordered_set<string> seen;
    int over = 0;

    for (int i = 0; i < num_riffs; i++) {
        string song = "";
        // cin >> song;
        // char base = song[0];
        // for (int j = 0; j < num_notes; j++) {
        //     song[j] -= base;
        //     // cout << "received: " << c << "\n";
        // }

        char c, base2;
        cin >> base2;
        for (int j = 1; j < num_notes; j++) {
            cin >> c;
            song += c - base2;
        }

        songs[song]++;

        if (songs[song] >= threshold) {
            if (seen.count(song)) {
                continue;
            } else {
                over++;
                seen.insert(song);
            }
        }
    }

    cout << over;
    return 0;
}