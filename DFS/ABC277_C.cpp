#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<int, vector<int>> g;
map<int, bool> visited;
int ans = 1;

void dfs(int v){
    visited[v] = true;
    ans = max(ans, v);
    for(int next_v: g[v]){
        if(visited[next_v]) continue;
        dfs(next_v);
    }
}

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}