#pragma GCC optimize("O3,unroll-loops")
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
 * Optimized O(N) solution to find valid robot configurations.
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

/*
 * Helper function to run and format test cases cleanly
 */
void runTestCase(int testNumber, const vector<int>& input, int expectedOutput) {
    int actualOutput = getValidConfigurations(input);
    cout << "Test Case " << testNumber << ": ";
    
    if (actualOutput == expectedOutput) {
        cout << "[PASS]\n";
    } else {
        cout << "[FAIL]\n";
        cout << "  Expected: " << expectedOutput << "\n";
        cout << "  Actual:   " << actualOutput << "\n";
    }
    
    // Print the array for context (truncated if too long)
    cout << "  Input: [";
    for (size_t i = 0; i < input.size(); ++i) {
        cout << input[i];
        if (i < input.size() - 1) cout << ", ";
        if (i >= 9) { cout << "..."; break; } // Truncate long arrays in output
    }
    cout << "]\n\n";
}

int main() {
    cout << "--- Running Robot Configuration Tests ---\n\n";

    // Test Case 1: Sample from the Image
    // Explanation: k=2 and k=5 are the valid configurations.
    runTestCase(1, {3, 0, 0, 3, 3}, 2);

    // Test Case 2: The Example from the Problem Description
    // Explanation: k=1, k=4, and k=8 are the valid configurations.
    runTestCase(2, {6, 0, 3, 3, 6, 7, 2, 7}, 3);

    // Test Case 3: All Zeros Edge Case
    // Explanation: The only valid configuration is when ALL robots operate (k=N). 
    // If any are in standby, they malfunction because total operating >= 0.
    runTestCase(3, {0, 0, 0, 0}, 1);

    // Test Case 4: All Identical Non-Zero Values
    // Explanation: If thresholds are all 2. 
    // k=0 is valid (all standby, 0 < 2). 
    runTestCase(4, {2, 2, 2}, 1);

    // Test Case 5: Custom Array 
    runTestCase(5, {2, 1, 2, 1}, 2);

    // Test Case 6: Edge Case - Minimum constraints (N=2)
    runTestCase(6, {1, 1}, 1);

    cout << "--- Testing Complete ---\n";
    return 0;
}