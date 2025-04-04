#include<bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> numSet(nums.begin(), nums.end());
    int longest = 0;
    for (int num : nums) {
        if (!numSet.count(num - 1)) {
            int currentNum = num, cnt = 1;
            while (numSet.count(currentNum + 1)) {
                currentNum++;
                cnt++;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}

int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << longestConsecutive(nums) << endl; 
    return 0;
}
