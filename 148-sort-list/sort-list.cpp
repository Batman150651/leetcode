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
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* mergeSortLL(ListNode* leftHead, ListNode* rightHead) {
        ListNode* dummyHead = new ListNode(-1);
        ListNode* temp = dummyHead;
        while (leftHead && rightHead) {
            if (leftHead->val < rightHead->val) {
                temp->next = leftHead;
                leftHead = leftHead->next;
            } else {
                temp->next = rightHead;
                rightHead = rightHead->next;
            }
            temp = temp->next;
        }
        if (leftHead)
            temp->next = leftHead;
        else
            temp->next = rightHead;
        return dummyHead->next;
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head; // fixed
        ListNode* middle = findMiddle(head);
        ListNode* rightHead = middle->next;
        middle->next = nullptr;
        ListNode* leftHead = sortList(head);
        rightHead = sortList(rightHead);
        return mergeSortLL(leftHead, rightHead);
    }
};