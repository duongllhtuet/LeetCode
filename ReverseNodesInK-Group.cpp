/*
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.



Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
Example 2:


Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]


Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 5000
0 <= Node.val <= 1000

*/

#include <iostream>

using namespace std;

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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prevGroupEnd = dummy;
        
        while (true)
        {
            ListNode* groupStart = prevGroupEnd->next;
            ListNode* groupEnd = prevGroupEnd;
            for (int i = 0; i < k && groupEnd != nullptr; i++)
                groupEnd = groupEnd->next;

            if (groupEnd == nullptr) break; 

            ListNode* nextGroupStart = groupEnd->next;
            reverseLinkedList(groupStart, groupEnd);

            prevGroupEnd->next = groupEnd;
            groupStart->next = nextGroupStart;

            prevGroupEnd = groupStart;
        }

        return dummy->next;
    }

private:
    void reverseLinkedList(ListNode* start, ListNode* end)
    {
        ListNode* prev = nullptr;
        ListNode* curr = start;
        ListNode* next = nullptr;

        while (prev != end)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
    }
};

/*
1 2 3 4 5
1 2 3

curr = addresse(1);
next = addresse(2);x
*/

int main()
{
    Solution solution;

    ListNode head = ListNode(1);
    head.next = new ListNode(2);
    head.next->next = new ListNode(3);
    head.next->next->next = new ListNode(4);
    head.next->next->next->next = new ListNode(5);

    ListNode *result = solution.reverseKGroup(&head, 2);

    while (result != nullptr)
    {
        cout << result->val << " -> ";
        result = result->next;
    }

    return 0;
}