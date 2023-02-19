#include "iostream"
#include "vector"
using namespace std;

int demo1(vector<int> &v, int target)
{ // 暴力解法
    int size = v.size();
    for (int i = 0; i < (int)v.size(); i++)
    {
        if (v[i] == target)
        {
            for (int j = i; j < size; j++)
            {
                v[j] = v[j + 1];
            }
            i--;
            size--;
        }
    }
    return size;
}

int demo2(vector<int> &v, int target)
{ // 双指针
    int fast = 0;
    int slow = 0;
    int size = v.size();
    for (fast = 0; fast < size; fast++)
    {
        if (v[fast] != target)
        {
            v[slow] = v[fast];
            slow++;
        }
    }
    return slow;
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