#include <cmath> // Required for ceil function
#include <vector>

using namespace std;

int minimumRateToEatBananas(vector<int> v, int h) {
    long long s = 1;
    long long e = 1000000000; // Initial search range
    int n = v.size();
    int ans = -1; // Initialize the answer to -1

    while (s <= e) {
        long long mid = s + (e - s) / 2; // Calculate the middle rate
        long long count = 0;

        // Count how many hours it takes to eat all bananas at the given rate
        for (int i = 0; i < n; i++) {
            count += ceil((v[i] * 1.0) / mid);
        }

        // If the total hours required is less than or equal to h,
        // update the answer and search in the higher rate range
        if (count <= h) {
            ans = mid;
            e = mid -1;
        }
        // If the total hours required is greater than h,
        // search in the lower rate range
        else {
            s = mid + 1;
        }
    }
    return ans; // Return the minimum rate
}
