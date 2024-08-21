#include <iostream>
#include <queue>

using namespace std;

/*
Idea:
- Every time a new ping occurs, calculate the new time window frame.
- Check the valid values if it's still valid, start from the front, if is out of the newest window frame,  pop it, until meet the one is still valid. Use a queue to store the current valid values.
*/

class RecentCounter
{
public:
    queue<int> tsForRecentRequests;

    RecentCounter()
    {
    }

    int ping(int t)
    {
        tsForRecentRequests.push(t);
        while (tsForRecentRequests.front() < t - 3000)
            tsForRecentRequests.pop();
        return tsForRecentRequests.size();
    }
};

int main()
{
    RecentCounter *obj = new RecentCounter();
    return 0;
}
