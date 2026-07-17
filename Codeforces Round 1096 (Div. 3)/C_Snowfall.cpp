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
        cin>>n;
        vector<int> arr(n);
        for(auto &i:arr){
            cin>>i;
        }
        int start = 0;
        int mid = 0;
        int high = n-1;

        while(mid<=high){
            if(!(arr[mid]%6)){
                swap(arr[mid],arr[start]);
                start++;
                mid++;
            }
            else if(!(arr[mid]%2)){
                mid++;
            }
            else{
                swap(arr[mid],arr[high]);
                high--;
            }
        }

        start = mid;
        high = n-1;

       while (start <= high) {
    if (arr[start] % 3 == 0) {
        swap(arr[start], arr[high]);
        high--;
    } else {
        start++;
    }
}



        // cout<<mid<<high<<endl;

        for(auto i: arr){
            cout<<i<<' ';
        }
        cout<<endl;

    }
    
    return 0;
}