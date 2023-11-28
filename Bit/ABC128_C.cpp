#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> s(m);
    vector<int> p(m);
    for(int i=0; i<m; i++){
        int k;
        cin >> k;
        for(int j=0; j<k; j++){
            int a;
            cin >> a;
            s[i].push_back(--a);
        }
    }
    for(int& e: p) cin >> e;

    int ans = 0;
    for(int bit=0; bit < (1<<n); bit++){
        bool okay = true;
        for(int i=0; i<m; i++){
            int cnt_on = 0;
            for(auto v: s[i]){
                if(bit & (1 << v)) cnt_on++;
            }
            if(cnt_on % 2 != p[i]) okay = false;
        }
        if(okay) ans++;
    }
    cout << ans << endl;
    return 0;
}