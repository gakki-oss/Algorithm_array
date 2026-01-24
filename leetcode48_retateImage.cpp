#include<iostream>
#include<vector>

using namespace std;


//借助中间矩阵变量来存储旋转后的新矩阵，在完成后将新矩阵复制给原矩阵
class Solution1 {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> matrix_new(n,vector<int>(n,0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matrix_new[j][n - i - 1] = matrix[i][j];
            }
        }
        matrix = matrix_new;
        }
};


//原地旋转 
class Solution2 {
    public:
    void retate2(vector<vector<int>>& matrix1)
    {
        int n = matrix1.size();
        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < n;j++)
            {
                swap(matrix1[i][j], matrix1[n - i - 1][j]);
            }
        }
        for (int i = 0; i < n;i++)
        {
            for (int j = 0 ; j < i ;j++)
            {
                swap(matrix1[i][j],matrix1[j][i]);
            }
        }
    }
};

int main()
{
    vector<vector<int>> matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> matrix2{{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    Solution1 s1;
    s1.rotate(matrix);
    //法1
    for (auto &row : matrix)
    {
        for(auto &col : row)
        {
            cout << col << " "; 
        }
        cout << endl;
    }
    cout << endl;
    //法2
    Solution2 s2;
    s2.retate2(matrix2);
    for (auto &row1 : matrix2)
    {
        for(auto &col2 : row1)
        {
            cout << col2 << " "; 
        }
        cout << endl;
    }

        return 0;
}
