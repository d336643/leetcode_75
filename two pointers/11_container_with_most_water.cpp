#include <vector>
#include <iostream>

using namespace std;

/*
Reasoning:
- Assume we choose two container (i, j)
    - stored water = width * height =  (j - i) * min(h[i], h[j])
- By setting right and left pointers moving inward, we could explore the area from largest width.
- To explore the possibility of larger area, we could move the pointer with shorter height inward.

Intuition:
- Method 1. Brute Force
    - Apply nested loop to find all candidate pairs.
    - Store the max water.
- Method 2. Two pointers.

Implementation:
- Define:
    - maxArea
    - leftP, rightP
- while two pointers not cross
    - curArea
    - update maxArea if curArea > maxArea
    - update leftP or rightP
*/

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int maxArea = -1;
        int leftP = 0, rightP = height.size() - 1;
        while (leftP < rightP)
        {
            int curArea = height[leftP] * height[rightP];
            if (curArea > maxArea)
            {
                maxArea = curArea;
            }

            if (height[leftP] < height[rightP])
                leftP++;
            else
                rightP--;
        }
        return maxArea;
    }
};

int main()
{
}
