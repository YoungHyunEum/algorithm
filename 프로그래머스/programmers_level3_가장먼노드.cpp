#include <string>
#include <vector>
#include <queue>
using namespace std;

struct Node{
    int to;
    int dist;
};

vector<int> v[20001];
int answer = 0;

void bfs(int n){
    vector<int> used(n+1, 0);
    int max_dist = 0;
    
    queue<Node> q;
    q.push({1, 0});
    used[1] = 1;
    
    while(!q.empty()){
        Node now = q.front();
        q.pop();
        
        if(now.dist == max_dist) answer++;
        else if(now.dist > max_dist) {
            max_dist = now.dist;
            answer = 1;
        }
        
        for(int i = 0; i < v[now.to].size(); i++){
            int t = v[now.to][i];
            if(used[t] == 1) continue;
            q.push({t, now.dist + 1});
            used[t] = 1;
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    
    for(int i = 0; i < edge.size(); i++){
        v[edge[i][0]].push_back(edge[i][1]);
        v[edge[i][1]].push_back(edge[i][0]);
    }
    
    bfs(n);
    
    return answer;
}
