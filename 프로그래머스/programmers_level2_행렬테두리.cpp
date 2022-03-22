#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int MAP[101][101] = { 0 };

int rotate(int x1, int y1, int x2, int y2) {
    int minNum;
    int temp = MAP[x1][y1];
    minNum = temp;
    // 오른쪽
    for (int i = x1; i < x2; i++)
    {
        minNum = min(minNum, MAP[i][y1]);
        MAP[i][y1] = MAP[i + 1][y1];
    }
    // 아래
    for (int i = y1; i < y2; i++)
    {
        minNum = min(minNum, MAP[x2][i]);
        MAP[x2][i] = MAP[x2][i + 1];
    }
    // 왼쪽
    for (int i = x2; i > x1; i--)
    {
        minNum = min(minNum, MAP[i][y2]);
        MAP[i][y2] = MAP[i - 1][y2];
    }
    // 위
    for (int i = y2; i > y1; i--)
    {
        minNum = min(minNum, MAP[x1][i]);
        MAP[x1][i] = MAP[x1][i - 1];
    }
    MAP[x1][y1 + 1] = temp;
    return minNum;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    int t = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            MAP[i][j] = t++;
        }
    }

    for (int i = 0; i < queries.size(); i++) {
        int d[4] = { 0 };
        for (int j = 0; j < 4; j++) {
            d[j] = queries[i][j];
        }
        answer.push_back(rotate(d[0] - 1, d[1] - 1, d[2] - 1, d[3] - 1));
    }

    return answer;
}
