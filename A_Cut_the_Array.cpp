#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin>>T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n+1);
        for (int i = 1; i <= n; ++i) cin>>a[i];
        vector<int> pref(n+1, 0);
        for (int i = 1; i <= n; ++i) pref[i] = (pref[i-1] + a[i]) % 3;
        
        if (pref[n] % 3 != 0) {
            cout <<0<<" "<<0<<endl;
            continue;
        }
        bool found = false;
        int ansL = 0, ansR = 0;
        for (int l = 1; l <= n-2 && !found; l++) {
            for (int r = l+1; r <= n-1 && !found; r++) {
                int s1 = pref[l];
                int s2 = (pref[r] - pref[l]) % 3; 
                if (s2 < 0) s2 += 3;
                int s3 = (pref[n] - pref[r]) % 3; 
                if (s3 < 0) s3 += 3;
                bool allS= (s1 == s2 && s2 == s3);
                bool allD= (s1 != s2 && s1 != s3 && s2 != s3);
                if (allS || allD) {
                    ansL = l; 
                    ansR = r; 
                    found = true;
                }
            }
        }
        if (found) cout << ansL << " " << ansR <<endl;
        else cout <<0<<" "<<0<<endl;
    }
    return 0;
}
