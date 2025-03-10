class Solution {
public:
    bool isVowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    long long countOfSubstrings(string word, int k) {
        int n = word.size();
        if (n < k) return 0; // Edge case: If word is shorter than k, no valid substrings exist
        
        vector<int> nextCons(n);
        int lastConsInd = n;
        
        // Precompute next consonant index for each position
        for (int i = n - 1; i >= 0; i--) {
            nextCons[i] = lastConsInd;
            if (!isVowel(word[i])) lastConsInd = i;
        }

        int left = 0, right = 0, cCount = 0;
        map<char, int> vCntMap; // Track vowel frequency
        long long ans = 0;

        while (right < n) {
            char ch = word[right];
            if (isVowel(ch)) {
                vCntMap[ch]++;
            } else {
                cCount++;
            }

            // If consonant count exceeds k, shrink the window
            while (cCount > k) {
                char c = word[left];
                if (isVowel(c)) {
                    vCntMap[c]--;
                    if (vCntMap[c] == 0) {
                        vCntMap.erase(c);
                    }
                } else {
                    cCount--;
                }
                left++;
            }

            // Count valid substrings
            while (left < n && vCntMap.size() == 5 && cCount == k) { 
                int idx = nextCons[right];  // Next consonant index
                ans += idx - right;         // Add all valid substrings
                char ch = word[left];

                if (isVowel(ch)) {
                    vCntMap[ch]--;
                    if (vCntMap[ch] == 0) {
                        vCntMap.erase(ch);
                    }
                } else {
                    cCount--;
                }
                left++;
            }

            right++;
        }

        return ans;
    }
};
