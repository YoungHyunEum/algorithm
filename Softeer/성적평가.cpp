#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int score;
    int order;
};

bool comp(Node a, Node b) {
    if (a.score > b.score) return true;
    else if (a.score <= b.score) return false;
}

int N;
vector<Node> competition[3];
vector<Node> total_score;
int ranking[3][100001];
int total_rank[100001];

void find_ranking() {
    for (int tc = 0; tc < 3; tc++) {
        int temp_score = competition[tc][0].score;
        int temp_rank = 1;
        ranking[tc][competition[tc][0].order] = temp_rank;

        for (int i = 1; i < N; i++) {
            if (competition[tc][i].score == temp_score) {
                ranking[tc][competition[tc][i].order] = temp_rank;
            }
            else {
                temp_score = competition[tc][i].score;
                temp_rank = i + 1;
                ranking[tc][competition[tc][i].order] = temp_rank;
            }
        }
    }

    int temp_score = total_score[0].score;
    int temp_rank = 1;
    total_rank[total_score[0].order] = temp_rank;

    for (int j = 1; j < N; j++) {
        if (total_score[j].score == temp_score) {
            total_rank[total_score[j].order] = temp_rank;
        }
        else {
            temp_score = total_score[j].score;
            temp_rank = j + 1;
            total_rank[total_score[j].order] = temp_rank;
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < N; j++) {
            int s;
            cin >> s;
            competition[i].push_back({ s, j });
            if (total_score.size() <= j) {
                total_score.push_back({s, j});
            }
            else {
                total_score[j].score += s;
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        sort(competition[i].begin(), competition[i].end(), comp);
    }
    sort(total_score.begin(), total_score.end(), comp);
    
    find_ranking();

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < N; j++) {
            cout << ranking[i][j] << " ";
        }
        cout << "\n";
    }

    for (int i = 0; i < N; i++) {
        cout << total_rank[i] << " ";
    }

    return 0;
}
