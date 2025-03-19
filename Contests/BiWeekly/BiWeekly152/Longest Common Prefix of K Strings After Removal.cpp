typedef unsigned long long ull;
class Solution {
public:
    vector<int> longestCommonPrefix(vector<string>& w, int k) {
        int n=w.size();
        vector<string> dovranimex = w;
        int mL = 0;
        for(auto &s : w) mL = max(mL, (int)s.size());
        const ull B = 131ULL;
        vector<unordered_map<ull,int>> mp(mL+1);
        vector<ull> p(mL+1);
        p[0] = 1;
        for(int i=1;i<=mL;i++) p[i] = p[i-1]*B;
        for(auto &s : w){
            ull h = 0;
            int L = s.size();
            for(int i=0;i<L;i++){
                h = h * B + (s[i]-'a'+1);
                mp[i+1][h]++;
            }
        }
        vector<int> bestF(mL+1,0), secF(mL+1,0);
        vector<ull> bestH(mL+1,0);
        for(int L=1; L<=mL; L++){
            for(auto &pr : mp[L]){
                int cnt = pr.second;
                ull hh = pr.first;
                if(cnt > bestF[L]){
                    secF[L] = bestF[L];
                    bestF[L] = cnt;
                    bestH[L] = hh;
                } else if(cnt > secF[L]){
                    secF[L] = cnt;
                }
            }
        }
        vector<vector<ull>> hs(n);
        for(int i=0;i<n;i++){
            int L = w[i].size();
            hs[i].resize(L+1,0);
            for(int j=0;j<L;j++){
                hs[i][j+1] = hs[i][j]*B + (w[i][j]-'a'+1);
            }
        }
        vector<int> ans(n,0);
        if(n-1 < k){
            return ans;
        }
        for(int i=0;i<n;i++){
            int lo = 1, hi = mL, res = 0;
            while(lo <= hi){
                int mid = (lo+hi)/2;
                int cand;
                if(mid > (int)w[i].size()) cand = bestF[mid];
                else{
                    ull h0 = hs[i][mid];
                    cand = (h0 == bestH[mid] ? max(bestF[mid]-1, secF[mid]) : bestF[mid]);
                }
                if(cand >= k){ res = mid; lo = mid+1; }
                else hi = mid-1;
            }
            ans[i] = res;
        }
        return ans;
    }
};