// Singly-linked lists are already defined with this interface:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
ListNode<int> * removeKFromList(ListNode<int> * l, int k) {
    while (l and l->value == k) l=l->next;

    for (auto node = l; node != NULL; node=node->next) {
        while (node->next and node->next->value == k) node->next = node->next->next;
    }

    return l;
}
