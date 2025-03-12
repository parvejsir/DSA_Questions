//lc potd cont max of neg or pos
class Solution {
public:
    int maximumCount(vector<int>& nums) {
     int n=nums.size();
     int neg=0,pos=0;
    for(int i=0;i<n;i++){
      if(nums[i]>0){
          pos++;
      }else if(nums[i]<0){
          neg++;
      }
    }
    // if(nums[n-2]!=nums[n-1]&& nums[n-1]>0){
    //     pos++;
    // }else if (nums[n-2]!=nums[n-1]&& nums[n-1]<0){
    //     neg++;
    // } 
    return max(neg,pos);  
    }
};
//delete and earn
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if(nums.empty()) return 0;

        int maxVal = *max_element(nums.begin(), nums.end());
        vector<int> points(maxVal + 1, 0);
        for (int num : nums) {
            points[num] += num;
        }
        vector<int> dp(maxVal + 1, 0);
        dp[0] = 0;
        dp[1] = points[1];
        for (int i = 2; i <= maxVal; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + points[i]);
        }
        return dp[maxVal];
    }
};
//count the team
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int ans = 0;
        
        for (int j = 1; j < n - 1; j++) {
            int lessLeft = 0, greaterLeft = 0;
            int lessRight = 0, greaterRight = 0;
            
            // Count elements less and greater than rating[j] on the left
            for (int i = 0; i < j; i++) {
                if (rating[i] < rating[j]) lessLeft++;
                else if (rating[i] > rating[j]) greaterLeft++;
            }
            
            // Count elements less and greater than rating[j] on the right
            for (int k = j + 1; k < n; k++) {
                if (rating[k] > rating[j]) greaterRight++;
                else if (rating[k] < rating[j]) lessRight++;
            }
            ans += (lessLeft * greaterRight) + (greaterLeft * lessRight);
        }
        
        return ans;
    }
};
