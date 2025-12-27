#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<long long> C(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }

    // Stability array exists but is irrelevant for scoring
    for (int i = 0; i < N; i++) {
        long long tmp;
        cin >> tmp; // S[i], ignored
    }

    sort(C.begin(), C.end(), greater<long long>());

    long long ans = 0;
    for (int i = 0; i < K; i++) {
        ans += C[i];
    }

    cout << ans << "\n";
    return 0;
}
