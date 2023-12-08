#include <iostream>
using namespace std;

int n, m;
int dist[15][15];
bool visited[15];
int ans = 0;

void dfs(int v, int sum){
    visited[v] = true;
    ans = max(ans, sum);
    for(int v2=1; v2<=n; v2++){
        if(!visited[v2] && dist[v][v2] > 0){
            dfs(v2, sum + dist[v][v2]);
        }
    }
    visited[v] = false;
}

int main(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = dist[b][a] = c;
    }
    for(int i=1; i<=n; i++){
        dfs(i, 0);
    }
    cout << ans << endl;
    return 0;
}