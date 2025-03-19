#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;

bool isSmooth(const vector<ll> &v) {
    int n = v.size();
    if(n <= 1) return true;
    for (int i = 1; i < n; i++) if(v[i] <= v[i-1]) return false;
    if(n == 2) return true;
    vector<ll> d(n-1);
    for (int i = 0; i < n-1; i++) d[i] = v[i+1]-v[i];
    return isSmooth(d);
}

bool checkWindow(const vector<ll> &B) {
    return isSmooth(B);
}

int main(){
    fast;
    int t; cin >> t;
    while(t--){
        int N; cin >> N;
        vector<ll> A(N);
        for(auto &x : A) cin >> x;
        const int W = 50;
        vector<bool> pref(N, false), suff(N, false);
        {
            vector<ll> win;
            for (int i = 0; i < N; i++){
                int start = max(0, i - W + 1);
                win.clear();
                for (int j = start; j <= i; j++) win.push_back(A[j]);
                pref[i] = isSmooth(win);
            }
        }
        {
            vector<ll> win;
            for (int i = N-1; i >= 0; i--){
                int end = min(N-1, i + W - 1);
                win.clear();
                for (int j = i; j <= end; j++) win.push_back(A[j]);
                suff[i] = isSmooth(win);
            }
        }
        string ans; ans.resize(N, '0');
        for (int i = 0; i < N; i++){
            if(i > 0 && !pref[i-1]) { ans[i] = '0'; continue; }
            if(i < N-1 && !suff[i+1]) { ans[i] = '0'; continue; }
            int L = max(0, i - W);
            int R = min(N-1, i + W);
            vector<ll> B;
            for (int j = L; j <= R; j++){
                if(j==i) continue;
                B.push_back(A[j]);
            }
            if(B.size() == 0) { ans[i] = '1'; continue; }
            ans[i] = checkWindow(B) ? '1' : '0';
        }
        cout << ans << "\n";
    }
    return 0;
}
