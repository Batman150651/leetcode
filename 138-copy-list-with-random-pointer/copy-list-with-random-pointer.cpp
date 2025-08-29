/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> map;
        Node* newHead = new Node(-1);
        Node* newItr = newHead;
        Node* itr = head;
        while(itr){
            Node* node = new Node(itr->val);
            map[itr] = node;
            newItr->next = node;
            itr = itr->next;
            newItr = node;
        }
        itr = head;
        newItr = newHead->next;
        while(itr){
            if(itr->random){
                newItr->random = map[itr->random];
            }
            itr = itr->next;
            newItr = newItr->next;
        }
        Node* deleted = newHead;
        newHead = newHead->next;
        delete deleted;
        return newHead;
    }
};