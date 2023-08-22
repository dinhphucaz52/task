#include <iostream>
#include <vector>


using namespace std;

vector<int> values = {1, 2, 5};
int res[500];

void xuat(int pos)
{
    for (int i = 1; i < pos; i++)
        cout << res[i] << " ";
    cout << endl;
}

void backtrack(int val, int pos)
{
    if (val == 0)
        return xuat(pos), void();
    for (int x : values)
    {
        if (x > val)
            return;
        if (res[pos-1] > x)    
            continue;
        res[pos] = x;
        backtrack(val - x, pos + 1);
    }
}

int main()
{
    backtrack(10, 1);
}