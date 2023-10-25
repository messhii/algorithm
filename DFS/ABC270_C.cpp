#include <iostream>
#include <vector>
using namespace std;

int n, x, y;
vector<vector<int>> g;
vector<bool> visited;
vector<int> ans;
bool stop = false;

void dfs(int v){
    visited[v] = true;
    if(!stop) ans.push_back(v);
    if(v == y) stop = true;
    for(int v_next: g[v]){
        if(!visited[v_next]){
            dfs(v_next);
        }
    }
    if(!stop) ans.pop_back();
}

int main(){
    cin >> n >> x >> y;
    g.resize(n+1);
    visited.resize(n+1);
    for(int i=0; i<n-1; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(x);
    for(int e: ans) cout << e << " ";
    cout << endl;    
    return 0;
}