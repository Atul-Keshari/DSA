#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define pb push_back
#define ll long long
#define vl vector<ll>
#define pl pair<ll,ll>
#define vpl vector<pair<ll,ll>>
#define vvl vector<vector<ll>>
#define rep(i,n) for(ll i=0;i<n;i++)
#define repp(i,k,n) for(ll i=k;i<n;i++)
#define en "\n"
void solve(){
    ll n;
    cin>>n;vl a(n);
    rep(i,n)cin>>a[i];
    if(a[0]==0&&a[n-1]==0){
        cout<<3<<en;
        cout<<n-1<<" "<<n<<en;
        cout<<1<<" "<<n-2<<en;
        cout<<1<<" "<<2<<en;
    }else if(a[0]==0){
        cout<<2<<en;
        cout<<1<<" "<<n-1<<en;
        cout<<1<<" "<<2<<en;
    }else if(a[n-1]==0){
        cout<<2<<en;
        cout<<2<<" "<<n<<en;
        cout<<1<<" "<<2<<en;
    }else{
        ll fl=false;
        repp(i,1,n-1){
            if(a[i]==0){
                fl=true;
                break;
            }
        }
        if(fl){
            cout<<2<<en;
            cout<<2<<" "<<n<<en<<1<<" "<<2<<en;
        }else{
            cout<<3<<en;
            cout<<n-1<<" "<<n<<en;
            cout<<2<<" "<<n-1<<en;
            cout<<1<<" "<<2<<en;
        }
    }
}
int main()
{

    fast;
    int t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}