#pragma GCC optimize("O3,unroll-loops")
#include <iostream>
#include <vector>

using namespace std;

/*
 * Complete the 'getValidConfigurations' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY coordinationThreshold as parameter.
 */
int getValidConfigurations(vector<int> coordinationThreshold) {
    long long n = coordinationThreshold.size();
    
    // Frequency array to count occurrences of each threshold
    vector<long long> count(n + 1, 0);
    for (long long t : coordinationThreshold) {
        if (t <= n) {
            count[t]++;
        }
    }
    
    long long valid_configs = 0;
    long long less_than_k = 0;
    
    // Test all possible global configurations where exactly 'k' robots operate
    for (long long k = 0; k <= n; ++k) {
        // A valid state requires exactly k robots to have threshold < k
        // AND zero robots to have threshold == k.
        if (less_than_k == k && count[k] == 0) {
            valid_configs++;
        }
        
        // Add current threshold frequency to prefix sum for the next k
        if (k <= n) {
            less_than_k += count[k];
        }
    }
    
    return valid_configs;
}

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    // Read the number of elements
    if (cin >> n) {
        vector<int> coordinationThreshold(n);
        
        // Read the array elements
        for (int i = 0; i < n; ++i) {
            cin >> coordinationThreshold[i];
        }

        // Execute the optimal algorithm and print the result
        int result = getValidConfigurations(coordinationThreshold);
        cout << result << "\n";
    }

    return 0;
}