//LC POTD 11mar
class Solution {
public:
    int numberOfSubstrings(string s) {
       vector<int> lastSeen(3,-1);
       int count=0;
       for(int i=0;i<s.size();i++){
        lastSeen[s[i]-'a']=i;
        if(lastSeen[0]!=-1 && lastSeen[1]!=-1 && lastSeen[2]!=-1){
         int tempmin=min(lastSeen[0],lastSeen[1]);
         int finalmin=min(tempmin,lastSeen[2]);
         count+=1+finalmin;
        }
       } 
       return count;
    }
};
