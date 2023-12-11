#include <iostream>
#include <vector>
using namespace std;

const int INF = 1 << 30;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> dp(n+1, INF), h(n+1);
    for(int i=1; i<=n; i++) cin >> h[i];

    dp[1] = 0;
    for(int i=2; i<=n; i++){
        for(int j=1; j<=k; j++){
            if(i-j <= 0) continue;
            dp[i] = min(dp[i], dp[i-j] + abs(h[i] - h[i-j]));
        }
    }
    cout << dp[n] << endl;
    return 0;
}