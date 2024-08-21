#include <iostream>
#include <vector>

using namespace std;

/*
My understanding:
- `gain`: where each element represents a change in altitude from the previous point
- The altitudes of ith point is the sum from gain[0] to gain[i-1].

Idea:
- Altitude Calculation:
    - Cumulatively added up gain[0] to gain[n-1]
- During the iteration, store the maximum altitude we have seen so far.
*/

class Solution
{
public:
    int largestAltitude(vector<int> &gain)
    {
        int curAltitude = 0;
        int maxAltitude = 0;
        for (int i = 0; i < gain.size(); i++)
        {
            curAltitude += gain[i];
            maxAltitude = max(curAltitude, maxAltitude);
        }
        return maxAltitude;
    }
};

int main()
{
    Solution sol;
    vector<int> gain = {-5, 1, 5, 0, -7};
    cout << sol.largestAltitude(gain) << endl;
    return 0;
}
