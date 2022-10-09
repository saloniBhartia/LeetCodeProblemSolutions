class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> S;
        vector<int> result(T.size());
        if(T.size()==0) {
            return result;
        } 
        S.push(0);
        for(int i=1;i<T.size();i++) {
            while(!S.empty() && T[S.top()]<T[i]) {
                result[S.top()] = i-S.top();
                S.pop();
            }
            S.push(i);
        }
        
        while(!S.empty()) {
            result[S.top()]=0;
            S.pop();
        }
        return result;
    }
};

//https://leetcode.com/problems/daily-temperatures/