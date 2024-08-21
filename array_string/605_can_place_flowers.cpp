#include <iostream>
#include <vector>

using namespace std;
/*
Approach:
- Find the maximum # of new flowers can be planted, denoting as `maxFlowersCanBePlanted`.
    -  Iterate through `flowerbed`, For ith plot, check three things: self empty, right emptym left empty, if three conditions are satisfied:
        - `maxFlowersCanBePlanted` + 1
        - set current plot to planted, flowerbed[i] = 1
- Check if n is less or equal to `maxFlowersCanBePlanted`.
*/

class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int plotsCanBePlantedCnt = 0;

        for (int i = 0; i < flowerbed.size(); i++)
        {
            bool isCurrentEmpty = flowerbed[i] == 0;
            bool isLeftEmpty = i == 0 || flowerbed[i - 1] == 0;
            bool isRightEmpty = i == flowerbed.size() - 1 || flowerbed[i + 1] == 0;
            if (isCurrentEmpty && isLeftEmpty && isRightEmpty)
            {
                plotsCanBePlantedCnt += 1;
                flowerbed[i] = 1;
            }
            // cout << plotsCanBePlantedCnt << " ";
        }
        return plotsCanBePlantedCnt >= n;
    }
};

int main()
{
    Solution sol;
    vector<int> flowerbed = {1, 0, 0, 0, 1};
    int n = 2;
    cout << (sol.canPlaceFlowers(flowerbed, n) ? "true" : "false") << endl;
    return 0;
}
