#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    // Store pairs of {value, original_array_index}
    vector<pair<long long, int>> elements;
    elements.reserve(3 * n);
    
    for (int i = 0; i < n; ++i) {
        long long a, b, c;
        cin >> a >> b >> c;
        elements.push_back({a, i});
        elements.push_back({b, i});
        elements.push_back({c, i});
    }
    
    // Sort all 3N elements by their value
    sort(elements.begin(), elements.end());
    
    // Sliding window tracking
    vector<int> counts(n, 0);
    int unique_count = 0;
    long long min_diff = 2e18; // Initialize with a very large number
    int left = 0;
    
    // Expand the window with the right pointer
    for (int right = 0; right < elements.size(); ++right) {
        int right_idx = elements[right].second;
        
        // If this is the first time we are seeing this row index in our window
        if (counts[right_idx] == 0) {
            unique_count++;
        }
        counts[right_idx]++;
        
        // When our window contains at least one element from every row
        while (unique_count == n) {
            // Calculate the current difference
            long long current_diff = elements[right].first - elements[left].first;
            min_diff = min(min_diff, current_diff);
            
            // Try to shrink the window from the left to find a smaller valid range
            int left_idx = elements[left].second;
            counts[left_idx]--;
            
            // If removing the left element breaks our valid window
            if (counts[left_idx] == 0) {
                unique_count--;
            }
            left++; // Move left pointer forward
        }
    }
    
    cout << min_diff << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}