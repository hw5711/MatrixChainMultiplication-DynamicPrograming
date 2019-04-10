#include <iostream>
using namespace std;

const int inputMatricNum1 = 7;
const int inputMatricNum2 = 6;

const int COLS1 = 6;
const int ROWS1 = 6;
const int COLS2 = 5;
const int ROWS2 = 5;

// With 6 matrixes
void Matrix_Chain1(int* p, int n, int m[][COLS1] ,int s[][COLS1])
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

// With 6 matrixes
void print_optimal_parens1(int s[][COLS1], int i, int j)
{
    if (i == j)
    {
        cout << "A" << i;
    }
    else
    {
        cout << "(";
        print_optimal_parens1(s, i, s[i][j]);
        print_optimal_parens1(s, s[i][j] + 1, j);
        cout << ")";
    }
}

// With 5 matrixes
void Matrix_Chain2(int* p, int n, int m[][COLS2] ,int s[][COLS2])
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

// With 5 matrixes
void print_optimal_parens2(int s[][COLS2], int i, int j)
{
    if (i == j)
    {
        cout << "A" << i;
    }
    else
    {
        cout << "(";
        print_optimal_parens2(s, i, s[i][j]);
        print_optimal_parens2(s, s[i][j] + 1, j);
        cout << ")";
    }
}


int main()
{
    // Test case 1
    int p1[inputMatricNum1]={10,35,15,5,10,20,25};
    int m1[ROWS1][COLS1];
    int s1[ROWS1][COLS1];
    cout << "With test case #1: ";
    for(int index = 0; index < inputMatricNum1-1; index++)
    {
      cout << "A"<< (index+1)<< "(" << p1[index] << "x" << p1[index+1] << ") ";
    }
    Matrix_Chain1(p1, ROWS1, m1, s1);
    cout << "\nResult is: "<< endl;
    print_optimal_parens1(s1, 1, COLS1);
    cout << endl<< endl;

    // Test case 2
    int p2[inputMatricNum2]={10,35,15,5,10,20};
    int m2[ROWS2][COLS2];
    int s2[ROWS2][COLS2];
    cout << "\nWith test case #2: ";
    for(int index = 0; index < inputMatricNum2-1; index++)
    {
      cout << "A"<< (index+1)<< "(" << p2[index] << "x" << p2[index+1] << ") ";
    }
    Matrix_Chain2(p2, ROWS2, m2, s2);
    cout << "\nResult is: "<< endl;
    print_optimal_parens2(s2, 1, COLS2);
    cout << endl << endl;

    // Test case 3
    int p3[inputMatricNum1]={55,35,5,15,60,20,25};
    int m3[ROWS1][COLS1];
    int s3[ROWS1][COLS1];
    cout << "With test case #3: ";
    for(int index = 0; index < inputMatricNum1-1; index++)
    {
      cout << "A"<< (index+1)<< "(" << p3[index] << "x" << p3[index+1] << ") ";
    }
    Matrix_Chain1(p3, ROWS1, m3, s3);
    cout << "\nResult is: "<< endl;
    print_optimal_parens1(s3, 1, COLS1);
    cout << endl<< endl;

    // Test case 4
    int p4[inputMatricNum2]={1,2,3,4,5,6};
    int m4[ROWS2][COLS2];
    int s4[ROWS2][COLS2];
    cout << "\nWith test case #4: ";
    for(int index = 0; index < inputMatricNum2-1; index++)
    {
      cout << "A"<< (index+1)<< "(" << p4[index] << "x" << p4[index+1] << ") ";
    }
    Matrix_Chain2(p4, ROWS2, m4, s4);
    cout << "\nResult is: "<< endl;
    print_optimal_parens2(s4, 1, COLS2);
    cout << endl << endl;

    // Test case 5 from the book
    cout << "Here is the expamle from the book: "<< endl;
    int p5[inputMatricNum1]={30,35,15,5,10,20,25};
    int m5[ROWS1][COLS1];
    int s5[ROWS1][COLS1];
    cout << "With test case #5: ";
    for(int index = 0; index < inputMatricNum1-1; index++)
    {
      cout << "A"<< (index+1)<< "(" << p5[index] << "x" << p5[index+1] << ") ";
    }
    Matrix_Chain1(p5, ROWS1, m5, s5);
    cout << "\nResult is: "<< endl;
    print_optimal_parens1(s5, 1, COLS1);
    cout << endl<< endl;

    return 0;
}
