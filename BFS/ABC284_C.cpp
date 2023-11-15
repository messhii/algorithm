#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int n, m;
    queue<int> q;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    vector<bool> visited(n + 1);

    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = 0;
    for(int i=1; i<=n; i++){
        if(visited[i]) continue;
        ans++;
        q.push(i);
        while(!q.empty()){
            int v = q.front();
            q.pop();
            for(int next_v: g[v]){
                if(visited[next_v]) continue;
                q.push(next_v);
                visited[next_v] = true;
            }
        }
    }
    cout << ans << endl;
    return 0;
}