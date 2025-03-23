class Solution {
    public:
    int mod=(int)1e9+7;
        int countPaths(int n, vector<vector<int>>& roads) {
            priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>pq;
            vector<vector<long long>>adj[n];
            vector<long long>dis(n,LLONG_MAX);
            for(auto in:roads){
                adj[in[0]].push_back({in[1],in[2]});
                adj[in[1]].push_back({in[0],in[2]});
            }
            pq.push({0,0});
            dis[0]=0;
            vector<long long>fre(n,0);
            fre[0]=1;
            while(!pq.empty()){
                long long tim=pq.top().first;
                long long nod=pq.top().second;
                pq.pop();
                for(auto in:adj[nod]){
                    if(dis[in[0]]>tim+in[1]){
                        dis[in[0]]=tim+in[1];
                        fre[in[0]]=fre[nod]%mod;
                        pq.push({dis[in[0]],in[0]});
                    }else if(dis[in[0]]==tim+in[1]){
                        fre[in[0]]=(fre[in[0]]+fre[nod])%mod;
                    }
                }
            }
            return fre[n-1]%mod;
        }
    };