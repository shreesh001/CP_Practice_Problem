#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> x(n);
        for(int i=0;i<n;i++) cin >> x[i];

        if(n == 1){
            cout << 0 << '\n';
            continue;
        }

        ll cur = 0;
        int segments = 1;
        int sign = 1;

        for(int i=0;i+1<n;i++){
            ll d = x[i+1] - x[i];
            cur += sign * d;

            if(cur <= 0){
                segments++;
                cur = d;
                sign = 1;
            }else{
                sign = -sign;
            }
        }

        cout << n - segments << '\n';
    }
    return 0;
}
