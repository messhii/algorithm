#include <iostream>
using namespace std;

int h, w;
char s[1010][1010];
bool visited[1010][1010];

void dfs(int x, int y){
    visited[x][y] = true;
    for(int i=-1; i<=1; i++){
        for(int j=-1; j<=1; j++){
            if(x + i >= 1 && x + i <= h && y + j >= 1 && y + j <= w && !visited[x + i][y + j] && s[x + i][y + j] == '#'){
                dfs(x + i, y + j);
            }
        }
    }
}

int main(){
    cin >> h >> w;
    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            cin >> s[i][j];
        }
    }
    int ans = 0;
    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            if(!visited[i][j] && s[i][j] == '#'){
                dfs(i, j);
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}