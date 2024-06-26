class Solution
{
public:
    // Utility function to perform DFS traversal and find nodes at distance k from leaf nodes
    void findKDistance(Node* root, int k, vector<int>& path, vector<bool>& visited, int depth, int& count) {
        if (root == nullptr)
            return;

        // Add current node to the path
        path.push_back(root->data);
        visited.push_back(false);

        // If we reached a leaf node
        if (root->left == nullptr && root->right == nullptr) {
            // Calculate the distance of each ancestor node from the leaf node
            int index = depth - k;
            if (index >= 0 && !visited[index]) {
                visited[index] = true;
                count++;
            }
        }

        // Recursive call for left and right subtrees
        findKDistance(root->left, k, path, visited, depth + 1, count);
        findKDistance(root->right, k, path, visited, depth + 1, count);

        // Remove current node from the path
        path.pop_back();
        visited.pop_back();
    }

    //Function to return count of nodes at a given distance from leaf nodes.
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