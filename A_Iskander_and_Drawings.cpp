#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using vi = vector<int>;
using vll = vector<long long>;

const int MOD = 1e9 + 7;
const int INF = 1e9;
const long long LINF = 1e18;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

#ifdef LOCAL
    #define debug(x) cerr << #x << " = " << (x) << "\n"
#else
    #define debug(x)
#endif



int main() {
    FAST_IO;
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int ans = 0;
        int temp = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                ans = max(ans, temp);
                temp = 0;
            } else {
                temp++;
            }
        }
        ans = max(ans, temp);
        cout << (ans/2) + (ans%2) << "\n";
    }
    
    return 0;
}