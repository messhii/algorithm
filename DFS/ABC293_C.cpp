#include <iostream>
#include <map>
using namespace std;

int h, w;
int a[15][15];
map<int, bool> visited;
int ans = 0;

void dfs(int x, int y){
    visited[a[x][y]] = true;
    if(x == h && y == w) ans++;
    if(x + 1 <= h && !visited[a[x + 1][y]]){
        dfs(x + 1, y);
    }
    if(y + 1 <= w && !visited[a[x][y + 1]]){
        dfs(x, y + 1);
    }
    visited[a[x][y]] = false;
}

int main(){
    cin >> h >> w;
    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            cin >> a[i][j];
        }
    }
    dfs(1, 1);
    cout << ans << endl;
    return 0;
}