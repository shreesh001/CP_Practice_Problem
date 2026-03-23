#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Pass A by const reference to avoid O(N) copy overhead
long long solve(int N, const vector<int>& A, long long K) {
    long long max_h = 0;
    
    // Only inner elements can be peaks (indices 1 to N-2)
    for (int i = 1; i < N - 1; i++) {
        long long cur = A[i];
        long long L = A[i - 1];
        long long R = A[i + 1];
        
        // The absolute optimal strategy is to dump all K operations into raising the peak.
        // Check if doing so successfully makes it strictly taller than both neighbors.
        if (cur + K > L && cur + K > R) {
            max_h = max(max_h, cur + K);
        }
    }
    
    return max_h;
}

int main() {
    // Fast I/O for strict time limits
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    // Read the number of test cases
    if (cin >> T) {
        while (T--) {
            int N;
            cin >> N;
            
            // Read the elevation array
            vector<int> A(N);
            for (int i = 0; i < N; i++) {
                cin >> A[i];
            }
            
            long long K;
            cin >> K;
            
            // Solve and print the result
            cout << solve(N, A, K) << "\n";
        }
    }
    return 0;
}