/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int tam = 1;
        int middle;
        ListNode *node;
        
        for (node = head->next; node != NULL; node=node->next) tam++;
        
        middle = (tam/2)+1;
        
        node = head;
        for (int i = 1; i < middle; i++) node=node->next;
        
        return node;
    }
};
