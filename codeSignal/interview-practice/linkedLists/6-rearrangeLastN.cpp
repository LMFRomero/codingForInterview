/ Singly-linked lists are already defined with this interface:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
ListNode<int> * rearrangeLastN(ListNode<int> * l, int n) {
    if (!l or n == 0) return l;

    auto node = l;
    int size = 1;
    for (; node->next != NULL; node = node->next) size++;
    if (size == n) return l;
    node->next = l;

    node = l;
    for (int i = 1; i < size-n; i++) {
        node = node->next;
    }
    l = node->next;
    node->next = NULL;

    return l;
}
