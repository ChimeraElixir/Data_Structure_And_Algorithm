#include <bits/stdc++.h>

using namespace std;

// Fast I/O
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);

// Type aliases
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using vi = vector<int>;
using vll = vector<long long>;

// Constants
const int MOD = 1e9 + 7;
const int INF = 1e9;
const long long LINF = 1e18;

// Utility macros
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

// Debug (only in local)
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
        int a, b;
        cin >> a >> b;
    cout << ((a % b == 0) ? "YES\n" : "NO\n");    }
    
    return 0;
}