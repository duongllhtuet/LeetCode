/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
*/

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *next) : val(x), next(next) {};
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int lengthOfListNode = 1;
        ListNode* result = head;

        while (head->next != nullptr) 
        {
            lengthOfListNode++;
            head = head->next;
        }

        int targetNodeNeedToDelete = lengthOfListNode - n;
        ListNode* resultNode = result;
        while (targetNodeNeedToDelete > 1) 
        {
            result = result->next;
            targetNodeNeedToDelete--;
        }

        result->next = result->next->next;

        return resultNode;
    };
};

int main()
{
    Solution solution;

    ListNode head = ListNode(1);
    head.next = new ListNode(2);
    head.next->next = new ListNode(3);
    head.next->next->next = new ListNode(4);
    head.next->next->next->next = new ListNode(5);

    ListNode* result = solution.removeNthFromEnd(&head, 2);

    while (result->next != nullptr)
    {
        cout << result->val << " -> ";
        result = result->next;
    }

    return 0;
}