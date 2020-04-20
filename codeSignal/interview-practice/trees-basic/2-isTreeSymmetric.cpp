//
// Binary trees are already defined with this interface:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };
bool isSym (Tree<int> * t1, Tree<int> * t2) {
    bool isNull1 = t1 == NULL, isNull2 = t2 == NULL;
    if (isNull1 != isNull2) return false;
    if (isNull1 == true and isNull2 == true) return true;

    if (t1->value == t2->value) {
        return (isSym(t1->left, t2->right) and isSym(t1->right, t2->left));
    }

    return false;
}

bool isTreeSymmetric(Tree<int> * t) {
    return isSym(t, t);
}
