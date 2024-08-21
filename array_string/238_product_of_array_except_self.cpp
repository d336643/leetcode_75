#include <iostream>
#include <vector>

using namespace std;

/*
Requirement:
- No "division" operation.

Intuition:
- ProductExceptSelf = LeftProduct * RightProduct
    - LeftProduct: the product of lefthand elements before idnex i
    - RightProduct: the product of righthand elements after idnex i
- We could calulate all the left and right products in advance.

Concept,
i = 0, leftP = 1, rightP = n[1]*n[2]...n[k-1]
i = 1, leftP = n[0], rightP = n[2]*n[3]...n[k-1]
...
i = k-1, leftP = n[0]*n[1]*...n[k-2], rightP=1

Improvement:
- Calculate without leftProducts and rightProducts.
*/

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> leftProducts;
        vector<int> rightProducts;
        vector<int> answers;

        // leftProducts: 1, n[0], n[0]*n[1]...
        int curProduct = 1;
        leftProducts.push_back(curProduct);
        for (int i = 0; i < nums.size() - 1; i++)
        {
            curProduct *= nums[i];
            leftProducts.push_back(curProduct);
        }

        // rightProduct: 1, n[k-1], n[k-1]*n[k-2]...
        curProduct = 1;
        rightProducts.push_back(curProduct);
        for (int i = nums.size() - 1; i > 0; i--)
        {
            curProduct *= nums[i];
            rightProducts.push_back(curProduct);
        }

        // product without self
        for (int i = 0; i < nums.size(); i++)
        {
            answers.push_back(leftProducts[i] * rightProducts[nums.size() - i - 1]);
        }
        return answers;
    }
};

int main()
{
}
