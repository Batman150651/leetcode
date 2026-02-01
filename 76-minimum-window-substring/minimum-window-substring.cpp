class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<int,int> mp;
        for(int i=0;i<t.size();i++){
            mp[t[i]]++;
        }
        int charCnt = t.size();
        int i=0,j=0;
        string minSubstr = "";
        int minLen = s.size();
        while(j<s.size()){
            if(mp.find(s[j])!=mp.end()){
                if(mp[s[j]]>0) charCnt--;  
                mp[s[j]]--;
            }
            while(charCnt==0){
                if(mp.find(s[i])!=mp.end()){ 
                    if(mp[s[i]]<0){
                        mp[s[i]]++;
                    }
                    else break;
                }
                i++;
            }
            if(charCnt==0 && j-i+1<=minLen){
                minSubstr = s.substr(i,j-i+1);
                minLen = minSubstr.size();
            }
            j++;
        }
        return minSubstr;
    }
};