#include <iostream>
#include <vector>
#include <set>

using namespace std;

/*
Idea:
- Obviously, use "set" is much more efficient becuase it takes only O(1) for the "find" operation.

*/

class Solution
{
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {
        set<int> set1;
        set<int> set2;

        for (int i = 0; i < nums1.size(); i++)
            set1.insert(nums1[i]);
        for (int i = 0; i < nums2.size(); i++)
            set2.insert(nums2[i]);

        vector<int> onlyInNums1;
        vector<int> onlyInNums2;
        for (const auto &n : set1)
        {
            if (set2.find(n) == set2.end())
                onlyInNums1.push_back(n);
        }
        for (const auto &n : set2)
        {
            if (set1.find(n) == set1.end())
                onlyInNums2.push_back(n);
        }
        return {onlyInNums1, onlyInNums2};
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {2, 4, 6};
    vector<vector<int>> answer = sol.findDifference(nums1, nums2);
    return 0;
}
