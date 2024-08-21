#include <iostream>
#include <vector>

using namespace std;

/*
Requirements:
- in-place switching.
- Edge cases: empty array? all zeros at the end? no zeros at all?

Approach:
- Move all non-zeros to the prefix elements, append the remaining spots to zeros.
- Use two pointers:
    - `searchingIdx`: Scans through the array looking for non-zero elements.
    - `placeIdx`: Marks the position where the next non-zero element founded by `searchingIdx` should be placed. It records the current end of the non-zeros.
- While `searchingIdx` iterates through the end, all non-zero elements with original order should be shifted to the begining of the array up to `placeIdx-1`.
- To push all zeros to the end, from `placeIdx` to `nums.size()-1`, fill these indices with zeros.
*/

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int last_non_zero_idx = 0;
        for (int cur_idx = 0; cur_idx < nums.size(); cur_idx++)
        {
            if (nums[cur_idx] != 0)
                nums[last_non_zero_idx++] = nums[cur_idx];
        }
        for (; last_non_zero_idx < nums.size(); last_non_zero_idx++)
        {
            nums[last_non_zero_idx] = 0;
        }
    }
};

void printVector(const vector<int> &vec)
{
    cout << "[";
    for (int i = 0; i < vec.size(); i++)
    {
        if (i != vec.size() - 1)
            cout << vec[i] << ",";
        else
            cout << vec[i] << "]" << endl;
    }
}

int main()
{
    Solution sol;
    vector<int> nums = {0, 1, 0, 3, 12};
    sol.moveZeroes(nums);
    printVector(nums);
    return 0;
}
