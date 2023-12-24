#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(m);
    for(int i=0; i<m; i++){
        int c;
        cin >> c;
        a[i].resize(c);
        for(auto &e: a[i]) cin >> e;
    }

    int ans = 0;
    for(int bit=1; bit < (1<<m); bit++){
        vector<bool> visited(n+1);
        int x_cnt = 0;
        for(int i=0; i<m; i++){
            if(bit & (1 << i)){
                for(auto e: a[i]){
                    if(visited[e]) continue;
                    visited[e] = true;
                    x_cnt++;
                }
            }
        }
        if(x_cnt == n) ans++;
    }
    cout << ans << endl;
    return 0;
}