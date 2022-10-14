class Solution {
    
    void print(vector<vector<int>> p, int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout<<p[i][j]<<" ";
            cout<<"\n";
        }
    }
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<int>> LCS(n, vector<int>(n, 0));
        int maxLength = 0;
        string result = "";
        
        for (int gap = 0; gap < n; gap++) {
            for (int i=0; i < n-gap; i++) {
                int j = i+gap;
                if (gap == 0) {
                    LCS[i][j] = 1;
                } else if (gap == 1) {
                    LCS[i][j] = (s[i] == s[j]);
                } else {
                    LCS[i][j] = (s[i] == s[j] && (LCS[i+1][j-1] == 1));
                }
                
                if (LCS[i][j] == 1 && maxLength < gap+1) {
                    maxLength = gap+1;
                    result = s.substr(i, gap+1);
                }
            }
        }
        
        // print(LCS, n);
        
        return result;
    }
};