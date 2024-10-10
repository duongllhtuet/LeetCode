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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *result = nullptr;
        ListNode *current = nullptr;
        int d = 0;

        while (l1 != nullptr || l2 != nullptr || d > 0)
        {
            int sum = (l1 != nullptr ? l1->val : 0) + (l2 != nullptr ? l2->val : 0) + d;
            d = sum / 10; // Lưu số dư

            // Tạo nút mới chứa tổng và cập nhật con trỏ next
            ListNode *newNode = new ListNode(sum % 10);
            if (result == nullptr)
            {
                result = newNode;
                current = result;
            }
            else
            {
                current->next = newNode;
                current = current->next;
            }

            // Di chuyển đến nút tiếp theo trong l1 và l2 (nếu có)
            l1 = (l1 != nullptr ? l1->next : nullptr);
            l2 = (l2 != nullptr ? l2->next : nullptr);
        }

        return result;
    }
};