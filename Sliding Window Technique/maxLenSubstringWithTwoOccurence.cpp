class Solution {
public:
    int maximumLengthSubstring(string s) {
        int cnt[26] = {};  // Array to count occurrences of each character
    int res = 0;       // Result variable to store the maximum length
    int j = 0;         // Start pointer for the sliding window

    for (int i = 0; i < s.size(); ++i) {
        cnt[s[i] - 'a']++;  // Increment the count of the current character

        // If the count of the current character exceeds 2, shrink the window
        while (cnt[s[i] - 'a'] > 2) {
            cnt[s[j] - 'a']--;  // Decrement the count of the character at the start of the window
            j++;                // Move the start pointer to the right
        }

        // Update the result with the maximum length of the valid window
        res = max(res, i - j + 1);
    }

    return res;  // Return the maximum length found
    }
};