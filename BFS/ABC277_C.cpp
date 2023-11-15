#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int n;
    queue<int> que;
    map<int, vector<int>> g;
    map<int, bool> visited;
    cin >> n;
    
    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    que.push(1);
    int ans = 1;
    while(!que.empty()){
        int v = que.front();
        que.pop();        
        for(auto next_v: g[v]){
            if(visited[next_v]) continue;
            visited[next_v] = true;
            que.push(next_v);
            ans = max(ans, next_v);
        }
    }
    cout << ans << endl;
    return 0;
}