class Spreadsheet {
    int n;                  
    vector<vector<int>> m;   
public:
    Spreadsheet(int rows) {
        n = rows;
        m.assign(n, vector<int>(26, 0));
    }
    void setCell(string s, int v) {
        int c = s[0] - 'A';         
        int r = stoi(s.substr(1)) - 1; 
        m[r][c] = v;
    }
    void resetCell(string s) {
        int c = s[0] - 'A';
        int r = stoi(s.substr(1)) - 1;
        m[r][c] = 0;
    }
    int getValue(string f) {
        string exp = f.substr(1);
        int p = exp.find('+');
        string L = exp.substr(0, p), R = exp.substr(p + 1);
        int a = 0, b = 0;
        if (isalpha(L[0])) {
            int c = L[0] - 'A';
            int r = stoi(L.substr(1)) - 1;
            a = m[r][c];
        } else {
            a = stoi(L);
        }
        if (isalpha(R[0])) {
            int c = R[0] - 'A';
            int r = stoi(R.substr(1)) - 1;
            b = m[r][c];
        } else {
            b = stoi(R);
        }
        
        return a + b;
    }
};