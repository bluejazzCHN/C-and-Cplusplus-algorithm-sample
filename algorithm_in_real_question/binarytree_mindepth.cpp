#include <iostream>
#include <queue>

using namespace std;

class TreeNode
{
public:
    int id;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    TreeNode(int num) : id(num) {}
    TreeNode(int num, TreeNode *r, TreeNode *l) : id(num), left(l), right(r) {}
};

int minDepth(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    queue<TreeNode> q;
    q.push(*root);
    int depth = 1;
    while (!q.empty())
    {
        int sz = q.size();
        for (int i = 0; i < sz; i++)
        {
            TreeNode cur = q.front();
            q.pop();
            // tree的分支是否结束的判断条件
            if (cur.left == nullptr && cur.right == nullptr)
            {
                return depth;
            }
            // 遍历左分支
            if (cur.left != nullptr)
            {
                q.push(*cur.left);
            }
            // 遍历右分支
            if (cur.right != nullptr)
            {
                q.push(*cur.right);
            }
        }
        depth++;
    }
    return depth;
}

int main(int argc, char const *argv[])
{
    /*构造一个tree 如下图：
                    Roor(1)
                      |
                |           |
              r_l(2)       r_r(3)
            |       |
       r_l_l(21)  r_l_r(22)
    */
    TreeNode *root = new TreeNode(1);
    TreeNode *r_r = new TreeNode(3);
    TreeNode *r_l_l = new TreeNode(21);
    TreeNode *r_l_r = new TreeNode(22);
    TreeNode *r_l = new TreeNode(2, r_l_l, r_l_r);

    root->right = r_r;
    root->left = r_l;
    // cout << (root->right == nullptr) << root->right->id << endl;
    cout << "min depth: " << minDepth(root) << endl;
    return 0;
}
