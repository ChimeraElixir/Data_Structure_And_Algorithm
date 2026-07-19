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
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            sum += x;
        }
        cout << (sum % 4 == 0 ? "YES" : "NO") << '\n';
        // int n ;
        // cin>> n ;
        // vector<int> arr(n);
        // vector<int> plus;
        // vector<int> minus;
        // int cnt_plus=0;
        // int cnt_minus=0;
        // for(auto &i:arr){
        //     cin>>i;
        // }
        // int sum = 0;

        // for(auto i:arr){
        //     sum+=i;
        // }

        // if(sum==0){
        //     cout<<"YES"<<endl;
        //     continue;
        // }

        // // if(sum == 4 || sum == -4){
        // //     cout<<"YES"<<endl;
        // //     continue;
        // // }


        // for(auto i :arr){
        //     if(i==1){
        //         cnt_plus++;
        //     }
        //     else{
        //         if(cnt_plus>0){
        //             plus.pb(cnt_plus);
        //             cnt_plus = 0;
        //         }
        //     }
        // }
        // if(cnt_plus > 0) {
        //     plus.pb(cnt_plus);
        // }

        // for(auto i :arr){
        //     if(i==-1){
        //         cnt_minus--;
        //     }
        //     else{
        //         if(cnt_minus<0){
        //             minus.pb(cnt_minus);
        //             cnt_minus = 0;
        //         }
        //     }
        // }
        // if(cnt_minus < 0) {
        //     minus.pb(cnt_minus);
        // }

        // // for(auto x : minus) cout << x << " ";
        // //     cout << endl;

        // // cout<<abs(sum)%4<<endl;

        

        // if(abs(sum)%4 == 0){
        //     if(sum > 0){
        //         auto it = std::find(plus.begin(), plus.end(), sum/2);  
        //         if (it != plus.end()){
        //             cout<<"YES"<<endl;
        //         }
        //         else{
        //             cout<<"NO"<<endl;
        //         }
        //     }
        //     else{
        //         auto it = std::find(minus.begin(), minus.end(), (sum)/2);  
        //         if (it != minus.end()){
        //             cout<<"YES"<<endl;
        //         }
        //         else{
        //             cout<<"NO"<<endl;
        //         }
        //     }
        // }
        // else{
        //     cout<<"NO"<<endl;
        // }
    }
    
    return 0;
}