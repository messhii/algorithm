#include <iostream>
#include <queue>
using namespace std;

int main(){
    int h, w;
    char s[1010][1010];
    bool visited[1010][1010];
    cin >> h >> w;
    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            cin >> s[i][j];
        }
    }

    int ans = 0;
    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            if(s[i][j] == '.' || visited[i][j]) continue;
            ans++;
            queue<pair<int, int>> que;
            que.push(make_pair(i, j));
            while(!que.empty()){
                auto [x, y] = que.front();
                que.pop();
                for(int x2=x-1; x2<=x+1; x2++){
                    for(int y2=y-1; y2<=y+1; y2++){
                        if(x2 <= 0 || x2 > h || y2 <= 0 || y2 > w) continue;
                        if(s[x2][y2] == '.' || visited[x2][y2]) continue;
                        que.push(make_pair(x2, y2));
                        visited[x2][y2] = true;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}