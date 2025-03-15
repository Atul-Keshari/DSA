class Solution {
    public:
        vector<int> longestSpecialPath(vector<vector<int>>& edges, vector<int>& nums) {
            n = nums.size();
            this->nums = nums;
            adj.assign(n, vector<pair<int,int>>());
            for(auto &e: edges){
                int u = e[0], v = e[1], w = e[2];
                adj[u].push_back({v, w});
                adj[v].push_back({u, w});
            }
            path.resize(n);
            dist.resize(n);
            freq.assign(maxVal+1, 0);
            ansLength = 0;
            ansNodes = INT_MAX;
            dupCount = 0;
            overCount = 0;
            dfs(0, -1, 0, 0, 0);
            return { (int)ansLength, ansNodes };
        }
        
    private:
        int n;
        vector<int> nums;
        vector<vector<pair<int,int>>> adj;
        vector<int> path;         
        vector<long long> dist;   
        vector<int> freq;         
        const int maxVal = 50000;
        int dupCount;  
        int overCount; 
        long long ansLength;
        int ansNodes;
        inline bool valid() {
            return (overCount == 0 && dupCount <= 1);
        }
        void dfs(int node, int parent, long long curDist, int L, int depth) {
            path[depth] = node;
            dist[depth] = curDist;
            int v = nums[node];
            int old = freq[v];
            if(old == 0) {
                freq[v] = 1;
            } else if(old == 1) {
                freq[v] = 2;
                dupCount++;
            } else if(old == 2) {
                freq[v] = 3;
                overCount++;
                dupCount--; 
            }
            int origL = L; 
            int newL = L;
            while (!valid() && newL < depth) {
                int remNode = path[newL];
                int remVal = nums[remNode];
                if(freq[remVal] == 1) {
                    freq[remVal] = 0;
                } else if(freq[remVal] == 2) {
                    freq[remVal] = 1;
                    dupCount--;
                } else if(freq[remVal] == 3) {
                    freq[remVal] = 2;
                    overCount--;
                    dupCount++; 
                }
                newL++;
            }
            long long curPathLength = (newL == depth ? 0LL : (dist[depth] - dist[newL]));
            int nodeCount = depth - newL + 1;
            if(curPathLength > ansLength) {
                ansLength = curPathLength;
                ansNodes = nodeCount;
            } else if(curPathLength == ansLength && nodeCount < ansNodes) {
                ansNodes = nodeCount;
            }
            for(auto &p : adj[node]) {
                int child = p.first, w = p.second;
                if(child == parent) continue;
                dfs(child, node, curDist + w, newL, depth + 1);
            }
            for (int i = newL - 1; i >= origL; i--) {
                int remNode = path[i];
                int remVal = nums[remNode];
                if(freq[remVal] == 0) {
                    freq[remVal] = 1;
                } else if(freq[remVal] == 1) {
                    freq[remVal] = 2;
                    dupCount++;
                } else if(freq[remVal] == 2) {
                    freq[remVal] = 3;
                    overCount++;
                    dupCount--; 
                }
            }
            if(freq[v] == 1) {
                freq[v] = 0;
            } else if(freq[v] == 2) {
                freq[v] = 1;
                dupCount--;
            } else if(freq[v] == 3) {
                freq[v] = 2;
                overCount--;
                dupCount++;
            }
        }
    };