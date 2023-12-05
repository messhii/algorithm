#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    vector<bool> visited(n + 1);

    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    queue<int> que;
    int ans = 0;
    for(int i=1; i<=n; i++){
        if(visited[i]) continue;
        ans++;
        que.push(i);
        while(!que.empty()){
            int v = que.front();
            que.pop();
            for(auto next_v: g[v]){
                if(visited[next_v]) continue;
                visited[next_v] = true;
                que.push(next_v);
            }
        }
    }
    cout << ans << endl;
    return 0;
}