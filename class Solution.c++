class Solution
{
public:
    void findKDistance(Node* root, int k, vector<int>& path, vector<bool>& visited, int depth, int& count) {
        if (root == nullptr)
            return;
        path.push_back(root->data);
        visited.push_back(false);
        if (root->left == nullptr && root->right == nullptr) {
            int index = depth - k;
            if (index >= 0 && !visited[index]) {
                visited[index] = true;
                count++;
            }
        }
        findKDistance(root->left, k, path, visited, depth + 1, count);
        findKDistance(root->right, k, path, visited, depth + 1, count);
        path.pop_back();
        visited.pop_back();
    }
    int printKDistantfromLeaf(Node* root, int k)
    {
        if (root == nullptr)
            return 0;

        vector<int> path;
        vector<bool> visited;
        int count = 0;

        findKDistance(root, k, path, visited, 0, count);

        return count;
    }
};