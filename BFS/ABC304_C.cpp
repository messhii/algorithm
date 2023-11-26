#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int main(){
    int n, d;
    cin >> n >> d;
    vector<pair<int, int>> place(n + 1);
    vector<bool> visited(n + 1);
    for(int i=1; i<=n; i++){
        int x, y;
        cin >> x >> y;
        place[i] = make_pair(x, y);
    }

    queue<int> que;
    que.push(1);
    visited[1] = true;
    while(!que.empty()){
        int v = que.front();
        que.pop();
        for(int i=1; i<=n; i++){
            if(visited[i]) continue;
            int dist = pow((place[v].first - place[i].first), 2) + pow((place[v].second - place[i].second), 2);
            if(dist <= d * d){
                visited[i] = true;
                que.push(i);
            }            
        }
    }

    for(int i=1; i<=n; i++){
        if(visited[i]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}