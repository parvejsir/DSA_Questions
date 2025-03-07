//LC POTD closet prime in Range
class Solution {
public:
    void solve(vector<bool>& seive) {
        int n = seive.size();
        seive[0] = seive[1] = false;  // 0 and 1 are not prime
        for (int p = 2; p * p < n; p++) {
            if (seive[p]) {
                for (int i = p * p; i < n; i += p) {
                    seive[i] = false;
                }
            }
        }
    }

    vector<int> closestPrimes(int left, int right) {
        vector<bool> prime(right + 1, true); // Initialize with true
        solve(prime);

        vector<int> primeSet;
        for (int i = left; i <= right; i++) {
            if (prime[i]) {
                primeSet.push_back(i);
            }
        }

        if (primeSet.size() < 2) return {-1, -1}; // No pair exists

        int mindiff = INT_MAX;
        vector<int> result = {-1, -1};
        for (int i = 1; i < primeSet.size(); i++) {
            if (primeSet[i] - primeSet[i - 1] < mindiff) {
                mindiff = primeSet[i] - primeSet[i - 1];
                result = {primeSet[i - 1], primeSet[i]};
            }
        }
        return result;
    }
};
//wildcard matching
class Solution {
public:
    bool isAllStars(string &S1, int i) {
        for (int j = 0; j <= i; j++) {
            if (S1[j] != '*')
                return false;
        }
        return true;
    }

    bool wildcardMatchingUtil(string &S1, string &S2, int i, int j, vector<vector<int>> &dp) {
        // Base Cases
        if (i < 0 && j < 0) return true;
        if (i < 0 && j >= 0) return false;
        if (j < 0 && i >= 0) return isAllStars(S1, i);

        if (dp[i][j] != -1) return dp[i][j];

        if (S1[i] == S2[j] || S1[i] == '?') {
            return dp[i][j] = wildcardMatchingUtil(S1, S2, i - 1, j - 1, dp);
        } else if (S1[i] == '*') {
            return dp[i][j] = wildcardMatchingUtil(S1, S2, i - 1, j, dp) || wildcardMatchingUtil(S1, S2, i, j - 1, dp);
        } else {
            return dp[i][j] = false;
        }
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(m, vector<int>(n, -1)); 
        return wildcardMatchingUtil(p, s, m - 1, n - 1, dp);
    }
};
