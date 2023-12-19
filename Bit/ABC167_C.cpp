#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m, x;
    cin >> n >> m >> x;
    vector<vector<int>> a(n, vector<int>(m));
    vector<int> price(n);
    for(int i=0; i<n; i++){
        cin >> price[i];
        for(int& e: a[i]) cin >> e;
    }
    int ans = 1e9;
    for(int bit=0; bit < (1<<n); bit++){
        vector<int> sum(m);
        int total = 0;
        for(int i=0; i<n; i++){
            if(bit & 1<<i){
                for(int j=0; j<m; j++){
                    sum[j] += a[i][j];
                }
                total += price[i];
            }
        }
        bool flag = true;
        for(int e: sum) if(e < x) flag = false;
        if(flag) ans = min(ans, total);
    }
    if(ans == 1e9) ans = -1;
    cout << ans << endl;
    return 0;
}