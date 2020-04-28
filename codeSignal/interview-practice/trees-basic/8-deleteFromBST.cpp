//
// Binary trees are already defined with this interface:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };
Tree<int> * find_value(Tree<int> *t, int value) {
    if (t == nullptr) return nullptr;

    if (t->left) 
        if (t->left->value == value) return t;
    if (t->right) 
        if (t->right->value == value) return t;

    auto node = find_value(t->left, value);
    return (node) ? node : find_value(t->right, value);
}

int get_new_node (Tree<int> *node, Tree<int> *prev) {
    if (node->right) return get_new_node(node->right, node);
    
    int new_val = node->value;
    prev->right = node->left;
    free(node);

    return new_val;
}

Tree<int> * remove_node (Tree<int> *node) {
    if (!(node->left)) {
        if (!(node->right)){
            free(node);
            return nullptr;
        }

        auto tmp = node->right;
        free(node);
        node = tmp;
    }

    else {
        if (node->left->right) node->value = get_new_node(node->left, node);
        else {
            auto tmp = node->left;
            tmp->right = node->right;
            free(node);
            node = tmp;
        }
    }
        
    return node;
}

Tree<int> * deleteFromBST(Tree<int> * t, std::vector<int> queries) {
    for (int i : queries) {
        if (t == nullptr) return t;

        if (t->value == i) {
            t = remove_node(t);
            continue;
        }

        auto node = find_value(t, i);
        if (node == nullptr) continue;

        if (node->left and node->left->value == i)
            node->left = remove_node(node->left);

        else
            node->right = remove_node(node->right);
    }

    return t;
}
