#include <iostream>
#include <map>
using namespace std;

int h, w;
int a[15][15];
map<int, bool> visited;
int ans = 0;

void dfs(int y, int x){
    visited[a[y][x]] = true;
    if(y == h && x == w) ans++;
    if(y + 1 <= h && !visited[a[y + 1][x]]){
        dfs(y + 1, x);
        visited[a[y + 1][x]] = false;
    }
    if(x + 1 <= w && !visited[a[y][x + 1]]){
        dfs(y, x + 1);
        visited[a[y][x + 1]] = false;
    }
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