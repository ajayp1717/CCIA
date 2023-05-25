#include <iostream>
#include <vector>
#include <string>
using namespace std;

class NQueues
{
    int n;

public:
    NQueues(int n)
    {
        this->n = n;
    }
    bool isSafe(int r, int c, vector<string> board);
    void solve(int c, vector<string> &board, vector<vector<string>> &ans);
    vector<vector<string>> solveQueue();
    void display(vector<vector<string>> v);
};

bool NQueues::isSafe(int r, int c, vector<string> board)
{
    int tmpr = r, tmpc = c;
    while (r >= 0 && c >= 0)
    {
        if (board[r][c] == 'Q')
            return false;
        r--;
        c--;
    }
    c = tmpc;
    r = tmpr;
    while (c >= 0)
    {
        if (board[r][c] == 'Q')
            return false;
        c--;
    }
    c = tmpc;
    r = tmpr;
    while (r < n && c >= 0)
    {
        if (board[r][c] == 'Q')
            return false;
        r++;
        c--;
    }
    return true;
}

void NQueues::solve(int c, vector<string> &board, vector<vector<string>> &ans)
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

vector<vector<string>> NQueues::solveQueue()
{
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '-');
    for (int i = 0; i < n; i++)
    {
        board[i] = s;
    }
    solve(0, board, ans);
    return ans;
}

void NQueues::display(vector<vector<string>> v)
{
    cout << "--------------------------------" << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << "Aragement " << i + 1 << endl;
        for (int j = 0; j < v[0].size(); j++)
        {
            cout << v[i][j];
            cout << endl;
        }
        cout << endl;
    }
    cout << "--------------------------------" << endl;
}

int main()
{
    int n;
    cout << "Enter the number of queues" << endl;
    cin >> n;
    NQueues q(n);
    vector<vector<string>> v = q.solveQueue();
    q.display(v);
    return 0;
}