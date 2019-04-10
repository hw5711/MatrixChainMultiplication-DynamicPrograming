#include <iostream>
using namespace std;

const int inputMatricNum = 7;
const int COLS = 6;
const int ROWS = 6;

void Matrix_Chain(int* p, int n, int m[][COLS] ,int s[][COLS])
{
    int i,j,l,tmp;
    for (int i = 1; i <= n; i++)
    {
        m[i][i] = 0;
    }
    for (l = 2; l <= n; l++)
    {
        for (i = 1; i <= n - l + 1; i++)
        {
            j = i + l - 1;
            m[i][j] = m[i][i] + m[i + 1][j] + p[i - 1] * p[i] * p[j];
            s[i][j] = i;
            for (int k = i + 1; k < j; k++)
            {
                tmp = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (tmp < m[i][j])
                {
                    m[i][j] = tmp;
                    s[i][j] = k;
                }
            }
        }
    }
}

void print_optimal_parens(int s[][COLS], int i, int j)
{
    if (i == j)
    {
        cout << "A" << i;
    }
    else
    {
        cout << "(";
        print_optimal_parens(s, i, s[i][j]);
        print_optimal_parens(s, s[i][j] + 1, j);
        cout << ")";
    }
}
int main()
{
    int p[inputMatricNum]={10,35,15,5,10,20,25};
    int m[ROWS][COLS];
    int s[ROWS][COLS];

    Matrix_Chain(p,ROWS, m, s);
    cout << endl;
    print_optimal_parens(s,1,COLS);
    cout << endl;
    return 0;
}
