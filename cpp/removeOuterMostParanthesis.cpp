class Solution {
public:
    string removeOuterParentheses(string S) {
        stack<char> st;
        int numOfPops;
        string target="";
        int i=0;
        while(i<S.length()) {
            if(S[i]=='(') {
                st.push('(');
                if(st.size()>1) {
                    target+='(';
                }
                ++i;
            } else {
                numOfPops = 0;
                while(S[i]==')'&& st.size()>1) {
                    st.pop();
                    ++numOfPops;
                    ++i;
                }
                while(numOfPops>0) {
                    target+=')';
                    --numOfPops;
                }
                if(st.size()==1 && S[i]==')') {
                    st.pop();
                    ++i;
                }
            }
        }
        return target;
    }
};
