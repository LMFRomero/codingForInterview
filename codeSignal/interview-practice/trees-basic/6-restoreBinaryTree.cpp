//
// Binary trees are already defined with this interface:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };
Tree<int> * restoreBinaryTree(std::vector<int> inorder, std::vector<int> preorder) {
    if (preorder.empty() == true)
        return nullptr;

    Tree<int> *root = new Tree(preorder[0]);
    auto find_it = find (inorder.begin(), inorder.end(), preorder[0]);
    int count_find = 0;
    for (auto it = inorder.begin(); it != find_it; it++, count_find++);

    vector <int> new_in, new_pre;

    for (int i = 1; i <= count_find; i++) new_pre.push_back(preorder[i]);
    for (int i = 0; i < count_find; i++) new_in.push_back(inorder[i]);
    root->left = restoreBinaryTree(new_in, new_pre);

    new_in.clear(); new_pre.clear();
    int size_in = inorder.size(), size_pre = preorder.size();

    for (int i = count_find+1; i < size_pre; i++) new_pre.push_back(preorder[i]);
    for (int i = count_find+1; i < size_in; i++) new_in.push_back(inorder[i]);
    root->right = restoreBinaryTree(new_in, new_pre);


    return root;
}
