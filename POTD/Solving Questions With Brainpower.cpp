class Solution {
    public:
        long long mostPoints(vector<vector<int>>& questions) {
            int n = questions.size();
            vector<long long> dp(n,0);
            dp[n-1] = questions[n-1][0];
            for(int i = n-2 ; i >= 0 ; i--) {
                int points = questions[i][0];
                int brainpower = questions[i][1];
            int next_available_index = min(i + brainpower + 1 , n);
            long long solve_points = points + (next_available_index < n ? dp[next_available_index] : 0);
            long long skip_points = dp[i+1];
            dp[i] = max(solve_points,skip_points);
    
            }
            return dp[0];
    
        }
    };