#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> g;
bool visited[(int)(1e9+10)];
int ans = 0;

void dfs(int v, int sum){
    visited[v] = true;
    ans = max(ans, sum);
    for(int next_v: g[v]){
        if(visited[next_v]) continue;
        dfs(next_v, sum + next_v - v);
    }
    visited[v] = false;
}

int main(){
    cin >> n;
    g.resize(n + 1);

    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}