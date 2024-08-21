#include <iostream>
#include <vector>

using namespace std;

/*
My understanding:
-  strictly to the left: assume idx of pivot is 4, left sum = nums[0] + nums[1] + nums[2] + nums[3].

Check:
- Could the pivot index be the first or last element? => Yes, it can be, as the sums on one side would be zero.

Idea:
- Iterate candidate pivot i, from 0 to the size of nums. Check if sumLeft equal to sumRight in each iteration.
- To efficiently calculate sumLeft and sumRight,
    - Initialize sumLeft to 0, sumRight to total sum of nums.
    - In each iteration, adding or subtracting the changing element to the previous sum.
*/

class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int curLeftSum = 0;
        int curRightSum = 0;
        for (int i = 1; i < nums.size(); i++)
            curRightSum += nums[i];
        if (curLeftSum == curRightSum)
            return 0;

        for (int candidatePivot = 1; candidatePivot < nums.size(); candidatePivot++)
        {
            curLeftSum += nums[candidatePivot - 1];
            curRightSum -= nums[candidatePivot];
            if (curLeftSum == curRightSum)
                return candidatePivot;
            // cout << curLeftSum << " " << curRightSum << endl;
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 1, -1};
    cout << sol.pivotIndex(nums) << endl;
    return 0;
}
