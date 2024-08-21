#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
Requirements:
- Return length of s, denoting as `sLen`
- In-place modify `chars` to s
- only one extra space is available

Clarify:
- Do I have to removing the elements after `sLen` when submitting the answer?

Intuition:
- Define the following variables:
    - `sLen`: current length of string `s`, also the pivot recorded for current chaning idx in `chars`
    - `curChar`: current consecutive char
    - `curCharLen`: current consecutive occurance of `curChar`
- Iterate through `chars`, name current charater as `c`:
    - if c is equal to curChar
        - curCharLen += 1
    - else // not consutive, jump to next char
        - update chars[sLen] to `curChar`
        - If `curCharLen` is greater than one, update one or few chars after chars[sLen] depends on the quotient of curCharLen
        - update `sLen`
        - update `curChar` and `curCharLen`
    - check if it's final char, if yes, update `sLen`

*/

class Solution
{
public:
    int updateChars(int sLen, vector<char> &chars, int curCharLen)
    {
        if (curCharLen > 1)
        {
            string curCharLenStr = to_string(curCharLen);
            for (int i = 0; i < curCharLenStr.size(); i++)
                chars[sLen + i] = curCharLenStr[i];
            return sLen + curCharLenStr.size();
        }
        return sLen;
    }
    int compress(vector<char> &chars)
    {
        int sLen = 1;
        char curChar = chars[0];
        int curCharLen = 1;

        for (int i = 1; i < chars.size(); i++)
        {
            if (chars[i] == curChar)
            {
                curCharLen += 1;
            }
            else
            {
                // append occurance if it's greater than one
                sLen = updateChars(sLen, chars, curCharLen);
                // update current checking point to new alphabet
                curChar = chars[i];
                curCharLen = 1;
                chars[sLen++] = curChar;
            }
            // Update the final group count when meet the final char
            if (i == chars.size() - 1)
            {
                sLen = updateChars(sLen, chars, curCharLen);
            }

            // cout << curChar << " " << curCharLen << " " << sLen << endl;
        }
        return sLen;
    }
};

int main()
{
    Solution sol;
    vector<char> chars = {'a', 'a', 'b', 'b', 'b', 'c', 'c'};
    cout << sol.compress(chars) << endl;
}
