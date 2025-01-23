#include <iostream>
using namespace std;

int solve(int n, int k)
{
    if (n < k)
    {
        return n;
    }
    int count = 0;
    int divide;

    while (n)
    {

        int low = 0;
        int high = n;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            long power = pow(k, mid);
            if (power <= n)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        long power1 = pow(k, low);
        long power2 = pow(k, high);

        if (abs(power1 - n) <= abs(power2 - n))
        {
            divide = power1;
        }
        else
        {
            divide = power2;
        }

        n = n - divide;
        count++;
    }

    return count;
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        cout << solve(n, k) << "\n";
    }
}