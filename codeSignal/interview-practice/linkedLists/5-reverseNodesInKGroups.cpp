// Singly-linked lists are already defined with this interface:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
ListNode<int> * reverseNodesInKGroups(ListNode<int> * l, int k) {
    ListNode<int> *node = l;
    int i = 0;
    while (i < k and node) {
        i++;
        node = node->next;
    }
    if (i != k) return l;

    ListNode<int> *first = l, *r = 0;
    while (i--) {
        node = l;
        l = l->next;
        node->next = r;
        r = node;
    }
    first->next = reverseNodesInKGroups(l, k);
    return node;    
}
