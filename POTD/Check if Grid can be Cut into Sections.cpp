class Solution {
    public:
        bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
            vector<vector<int>> temp = rectangles;
            sort(temp.begin(), temp.end(), [&](vector<int>& v1, vector<int>& v2){
                return v1[1]<v2[1];
            });
            int cnt=1;
            for(int i=1; i<temp.size(); i++){
                int sy_curr = temp[i][1];
                int ey_prev = temp[i-1][3];
    
                if(sy_curr >= ey_prev){
                    cnt++;
                    ey_prev = temp[i][3];
                }
                else{
                    temp[i][3] = max(temp[i-1][3], temp[i][3]);
                    continue;
                }
            }
            if(cnt>=3) return true;
            sort(rectangles.begin(), rectangles.end(), [&](vector<int>& v1, vector<int>& v2){
                return v1[0]<v2[0];
            });
            int count=1;
            for(int i=1; i<rectangles.size(); i++){
                int sx_curr = rectangles[i][0];
                int ex_prev = rectangles[i-1][2];
                if(sx_curr >= ex_prev){
                    count++;
                }
                else{
                    rectangles[i][2] = max(rectangles[i-1][2], rectangles[i][2]);
                    continue;
                }
            }
            return count>=3;
        }
    };