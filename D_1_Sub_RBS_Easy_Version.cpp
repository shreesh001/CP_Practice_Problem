#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    // Check if s contains "(())"
    bool has_nested = (s.find("(())") != string::npos);
    
    // Check if s contains ")("
    bool has_peak = (s.find(")(") != string::npos);

    // If both patterns exist, we can always remove 2 characters 
    // to form a better regular bracket sequence.
    if (has_nested && has_peak) {
        cout << n - 2 << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    int t;
    cin >> t; 
    while (t--) solve();
    return 0;
}