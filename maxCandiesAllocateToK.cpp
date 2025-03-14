class Solution {
public:
    bool isPossible(vector<int>& candies,long long k,long long mid){
        long long child=0;
        for(int i=0;i<candies.size();i++){
            child+=(long long)candies[i]/mid;
            if(child>=k)return true;
        }
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int n=candies.size();
        int maxCanAssign=*max_element(candies.begin(),candies.end());
        int minCanAssign=1;
        int ans=0;
        while(minCanAssign<=maxCanAssign){
            long long  mid=minCanAssign+(maxCanAssign-minCanAssign)/2;
            if(isPossible(candies,k,mid)){
                ans=mid;
                minCanAssign=mid+1;
            }else{
                maxCanAssign=mid-1;
            }
        }
        return ans;
    }
};
