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
        int n ;
        cin>>n;
        vector<int> arr(n);
        for(auto &i:arr){
            cin>>i;
        }
        vector<pair<int,int>> v;
        int i=0;
        
        while(i<n){
            int j=i+1;
            while(j<n && arr[j] > arr[i]){
                j++;
            }
            v.pb({arr[j-1],j-i}); 
            i=j;
        }
        cout<<v.size()<<endl;
        // int cnt = 0;

        // for(int i=0;i<v.size()-1;i++){
        //     if(v[i].first > v[i+1].first){
        //         cnt++;
        //     }
        // }

        // cout<<cnt<<endl;


    }
    
    return 0;
}