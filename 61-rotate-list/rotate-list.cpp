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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next){
            return head;
        }
        ListNode* temp = head;
        ListNode* temp3 = head;
        ListNode* node = nullptr;
        int size = 0;
        while(temp3){
            temp3=temp3->next;
            size++;
        }
        k = k%size;
        if(k==0) return head;
        while(temp){
            ListNode* temp2 = temp->next;
            temp->next = node;
            node = temp;
            temp = temp2;
        }
        ListNode* prev = nullptr;
        ListNode* linker = node;
        while(k>0){
            ListNode* temp2 = node->next;
            node->next = prev;
            prev = node;
            node = temp2;
            k--;
        }
        ListNode* newHead = prev;
        ListNode* prev2 = nullptr;
        while(node){
            ListNode* temp2 = node->next;
            node->next = prev2;
            prev2 = node;
            node = temp2;
        }
        linker->next = prev2;
        return newHead;
    }
};