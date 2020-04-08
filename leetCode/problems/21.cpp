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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        
        ListNode *current, *currentStart, *otherList, *tmp;
        current = (l1->val < l2->val) ? l1 : l2;
        currentStart = current;
        otherList = (l1->val < l2->val) ? l2 : l1;
        
        while (current->next and otherList) {
            if (current->next->val < otherList->val) {
                current = current->next;
                continue;
            }
            
            else {
                tmp = otherList;
                otherList = otherList->next;
                tmp->next = current->next;
                current->next = tmp;
                current=current->next;
            }
            
        }
        
        if (otherList) current->next = otherList;
        return currentStart;
    }
};
