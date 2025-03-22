#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define pb push_back
#define ll long long
#define vl vector<ll>
#define pl pair<ll,ll>
#define vpl vector<pl>
#define vvl vector<vector<ll>>
#define rep(i,n) for(ll i=0;i<n;i++)
#define repp(i,k,n) for(ll i=k;i<n;i++)
#define en "\n"
const int B = 61;
ll mem[62][2][2];
bool vis[62][2][2];
ll a, b;
ll rec(int i, int c1, int c2){
    if(i == B) return (c1==0 && c2==0) ? 0 : -1;
    if(vis[i][c1][c2]) return mem[i][c1][c2];
    vis[i][c1][c2] = true;
    ll ans = -1;
    int ai = (a >> i) & 1, bi = (b >> i) & 1;
    rep(k,2){
        int s1 = ai + k + c1, s2 = bi + k + c2;
        int nc1 = s1 >> 1, nc2 = s2 >> 1;
        if(((s1 & 1) & (s2 & 1)) != 0) continue;
        ll res = rec(i+1, nc1, nc2);
        if(res == -1) continue;
        ll cur = res | ((ll)k << i);
        if(ans == -1) ans = cur;
    }
    mem[i][c1][c2] = ans;
    return ans;
}
void go(){
    cin >> a >> b;
    memset(vis, 0, sizeof(vis));
    ll r = rec(0, 0, 0);
    cout << (r == -1 || r > 1000000000000000000LL ? -1 : r) << en;
}
int main(){
    fast;
    int T;
    cin >> T;
    while(T--) go();
    return 0;
}
