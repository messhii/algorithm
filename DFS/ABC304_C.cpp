#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> g;
vector<bool> visited;

void dfs(int v){
    visited[v] = true;
    for(auto next_v: g[v]){
        if(visited[next_v]) continue;
        dfs(next_v);
    }
}

int main(){
    int n, d;
    cin >> n >> d;
    vector<int> x(n + 1), y(n + 1);
    g.resize(n + 1);
    visited.resize(n + 1);
    for(int i=1; i<=n; i++){
        cin >> x[i] >> y[i];
    }
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            if((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) <= d * d){
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    dfs(1);
    for(int i=1; i<=n; i++){
        if(visited[i]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}