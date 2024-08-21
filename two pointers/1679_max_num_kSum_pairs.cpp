#include <vector>

using namespace std;

/*
- Intuition
    - Sort the array
    - Applying left and right pointers, both moving inward.
    - To find a pair where the pair sum equal to k,
        - left++ if current sum is too small
        - right-- if current sum is too large

- Implementation:
    - Define:
        - pairCnt
    - while left and right not cross
        - curSum = n[left] + n[right]
        - move left or right
*/

class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        // sort the array
        sort(nums.begin(), nums.end());

        // start finding pairs
        int pairCnt = 0;
        int leftP = 0, rightP = nums.size() - 1;
        while (leftP < rightP)
        {
            int curSum = nums[leftP] + nums[rightP];
            if (curSum == k)
            {
                pairCnt += 1;
                leftP++;
                rightP--;
            }
            else if (curSum < k)
            {
                leftP++;
            }
            else
            {
                rightP--;
            }
        }
        return pairCnt;
    }
};

int main()
{
}
