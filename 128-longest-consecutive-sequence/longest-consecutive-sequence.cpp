class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        if (nums.size()==0) {
            return 0;
        }
        unordered_set<int> num_set(nums.begin(), nums.end());
        int longest = 0;
        for (int num : num_set) {
            if (num_set.find(num - 1) == num_set.end()) {
                int currnum = num;
                int currstreak = 1;
                while (num_set.find(currnum + 1) != num_set.end()) {
                    currnum += 1;
                    currstreak += 1;
                }
                longest = max(longest, currstreak);
            }
        }

        return longest;
    }
};
