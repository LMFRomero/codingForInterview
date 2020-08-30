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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr or head->next == nullptr)
            return head;
        
        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *initEven = even;
        ListNode *tmp;
        
        while (even) {
            tmp = even->next;
            if (tmp == nullptr)
                break;
            even->next = tmp->next; 
            even = even->next;
            
            odd->next = tmp;
            odd = tmp;
        }
        
        odd->next = initEven;
        
        return head;
    }
};
