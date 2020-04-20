//
// Binary trees are already defined with this interface:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };
bool path(Tree<int> * t, int s, int sum) {
    if (t == nullptr) return false;
    sum += t->value;
    
    if (t->left == nullptr and t->right == nullptr) {
        if (sum == s) return true;
        else return false;
    }

    return (path(t->left, s, sum) or path(t->right, s, sum));
}

bool hasPathWithGivenSum(Tree<int> * t, int s) {
    return path(t, s, 0);
}
