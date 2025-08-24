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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int size = 0;
        ListNode* temp = head;
        while(temp){
            size++;
            temp = temp->next;
        }
        int numK = size/k;
        ListNode* linker = new ListNode(-1); 
        ListNode* newHead;   
        for(int i=0;i<numK;i++){
            ListNode* newLinker = head;
            ListNode* node = nullptr;
            for(int j=0;j<k;j++){
                ListNode* temp = head->next;
                head->next=node;
                node = head;
                head = temp;
            }
            if(i==0) newHead = node;
            linker->next = node;
            linker = newLinker;
        }
        linker->next = head;
        return newHead;
    }
};