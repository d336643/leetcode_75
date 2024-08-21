#include <iostream>
#include <string>

using namespace std;

/*
Ideas:
1. How to find candidate divisors?
    - Take the shorter string btw str1 and str2 as the first cantidate, if it's not valid, remove the last char as the next candidate.
2. How to check if 'str' are made up of multiple 'divisor'?
    - Firstly, check if len of 'str' is divisible by len of 'divisor'. If yes, calculate the number of times - 'n'.
    - Second, check if 'divisor * n' equal to 'str'
*/

class Solution
{
public:
    bool isDivisible(string divisor, string strToCheck)
    {
        if (strToCheck.size() % divisor.size() != 0)
            return false;
        if (strToCheck != joinWords(divisor, strToCheck.size() / divisor.size()))
            return false;
        return true;
    }
    string joinWords(string str1, int times)
    {
        string result = "";
        for (int i = 0; i < times; i++)
        {
            result += str1;
        }
        return result;
    }
    string gcdOfStrings(string str1, string str2)
    {
        string divisorBase = str1.size() < str2.size() ? str1 : str2;
        for (int cnt = divisorBase.size(); cnt > 0; cnt--)
        {
            string candidateDivisor = divisorBase.substr(0, cnt);
            if (isDivisible(candidateDivisor, str1) && isDivisible(candidateDivisor, str2))
            {
                return candidateDivisor;
            }
                }
        return "";
    }
};

int main()
{
    Solution solution;
    string str1 = "ABABAB";
    string str2 = "ABAB";

    cout << solution.gcdOfStrings(str1, str2) << endl;
}
