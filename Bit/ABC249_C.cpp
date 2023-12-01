#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<string> s(n);
    for(auto& s2: s) cin >> s2;

    int ans = 0;
    for(int bit=0; bit < (1<<n); bit++){
        map<char, int> mp;
        for(int i=0; i<n; i++){
            if(bit & (1<<i)){
                for(auto e: s[i]) mp[e]++;
            }
        }
        int cnt = 0;
        for(auto [key, value]: mp){
            if(value == k) cnt++;
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}