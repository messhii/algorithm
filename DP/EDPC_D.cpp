#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main(){
    int N, W;
    cin >> N >> W;
    vector<vector<ll>> dp(N+1, vector<ll>(W+1));
    vector<int> w(N+1), v(N+1);
    for(int i=1; i<=N; i++) cin >> w[i] >> v[i];

    for(int i=0; i<=W; i++) dp[0][i] = 0;
    for(int i=0; i<=N; i++) dp[i][0] = 0;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=W; j++){
            if(w[i] <= j){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - w[i]] + v[i]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[N][W] << endl;
    return 0;
}