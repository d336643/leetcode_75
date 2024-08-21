#include <iostream>
#include <string>

using namespace std;

/*
 */

class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        int LEN1 = word1.size();
        int LEN2 = word2.size();
        string result = "";

        for (int i = 0; i < max(LEN1, LEN2); i++)
        {
            if (i < LEN1)
            {
                result.push_back(word1[i]);
            }
            if (i < LEN2)
            {
                result.push_back(word2[i]);
            }
        }

        return result;
    }
};

int main()
{
    Solution solution;

    string word1 = "abc";
    string word2 = "defghij";

    string answer = solution.mergeAlternately(word1, word2);

    cout << answer << endl;

    return 0;
}
