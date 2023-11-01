#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<pair<int, int>>> g(15);
int visited[15];
int ans = 0;

void dfs(int v, int sum){
    visited[v] = true;
    ans = max(ans, sum);
    for(auto [v_next, dis]: g[v]){
        if(visited[v_next]) continue;
        dfs(v_next, sum + dis);
    }
    visited[v] = false;
}

int main(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back(make_pair(b, c));
        g[b].push_back(make_pair(a, c));
    }
    for(int i=1; i<=n; i++){
        dfs(i, 0);
    }
    cout << ans << endl;
    return 0;
}