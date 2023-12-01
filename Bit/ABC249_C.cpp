#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<string> s(n);
    for(auto& s2: s) cin >> s2;

    int ans = 0;
    for(int bit=0; bit < (1<<n); bit++){
        int alpha_cnt[26] = {};
        for(int i=0; i<n; i++){
            if(bit & (1<<i)){
                for(auto e: s[i]) alpha_cnt[e - 'a']++;
            }
        }
        int cnt = 0;
        for(int i=0; i<26; i++){
            if(alpha_cnt[i] == k) cnt++;
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}