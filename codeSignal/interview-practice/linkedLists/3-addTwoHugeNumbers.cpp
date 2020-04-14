// Singly-linked lists are already defined with this interface:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//


ListNode<int> * addTwoHugeNumbers(ListNode<int> * a, ListNode<int> * b) {
    int count = 0;
    ListNode<int> *prev = NULL, *next = NULL, *big, *small;
    int tmp = 0;
    int carry = 0;


    for (auto node = a; node != NULL;) {
        count++;
        next = node->next;
        node->next = prev;
        prev = node;
        node = next;
    }
    a = prev;

    tmp = count;
    big = a;

    count = 0;
    prev = next = NULL;
    for (auto node = b; node != NULL;) {
        count++;
        next = node->next;
        node->next = prev;
        prev = node;
        node = next;
    }
    b = prev;

    if (count > tmp) {
        big = b;
        small = a;
    }
    else small = b;

    count = 0;
    auto nodeA = big, nodeB = small;
    while (nodeA) {
        tmp = carry + nodeA->value + ((nodeB) ? nodeB->value : 0);
        if (tmp > 9999) {
            carry = tmp/9999;
            tmp %= 10000;
        }
        else {
            carry = 0;
        }

        nodeA->value = tmp;
        nodeA = nodeA->next;
        if (nodeB) nodeB = nodeB->next;
    }

    next = prev = NULL;
    for (auto node = big; node != NULL;) {
        count++;
        next = node->next;
        node->next = prev;
        prev = node;
        node = next;
    }
    big = prev;

    if (carry != 0) {
        small->value = carry;
        small->next = big;
        big = small;
    }

    return big;

}
