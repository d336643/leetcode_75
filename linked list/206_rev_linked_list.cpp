#include <iostream>
#include <vector>

using namespace std;

/*
Idea:
- Use three pointers, prev, cur, next to reverse the linked list.
*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *cur = head;
        ListNode *next = head->next;

        while (cur != nullptr)
        {
            cur->next = prev;
            prev = cur;
            cur = next;
            next = cur->next;
        }
        return prev;
    }
};

int main()
{
    Solution sol;
    return 0;
}
