//BRUTE FORCE APPROACH 


//OPTIMISED APPROACH 
// Here we'll use the concept of expand from center, consider each index as center & expand 
// We'll do this for all the elements of array by loping over it.
// O(n^2)
class Solution {
public:
int expandFromCenter(const string &s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;  // Length of the palindrome
    }

    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int n = s.size();
        int start = 0, end = 0;

        for (int i = 0; i < n; i++) {
            // Check for odd-length palindromes centered at i
            int len1 = expandFromCenter(s, i, i);
            // Check for even-length palindromes centered between i and i+1
            int len2 = expandFromCenter(s, i, i + 1);
            int len = max(len1, len2);

            // Update the start and end indices of the longest palindrome found
            if (len > end - start) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substr(start, end - start + 1);
    }
};
