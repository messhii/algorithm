#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> g(110);
bool visited[110];

void dfs(int v){
    visited[v] = true;
    for(int next_v: g[v]){
        if(visited[next_v]) continue;
        dfs(next_v);
    }
}

int main(){
    int ans = 0;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            dfs(i);
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}