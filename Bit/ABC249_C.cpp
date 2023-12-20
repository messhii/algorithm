#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<string> s(n);
    for(string& e: s) cin >> e;

    int ans = 0;
    for(int bit=0; bit<(1<<n); bit++){
        vector<int> cnt(26);
        for(int i=0; i<n; i++){
            if(bit & (1<<i)){
                for(char c: s[i]) cnt[c - 'a']++;
            }
        }
        int k_cnt = 0;
        for(int e: cnt){
            if(e == k) k_cnt++;
        }
        ans = max(ans, k_cnt);
    }
    cout << ans << endl;
    return 0;
}