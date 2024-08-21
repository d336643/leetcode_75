#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
Intuition:
- Apply two while loops:
- an outer loop scans through all the characters of string s
- Within the outer loop:
    - an inner loop to capture a word.
    - escaping the spaces

Implementation:
- Define a vector of string `words`.
- A pointer to store current scanning position, denoting as: i
- Outer loop:
    - While loop, break while i equals to the size of string s
    - continue when meet a space
- inner loop:
    - keeping append char to current string, break while meet a space
*/

class Solution
{
public:
    string reverseWords(string s)
    {
        // Searching for all words.
        vector<string> words;
        int idx = 0;
        while (idx < s.size())
        {
            if (s[idx] == ' ')
            {
                idx++;
                continue;
            }
            string currentStr = "";
            // capture a word
            while (idx < s.size() && s[idx] != ' ')
            {
                currentStr.push_back(s[idx]);
                idx += 1;
            }
            words.push_back(currentStr);
        }

        // Reverse words and return it to a sentence.
        string answer = "";
        for (int i = words.size() - 1; i >= 0; i--)
        {
            answer += words[i];
            if (i != 0)
                answer.push_back(' ');
        }
        return answer;
    }
};

int main()
{
}
