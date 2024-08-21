#include <iostream>
#include <vector>

using namespace std;

/*
Requirements:
- Input: `candies`, int array; `extraCandies`, int.
- Output `result`, bool array.

Approach:
- Iterate through the `candies`, find out the greatest number of all kids before giving extra candies, denoting as `maxCandies`.
- Iterate through `candies`, add extraCandies one by one, if the added number is greater or equal to the `maxCandies`, push a `true` into the `result` array, else `false`.
*/

class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        // find the the greatest number of candies, store it in variable called 'maxCandies';
        int maxCandies = -1;
        for (int i = 0; i < candies.size(); i++)
        {
            if (candies[i] > maxCandies)
                maxCandies = candies[i];
        }

        // Iterate over candies and plus 'extraCandies' to each candy, see if is larger or equal to 'maxCandies.'
        vector<bool> result;
        for (int i = 0; i < candies.size(); i++)
        {
            result.push_back(candies[i] + extraCandies >= maxCandies);
        }
        return result;
    };
};

int main()
{
    Solution sol;
    vector<int> candies = {4, 2, 1, 1, 2};
    int extraCandies = 1;
    for (bool b : sol.kidsWithCandies(candies, extraCandies))
        cout << b << " ";
    return 0;
}
