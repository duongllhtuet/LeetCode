/*Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)



Example 1:

Input: head = [1,2,3,4]

Output: [2,1,4,3]

Explanation:



Example 2:

Input: head = []

Output: []

Example 3:

Input: head = [1]

Output: [1]

Example 4:

Input: head = [1,2,3]

Output: [2,1,3]



Constraints:

The number of nodes in the list is in the range [0, 100].
0 <= Node.val <= 100
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
    ListNode* swapPairs(ListNode* head) 
    {
        if (!head || !head->next) return head; 

        ListNode* dummy = new ListNode(-1);  
        dummy->next = head;
        ListNode* prev = dummy;

        while (head != nullptr && head->next != nullptr) {
            ListNode* first = head;        
            ListNode* second = head->next; 

            first->next = second->next;
            second->next = first;
            prev->next = second;

            prev = first;
            head = first->next;
        }

        return dummy->next;  
    }
};


int main()
{
    Solution solution;

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    ListNode* result = solution.swapPairs(head);

    while (result!= nullptr)
    {
        cout << result->val << " -> ";
        result = result->next;
    }

    return 0;
}