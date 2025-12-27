#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if(!(cin >> t)) return 0;
    while(t--){
        long long x; cin >> x;
        long long p = 10;
        long long ans = -1;
        while(p <= 1000000000LL){
            long long y = p - 1 - x;
            if(y > 0 && y >= p/10 && y < 1000000000LL){
                ans = y;
                break;
            }
            p *= 10;
        }
        if(ans == -1) ans = 1; 
        cout << ans << '\n';
    }
    return 0;
}
