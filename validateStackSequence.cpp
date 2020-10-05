 bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> S;
        int j=0;
        for(int i=0;i<pushed.size();i++) {
            while(j<popped.size()&&!S.empty()&&popped[j]==S.top()) {
                S.pop();
                ++j;
            } 
          S.push(pushed[i]);
        }
        
        while(!S.empty()) {
            if(popped[j] != S.top()) {
                return false;
            }
            S.pop();
            ++j;
        }
        return true;
    }