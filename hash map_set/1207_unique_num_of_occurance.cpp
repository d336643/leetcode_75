#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/*
Idea:
- Obviously, use "hash map" to find the # of occurance of each elements in the array. {i: occurance}
- After collect the hash map, try to insert the occurances into a set, if insert fail, it means the value is already in the set, which means duplicate occurance.

Notes.
- The insert() function returns a std::pair.
- `result.first` is an iterator that points to the element in the set.
- `result.second` is a boolean value that indicates whether the insertion was successful.
*/

class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        unordered_map<int, int> num_cnt_dict;
        for (auto i : arr)
            num_cnt_dict[i]++;

        unordered_set<int> test_set;
        for (auto &pair : num_cnt_dict)
        {
            int occurance = pair.second;
            // Try to insert occurance in to a set.
            if (!test_set.insert(occurance).second)
                return false;
        }
        return true;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {-3, 0, 1, -3, 1, 1, 1, -3, 10, 0};
    cout << sol.uniqueOccurrences(arr) << endl;
    return 0;
}
