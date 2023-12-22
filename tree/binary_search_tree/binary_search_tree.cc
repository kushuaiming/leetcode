template <class T>
class BST {
 public:
  BST() : root_(nullptr) {}
  ~BST() { root_ = MakeEmpty(root_); }
  void Insert(T x) { Insert(root_, x); }
  void Remove(T x) { Remove(root_, x); }

 private:
  struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
  };

  TreeNode* MakeEmpty(TreeNode* t) {
    if (t == nullptr) {
      return nullptr;
    }
    MakeEmpty(t->left);
    MakeEmpty(t->right);
    delete t;
    return nullptr;
  }

  TreeNode* Insert(TreeNode* t, T x) {
    if (t == nullptr) {
      t = new TreeNode(x);
    } else if (x < t->val) {
      t->left = Insert(t->left, x);
    } else {
      t->right = Insert(t->right, x);
    }
  }

  TreeNode* Find(TreeNode* t, T x) {
    if (t == nullptr) {
      return nullptr
    }
    if (x < t->val) {
      return Find(t->left, x);
    }
    if (x > t->val) {
      return Find(t->right, x);
    }
    return t;
  }

  TreeNode* FindMin(TreeNode* t) {
    if (t == nullptr || t->left == nullptr) {
      return t;
    }
    return FindMin(t->left);
  }

  TreeNode* FindMax(TreeNode* t) {
    if (t == nullptr || t->right == nullptr) {
      return t;
    }
    return FindMax(t->right);
  }

  TreeNode* Remove(TreeNode* t, T x) {
    TreeNode* temp;
    if (t == nullptr) {
      return nullptr;
    } else if (x < t->val) {
      t->left = Remove(t->left, x);
    } else if (x > t->val) {
      t->right = Remove(t->right, x);
    } else if (t->left && t->right) {
      temp = FindMin(t->right);
      t->val = temp->val;
      t->right = Remove(t->right, t->val);
    } else {
      temp = t;
      if (t->left == nullptr) {
        t = t->right;
      } else if (t->right == nullptr) {
        t = t->left;
      }
      delete temp;
    }
    return t;
  }

  TreeNode* root_;
};
