#include <iostream>
#include <string>

using namespace std;

/*
Approach:
- Applied two pointers to scan through both s and t:
    - `idxS`: the end of currently found characters
    - `idxT`: scan through the string t
- A loop to keep idxT moving forward, within the loop:
    - If s[idxS] is equal to t[idxT], both idxS move one step forward
    - If idxS is reach the end of string s, return true.
*/

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        if (s == "")
            return true;

        int last_match_idx = 0;
        for (int cur = 0; cur < t.length(); cur++)
        {
            if (t[cur] == s[last_match_idx])
            {
                last_match_idx++;
                if (last_match_idx == s.length())
                    return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution sol;
    string s = "";
    string t = "ahbgdc";
    cout << (sol.isSubsequence(s, t) ? "true" : "false") << endl;
    return 0;
}
