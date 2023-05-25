#include <iostream>
#include <vector>
#include <string>
using namespace std;

class NQueens
{
    int n;

public:
    NQueens(int n)
    {
        this->n = n;
    }
    bool isSafe(int r, int c, vector<string> board);
    bool isSafeColumn(int c, vector<string> board);
    bool isSafeDiagonal(int r, int c, vector<string> board);
    bool isSafeRow(int r, vector<string> board);
    void solve(int c, vector<string> &board, vector<vector<string>> &ans);
    vector<vector<string>> solveQueens();
    void display(vector<vector<string>> v);
};

bool NQueens::isSafeColumn(int c, vector<string> board)
{
    for (int r = 0; r < n; r++)
    {
        if (board[r][c] == 'Q')
            return false;
    }
    return true;
}

bool NQueens::isSafeDiagonal(int r, int c, vector<string> board)
{
    int i, j;
    for (i = r, j = c; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
            return false;
    }
    for (i = r, j = c; i < n && j >= 0; i++, j--)
    {
        if (board[i][j] == 'Q')
            return false;
    }
    return true;
}

bool NQueens::isSafeRow(int r, vector<string> board)
{
    for (int c = 0; c < n; c++)
    {
        if (board[r][c] == 'Q')
            return false;
    }
    return true;
}

bool NQueens::isSafe(int r, int c, vector<string> board)
{
    return isSafeColumn(c, board) && isSafeDiagonal(r, c, board) && isSafeRow(r, board);
}

void NQueens::solve(int c, vector<string> &board, vector<vector<string>> &ans)
{
    if (c == n)
    {
        ans.push_back(board);
        return;
    }

    for (int r = 0; r < n; r++)
    {
        if (isSafe(r, c, board))
        {
            board[r][c] = 'Q';
            solve(c + 1, board, ans);
            board[r][c] = '-';
        }
    }
}

vector<vector<string>> NQueens::solveQueens()
{
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '-'));
    solve(0, board, ans);
    return ans;
}

void NQueens::display(vector<vector<string>> v)
{
    cout << "--------------------------------" << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << "Arrangement " << i + 1 << endl;
        for (int j = 0; j < v[0].size(); j++)
        {
            cout << v[i][j] << endl;
        }
        cout << endl;
    }
    cout << "--------------------------------" << endl;
}

int main()
{
    int n;
    cout << "Enter the number of queens: ";
    cin >> n;
    NQueens q(n);
    vector<vector<string>> v = q.solveQueens();
    q.display(v);
    return 0;
}
