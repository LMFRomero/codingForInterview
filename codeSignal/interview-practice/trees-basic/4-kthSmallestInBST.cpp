//
// Binary trees are already defined with this interface:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };
int kth;

//counter, size
pair<int, int> in_order (Tree<int> * t, int k, int counter) {
    if (t == nullptr) 
        return {counter, 0};


    pair <int, int> buf = in_order(t->left, k, counter);
    int new_counter = buf.second + counter + 1;

    if (new_counter == k) 
        kth = t->value;
   
    return {new_counter, buf.second + (in_order(t->right, k, new_counter).second) + 1};
}

int kthSmallestInBST(Tree<int> * t, int k) {
    in_order(t, k, 0);

    return kth;
}
