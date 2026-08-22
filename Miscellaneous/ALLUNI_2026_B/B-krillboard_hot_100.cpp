#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Song {
    string name;
    int improve;
    int worsen;

    float expected;

    explicit Song(string name, int improve, int worsen)
        : name{name}, improve{improve}, worsen{worsen} {}
};

// calculates expected score after n weeks given starting score, n weeks, %
// score will get better (decrease by 1), worse (increase by 1)
float calculate_expected(int start, int better, int worse, int n) {
    if (better == worse) { // betters and worses cancel
        return (float)start;
    }

    float score = (float)start;
    float improve = (float)better;
    float worsen = (float)worse;

    for (int i = 0; i < n; i++) {
        score = (improve / 100) * (score - 1) + (worsen / 100) * (score + 1) +
                ((100 - improve - worsen) / 100) * score;
    }
    return score;
}

bool customSort(Song a, Song b) {
    if (a.expected != b.expected) {
        return a.expected < b.expected;
    }
    return a.name < b.name;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num_songs, num_weeks;
    vector<Song> db;

    cin >> num_songs >> num_weeks;

    // take input for songs
    string name;
    int better, worse, start;
    for (int i = 0; i < num_songs; i++) {
        cin >> name >> start >> better >> worse;
        Song *s = new Song{name, better, worse};
        s->expected = calculate_expected(start, better, worse, num_weeks);
        cout << "Expected: " << s->expected << "\n";
        db.push_back(*s);
    }

    sort(db.begin(), db.end(), customSort);
    for (Song song : db) {
        cout << song.name << " ";
    }

    return 0;
}