#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n+1), b(n+1), c(n+1);
    vector<vector<int>> dp(n+1, vector<int>(3));
    for(int i=1; i<=n; i++) cin >> a[i] >> b[i] >> c[i];
    
    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    for(int i=1; i<=n; i++){
        dp[i][0] = a[i] + max(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = b[i] + max(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = c[i] + max(dp[i-1][0], dp[i-1][1]);
    }
    cout << max(dp[n][0], max(dp[n][1], dp[n][2])) << endl;
    return 0;
}