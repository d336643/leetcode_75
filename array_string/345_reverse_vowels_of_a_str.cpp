#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
Check:
- Are all input strings containing at least one vowel?
- Do the vowels appear in upper or lower case?

Approach:
- Use `left` and `right` pointers, `left` starts from the begining and move forward, `right` starts from the end and move backward.
- Create an outer loop to make sure two pointers stop while cross each other. Within the outer loop,
    - Use two `while` inner loops to let two pointers search for the next vowel.
    - When both pointers find the next vowels, switch.
*/

class Solution
{
public:
    bool isVowels(char c)
    {
        string vowels = "aeiouAEIOU";
        return vowels.find(c) != -1;
    }
    void swapChar(string &s, int idx1, int idx2)
    {
        char temp = s[idx1];
        s[idx1] = s[idx2];
        s[idx2] = temp;
    }
    string reverseVowels(string s)
    {
        int left = 0;
        int right = s.length() - 1;
        while (left < right)
        {
            while (!isVowels(s[left]) && left < right)
                left++;
            while (!isVowels(s[right]) && left < right)
                right--;
            swapChar(s, left, right);
            left++;
            right--;
            // cout << left << "!!" << right << endl;
        }

        return s;
    }
};

int main()
{
    Solution sol;
    string s = "leetcode";
    cout << sol.reverseVowels(s) << endl;
    return 0;
}
