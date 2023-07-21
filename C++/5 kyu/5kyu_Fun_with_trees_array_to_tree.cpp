class Solution {
public:
    static TreeNode* arrayToTree(const std::vector<int>& arr) {
        if (arr.empty()) {
            return nullptr;
        }

        return arrayToTreeRecursive(arr, 0);
    }

private:
    static TreeNode* arrayToTreeRecursive(const std::vector<int>& arr, int index) {
        if (index >= arr.size()) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(arr[index]);
        root->m_left = arrayToTreeRecursive(arr, 2 * index + 1);
        root->m_right = arrayToTreeRecursive(arr, 2 * index + 2);

        return root;
    }
};