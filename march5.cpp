//reconstruct a original digit
class Solution {
public:
    string originalDigits(string s) {
        map<char,int> mp;
        for(auto it:s)mp[it]++;
        string ans="";
        int cnt;
        if(mp.find('z')!=mp.end() && mp['z']>0){
            cnt=mp['z'];
            ans.insert(ans.size(),cnt,'0');
            mp['z']-=cnt;
            mp['e']-=cnt;
            mp['r']-=cnt;
            mp['o']-=cnt;
        }
        if(mp.find('g')!=mp.end() && mp['g']>0){
            cnt=mp['g'];
            ans.insert(ans.size(),cnt,'8');
            mp['e']-=cnt;
            mp['i']-=cnt;
            mp['g']-=cnt;
            mp['h']-=cnt;
            mp['t']-=cnt;
        }
        if(mp.find('x')!=mp.end() && mp['x']>0){
            cnt=mp['x'];
            ans.insert(ans.size(),cnt,'6');
            mp['s']-=cnt;
            mp['i']-=cnt;
            mp['x']-=cnt;
        }
        if(mp.find('u')!=mp.end() && mp['u']>0){
            cnt=mp['u'];
            ans.insert(ans.size(),cnt,'4');
            mp['f']-=cnt;
            mp['o']-=cnt;
            mp['u']-=cnt;
            mp['r']-=cnt;
        }
        if(mp.find('w')!=mp.end() && mp['w']>0){
            cnt=mp['w'];
            ans.insert(ans.size(),cnt,'2');
            mp['t']-=cnt;
            mp['w']-=cnt;
            mp['o']-=cnt;
        }
        if(mp.find('o')!=mp.end() && mp['o']>0){
            cnt=mp['o'];
            ans.insert(ans.size(),cnt,'1');
            mp['o']-=cnt;
            mp['n']-=cnt;
            mp['e']-=cnt;
        }
        if(mp.find('f')!=mp.end() && mp['f']>0){
             cnt=mp['f'];
            ans.insert(ans.size(),cnt,'5');
            mp['f']-=cnt;
            mp['i']-=cnt;
            mp['v']-=cnt;
            mp['e']-=cnt;
        }
        if(mp.find('t')!=mp.end() && mp['t']>0){
            cnt=mp['t'];
            ans.insert(ans.size(),cnt,'3');
            mp['t']-=cnt;
            mp['h']-=cnt;
            mp['r']-=cnt;
            mp['e']-=cnt;
            mp['e']-=cnt;
        }
        if(mp.find('s')!=mp.end() && mp['s']>0){
            cnt=mp['s'];
            ans.insert(ans.size(),cnt,'7');
            mp['s']-=cnt;
            mp['e']-=cnt;
            mp['v']-=cnt;
            mp['e']-=cnt;
            mp['n']-=cnt;
        }
        if(mp.find('i')!=mp.end() && mp['i']>0){
            cnt=mp['i'];
            ans.insert(ans.size(),cnt,'9');
            mp['n']-=cnt;
            mp['i']-=cnt;
            mp['n']-=cnt;
            mp['e']-=cnt;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
