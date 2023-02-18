#include "iostream"
#include "vector"
using namespace std;

int demo1(vector<int> &v, int target)
{ // 暴力解法
    int size = v.size();
    for (int i = 0; i < size; i++)
    {
        if (v[i] == target)
        {
            for (int j = i; j < size; j++)
            {
                v[j] = v[j + 1];
            }
        }
        i--;
        size--;
    }
    return size;
}

int main()
{
    vector<int> v;
    int target = 3;
    v.push_back(3);
    v.push_back(2);
    v.push_back(2);
    v.push_back(3);
    int size = demo1(v, target);
    cout << "size=" << size << endl;
}