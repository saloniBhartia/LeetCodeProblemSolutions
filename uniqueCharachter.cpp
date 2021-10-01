class Solution {
public:
    int firstUniqChar(string s) {
        map<char, int> charMap;
        
        for(int i=0;i<s.length();i++) {
            if(charMap.find(s[i]) != charMap.end()) {
               charMap[s[i]] = s.length() + i; 
            } else {
               charMap[s[i]] = i;    
            }
        }
        int minimum = INT_MAX;
        map<char, int>:: iterator itr = charMap.begin();
        
        for(;itr!=charMap.end();itr++) {
            if(itr->second<s.length()&&itr->second < minimum) {
                minimum = itr->second;
            }    
        }
        if(minimum == INT_MAX) return -1;
        return minimum;
    }
};
