//
// Binary trees are already defined with this interface:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };

bool compare (Tree<int> * t1, Tree<int> * t2) {
    if (t1 == nullptr || t2 == nullptr) return t1 == t2;

    if (t1->value != t2->value) return false;

    return (compare(t1->left, t2->left) and compare(t1->right, t2->right));
}

bool isSubtree(Tree<int> * t1, Tree<int> * t2) {
    if (t1 == nullptr)
        return t2 == nullptr;
 
    return compare(t1, t2) or isSubtree(t1->left, t2) or isSubtree(t1->right, t2); 
}
