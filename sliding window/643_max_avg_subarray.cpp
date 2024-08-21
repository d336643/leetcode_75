#include <iostream>
#include <vector>

using namespace std;

/*
Intuition:
- applying sliding window to frame each k continuous sbarrays
- After interating and summing each windows, we could get the greatest total of subarray, denoting as `maxSubArrSum`.

After submission:
- TLE when k is super larger, analyze:
- In each iteration, summing up all elements in the subarray is inefficient.

Improvement:
- Since the sliding window move forward by one element at a time, we could update the sum of the sliding window by
    - subtracting the first element which is removed from the window.
    - adding the last element that enters the window.
*/

class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        // The first subarray
        double maxSurArrSum = 0;
        double curSubArrySum = 0;
        for (int i = 0; i < k; i++)
            curSubArrySum += nums[i];
        maxSurArrSum = curSubArrySum;

        // iterate from second subarray
        // when sum up a new array. instead of add all k elements again, minus the first one and plus the last one.
        for (int i = 1; i < nums.size() - k + 1; i++)
        {
            curSubArrySum = curSubArrySum - nums[i - 1] + nums[i + k - 1];
            maxSurArrSum = max(curSubArrySum, maxSurArrSum);
            // cout << curSubArrySum << " ";
        }
        return maxSurArrSum / k;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {8860, -853, 6534, 4477, -4589, 8646, -6155, -5577, -1656, -5779, -2619, -8604, -1358, -8009, 4983, 7063, 3104, -1560, 4080, 2763, 5616, -2375, 2848, 1394, -7173, -5225, -8244, -809, 8025, -4072, -4391, -9579, 1407, 6700, 2421, -6685, 5481, -1732, -8892, -6645, 3077, 3287, -4149, 8701, -4393, -9070, -1777, 2237, -3253, -506, -4931, -7366, -8132, 5406, -6300, -275, -1908, 67, 3569, 1433, -7262, -437, 8303, 4498, -379, 3054, -6285, 4203, 6908, 4433, 3077, 2288, 9733, -8067, 3007, 9725, 9669, 1362, -2561, -4225, 5442, -9006, -429, 160, -9234, -4444, 3586, -5711, -9506, -79, -4418, -4348, -5891};
    int k = 93;
    cout << sol.findMaxAverage(nums, k) << endl;
}
