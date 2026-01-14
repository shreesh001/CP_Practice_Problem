#include <bits/stdc++.h>
using namespace std;

int main() {

    int N, K;
    cin >> N >> K;

    vector<long long> C(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }
    for (int i = 0; i < N; i++) {
        long long tmp;
        cin >> tmp;
    }

    sort(C.begin(), C.end(), greater<long long>());

    long long ans = 0;
    for (int i = 0; i < K; i++) {
        ans += C[i];
    }

    cout << ans << "\n";
    return 0;
}
