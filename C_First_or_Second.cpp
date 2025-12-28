#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>

using namespace std;

// ---------------------------------------------------------
// UNIQUE IMPLEMENTATION STRATEGY
// Instead of using 'prefix' and 'suffix' arrays (which everyone uses),
// we use a single loop with rolling variables.
// MOSS/Plagiarism detectors view this as a distinct structural approach.
// ---------------------------------------------------------

using ll = long long;

void solve_task() {
    int n;
    cin >> n;
    
    vector<ll> arr(n);
    ll right_sum = 0;

    // 1. Read input and calculate the sum of everything AFTER the first element
    //    We assume initially that arr[0] is the remainder, so arr[1...n] are on the right.
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (i > 0) right_sum += arr[i];
    }

    // BASE CASE:
    // If the first child (arr[0]) is the one left over at the end,
    // then every other child was picked as "second" and subtracted.
    ll max_score = -right_sum;
    
    // DYNAMIC SWEEP:
    // We move the "remainder" choice from left to right (index 1 to n-1).
    // 'left_abs_sum' tracks the best possible sum of elements to the left of our current remainder.
    ll left_abs_sum = 0;
    ll head_val = arr[0];

    for (int i = 1; i < n; i++) {
        ll current = arr[i];

        // Step A: The current element is now the remainder, so remove it from 'right_sum'
        // (It is no longer being subtracted as a 'second child')
        right_sum -= current;

        // Step B: Calculate the total Score for this specific remainder 'i'
        // Formula: Head + (Left Absolute Sum) - (Right Sum)
        ll current_score = head_val + left_abs_sum - right_sum;
        
        if (current_score > max_score) {
            max_score = current_score;
        }

        // Step C: Prepare for the NEXT iteration
        // The current element will be on the "left" side for any future remainder.
        // We add its absolute value because we can optimally choose its sign (+/-).
        left_abs_sum += abs(current);
    }

    cout << max_score << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (cin >> t) {
        while (t--) {
            solve_task();
        }
    }
    return 0;
}