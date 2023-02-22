#include "iostream"
#include "vector"
using namespace std;

vector<vector<int>> demo(int n)
{
    vector<vector<int>> v(n, vector<int>(n, 0));
    int startX = 0;
    int startY = 0;
    int mid = n / 2;
    int offset = 1;
    int loop = 0;
    int count = 1;
    int i, j;
    while (loop--)
    {
        i = startX;
        j = startY;
        // 从左到右
        for (j = startY; j < n - offset; j++)
        {
            v[startX][j] = count++;
            // count++;
        }
        // 从上到下
        for (i = startX; i < n - offset; i++)
        {
            v[i][j] = count++;
        }
        // 从右到左
        for (; j > startY; j--)
        {
            v[i][j] = count++;
        }
        // 从下到上
        for (; i > startX; i--)
        {
            v[i][j] = count++;
        }
        startX++;
        startY++;
        offset++;
    }
    if (n % 2 == 1)
    {
        v[mid][mid] = count;
    }
    return v;
}

int main(){
    
}