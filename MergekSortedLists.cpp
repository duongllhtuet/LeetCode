/*
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
 

Constraints:

k == lists.length
0 <= k <= 104
0 <= lists[i].length <= 500
-104 <= lists[i][j] <= 104
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 104.
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode* next) : val(x), next(next) {};

};


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        int lengthOfLists = lists.size();

        ListNode* list = mergeTwoLists(lists[0], lists[1]);

        for (int i = 2; i< lengthOfLists; i++)
        {
            list = mergeTwoLists(list, lists[i]);
        }

        return list;
    };
private:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        ListNode* result = new ListNode(-1); 
        ListNode* current = result;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }

        if (list1 != nullptr) {
            current->next = list1;
        } else {
            current->next = list2;
        }

        return result->next;  
    };
};

int main()
{
    Solution solution;

    vector<ListNode*> lists;
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(4);
    list1->next->next = new ListNode(5);
    lists.push_back(list1);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);
    lists.push_back(list2);

    ListNode* list3 = new ListNode(2);
    list3->next = new ListNode(6);
    lists.push_back(list3);

    ListNode* result = solution.mergeKLists(lists);

    while (result!= nullptr)
    {
        cout << result->val << " -> ";
        result = result->next;
    }

    return 0;
}