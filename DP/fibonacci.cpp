#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> dp(n);
    for(int i=1; i<n; i++){
        if(i <= 2) dp[i] = 1;
        else dp[i] = dp[i-1] + dp[i-2];
    }
    for(int a: dp) cout << a << " ";
    cout << endl;
    return 0;
}