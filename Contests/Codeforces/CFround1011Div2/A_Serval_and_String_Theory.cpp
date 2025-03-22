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
    ll n,k;cin>>n>>k;
    string s;
    cin>>s;
    set<char>ss;
    rep(i,n){
        ss.insert(s[i]);
    }
    if(ss.size()==1){
        cout<<"NO"<<en;
        return;
    }
    if(k==0){
        int i=0,j=n-1;
        while(i<j&&s[i]==s[j]){
            i++;
            j--;
        }
        if(s[i]>=s[j]){
            cout<<"NO"<<en;return;
        }
    }
    cout<<"YES"<<en;
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