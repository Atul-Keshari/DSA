#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(false), cin.tie(nullptr)
#define ll long long
#define rep(i,n) for(ll i=0;i<n;i++)
#define en "\n"
ll gcd(ll a, ll b){ return b==0?a:gcd(b,a%b); }
int main(){
    fast;
    int t; cin >> t;
    while(t--){
        ll N, K; cin >> N >> K;
        bool ok = false;
        ll a = -1, b = -1;
        if(N<=K){
            cout<<a<<" "<<b<<en;
            continue;
        }
        if(2*K+1<=N){
            cout<<1<<" "<<2*K+1<<en;
            continue;
        }
        else{
            for(int i=0;i<100;i++){
                b = N-i;
            for(ll d = 0; ; d++){
                a = N-i - K - d;
                if(a < 1) break;
                ll g = gcd(a, b);
                ll L = (a / g) * b;
                if(L - g >= 2 * K){
                    ok = true;
                    goto xx;
                }
            }
            }
            xx:;
        }
        if(ok) cout << a << " " << b << en;
        else cout << -1 << " " << -1 << en;
    }
    return 0;
}
