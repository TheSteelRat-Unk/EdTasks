// 
#include <vector>
#include <iostream>
#include <unordered_map>

class Solution {
public:
    int longestSubsequence(std::vector<int>& arr, int difference);
};

int Solution::longestSubsequence(std::vector<int>& arr, int difference)
{
    int longest = 0;
    std::unordered_map<int, int> dp;

    for (int num : arr) {
        dp[num] = dp[num - difference] + 1;
        longest = std::max(longest, dp[num]);
    }

    return longest;
}

int main() {
    std::vector<int> arr = {1, 5, 3, 7, 2, 8, 6};
    int difference = 2;

    Solution solution;
    int longest = solution.longestSubsequence(arr, difference);

    std::cout << "Longest subsequence length: " << longest << std::endl;

    return 0;
}
