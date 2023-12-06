#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int main(){
    int n, d;
    cin >> n >> d;
    vector<int> x(n + 1), y(n + 1);
    vector<bool> visited(n + 1);
    for(int i=1; i<=n; i++) cin >> x[i] >> y[i];    
    
    queue<pair<int, int>> que;
    visited[1] = true;
    que.push(pair(x[1], y[1]));
    while(!que.empty()){
        auto v = que.front();
        que.pop();
        for(int i=1; i<=n; i++){
            int dist = pow(v.first - x[i], 2) + pow(v.second - y[i], 2);
            if(visited[i] || dist > d * d) continue;
            visited[i] = true;
            que.push(make_pair(x[i], y[i]));
        }
    }
    for(int i=1; i<=n; i++){
        if(visited[i]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}