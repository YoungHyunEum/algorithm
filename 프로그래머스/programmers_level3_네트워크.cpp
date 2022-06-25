#include <string>
#include <vector>
#include <queue>
using namespace std;

int visited[200];

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i = 0; i < n; i++){
        if(visited[i] == 0) {
            answer++;
            queue<int> q;
            q.push(i);
            visited[i] = 1;

            while(!q.empty()){
                int now = q.front();
                q.pop();

                for(int j = 0; j < n; j++){
                    int to = computers[now][j];
                    if(visited[j] == 1 || i == j || to == 0) continue;
                    q.push(j);
                    visited[j] = 1;
                }
            }
        }
    }
    
    return answer;
}
