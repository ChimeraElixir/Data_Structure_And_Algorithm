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
        int n,x,y;
        cin>>n>>x>>y;
        vector<int> arr(n);
        bool flag =true;

        for(int i = 0 ; i < n ; i++){
            if(arr[i] != i+1 ){
                flag = false;
            }
        }
        if(flag){
            cout<<"YES"<<endl;
            continue;
        }
        
        vector<int> exps(4);
        exps[0] = arr[0] % x;
        exps[1] = arr[1] % x;
        exps[2] = arr[0] % y;
        exps[3] = arr[1] % y;

        vector<bool> flags(4,true);

        int flag2 = false;
        for(int i=0;i<n;i+=x){
            if(exps[0] != arr[i]%x){
                flags[0]= false;
            }
        }
        for(int i=1;i<n;i+=x){
            if(exps[1] != arr[i]%x){
                flags[1]= false;
            }
        }
        for(int i=0;i<n;i+=x){
            if(exps[2] != arr[i]%x){
                flags[0]= false;
            }
        }
        for(int i=1;i<n;i+=x){
            if(exps[3] != arr[i]%x){
                flags[1]= false;
            }
        }

        if(flags[0] && flags[1]){
            cout<<"YES"<<endl;
            continue;
        }
        if(flags[2] && flags[3]){
            cout<<"YES"<<endl;
            continue;
        }
        cout<<"NO"<<endl;

    }
    
    return 0;
}