struct TreeNode{
    int key;
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int k, int v) : key(k), val(v), left(nullptr), right(nullptr){}


};

class TreeMap {

private:

TreeNode* root;

TreeNode* removeHelper(TreeNode* node, int key){

    if (node == nullptr) {
    throw std::runtime_error("key not found");
}
    if (key < node->key){
       node->left = removeHelper(node->left,key);
    }

    else if (key> node->key){
        node->right = removeHelper(node->right, key);
    }

    else{
        // found

        if (node->left == nullptr){
            TreeNode* right = node->right;
            delete node;
            return right;
        }

        else if (node->right == nullptr){
            TreeNode* left = node->left;
            delete node;
            return left;
        }

        TreeNode* successor = node->right;
        while (successor->left != nullptr) successor = successor->left;
        node ->key = successor->key;

        node->val = successor->val;

        node->right = removeMin(node->right);



    }
    return node;
}

TreeNode* insertHelper(TreeNode* node, int key, int val) {
    if (node == nullptr) {
        return  new TreeNode(key,val);

    }

    else if (key < node->key){
        node -> left = insertHelper(node ->left, key,val);
        
    }

    else if (key > node -> key){
        node -> right = insertHelper(node ->right, key,val);

    }

    else {
        node -> val = val;

    }

    return node;


}

TreeNode* removeMin(TreeNode* node){
    if (node->left == nullptr){
            TreeNode* right = node->right;
            delete node;
            return right;
        }
     node->left = removeMin(node->left);
        return node;


}

void inorderHelper(TreeNode* node, std::vector<int>& result) {
        if (node == nullptr) return;
        inorderHelper(node->left, result);
        result.push_back(node->key);
        inorderHelper(node->right, result);
    }
 
    void destroy(TreeNode* node) {
        if (node == nullptr) return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

public:
    
    TreeMap() : root(nullptr) {}

    void insert(int key, int val) {
        root = insertHelper(root,key,val);
    }

    int get(int key) {
        TreeNode* node = root;

        while (node != nullptr) {
            if (node -> key > key){
                node = node->left;
            }
            else if (node -> key<key){
                node = node->right;
            }
            else{
                return node->val;
            }
        }
    throw std::runtime_error("key not found");
    }

    int getMin() {
        if (root == nullptr) throw std::runtime_error("tree is empty");
        TreeNode* node = root;
        while (node->left != nullptr) node = node->left;
        return node-> val;

    }

    int getMax() {
        if (root == nullptr) throw std::runtime_error("tree is empty");
        TreeNode* node = root;
        while (node->right != nullptr) node = node->right;
        return node-> val;

    }

    void remove(int key) {

        root=  removeHelper(root,key);

    
    }

    std::vector<int> getInorderKeys() {
    std::vector<int> result;
    inorderHelper(root, result);
    return result;
    }

};
