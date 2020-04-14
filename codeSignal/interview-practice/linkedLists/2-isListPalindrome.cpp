// Singly-linked lists are already defined with this interface:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
bool isListPalindrome(ListNode<int> * l) {
    if (!l) return true;
    int count = 0;
    auto tmpPointer = l;

    for (auto node = l; node != NULL; node=node->next) count++;

    if (count == 1) return true;

    auto nodeFront = tmpPointer;
    auto nodeBack = tmpPointer->next;
    
    for (int i = 1; i <= count; i++) {
        if (i > (count/2)) {
            tmpPointer = nodeFront->next;
            nodeFront->next = nodeBack;
            nodeBack = nodeFront;
            nodeFront = tmpPointer;
        }
        else {
            nodeFront=nodeFront->next;
            nodeBack=nodeBack->next;
        }
    }

    nodeFront = l;
    for (int i = 1; i <= count/2; i++) {
        if (nodeFront->value != nodeBack->value) {
            return false;
        }
        nodeFront = nodeFront->next;
        nodeBack = nodeBack->next;
    }

    return true;
}

