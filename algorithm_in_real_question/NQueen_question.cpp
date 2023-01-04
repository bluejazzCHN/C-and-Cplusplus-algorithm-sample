#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<string>> res;

//函数声明
vector<vector<string>> solveNQueens(int n);
//回溯函数，采用递归方式，结构为：检查终止条件-遍历（做选择-递归-撤销选择）
void backtrack(vector<string> &board, int row);
//验证规则（有三个规则：同一行，同一列，两个对角线）
bool isValidQ(vector<string> board, int row, int col);


vector<vector<string>> solveNQueens(int n)
{
    string row(n, '.');
    vector<string> board(n, row);
    backtrack(board, 0);
    return res;
}

void backtrack(vector<string> &board, int row)
{
    // 判断结束
    if (row == board.size())
    {
        res.push_back(board);
        return;
    }

    int n = board[row].size();

    for (int col = 0; col < n; col++)
    {
        // 确认这个点是否可以放Q
        if (!isValidQ(board, row, col))
        {
            continue;
        }
        board[row][col] = 'Q';
        backtrack(board, row + 1);
        board[row][col] = '.';
    }
}

bool isValidQ(vector<string> board, int row, int col)
{
    int n = board.size();
    // 检查某列是否有冲突
    for (int i = 0; i < row; i++)
    {
        // 第一个规则：列上只能有一个Q
        if (board[i][col] == 'Q')
        {
            return false;
        }
        // 第二个规则：右上对角线上只能有一个Q
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        {
            if (board[i][j] == 'Q')
            {
                return false;
            }
        }
        // 第三个规则：左上对角线上只能有一个Q
        for (int i = row - 1, j = col - 1; i >= 0 && j < n; i--, j--)
        {
            if (board[i][j] == 'Q')
            {
                return false;
            }
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    int row = 5;

    solveNQueens(row);
    cout << "Result of Queen board:" << endl;
    for (int i = 0;i<res.size();i++)
    {
        cout<<"---"<<" No "<<i<<" ---"<<endl;
        for (string row : res[i])
        {
            for (char c : row)
            {
                cout << c<<" ";
            }
            cout << endl;
        }
        cout<<endl;
    }

    return 0;
}
