/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head || !head->next) return NULL;
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* temp = head;
        while (fast && fast->next) {
            temp = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        temp->next = slow->next;
        return head;
    }
};