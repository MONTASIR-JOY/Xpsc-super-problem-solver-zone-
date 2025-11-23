#include<bits/stdc++.h>
using namespace std;
class Vector
{
    protected:
        int *arr;
        int size;
    public:
        Vector(int s = 0)
        {
            size = s;
            arr = new int[size];
        }
        Vector(Vector &v)
        {
            size = v.size;
            arr = new int[size];
            for (int i = 0; i < size;i++)
            {
                arr[i] = v.arr[i];
            }
        }
        ~Vector()
        {
            delete [] arr;
        }
        void input()
        {
            for (int i = 0; i < size;i++)
            {
                cin >> arr[i];
            }
        }
        void display()
        {
            for (int i = 0; i < size;i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        int sum()
        {
            int s = 0;
            for (int i = 0; i < size;i++)
            {
                s += arr[i];
            }
            return s;
        }
        Vector operator+(Vector &v)
        {
            Vector temp(size);
            for (int i = 0; i < size;i++)
            {
                temp.arr[i] = arr[i] + v.arr[i];
            }
            return temp;
        }
};
class resultvector:public Vector{
    public:
        resultvector(int s = 0)
        {
            Vector(s);
        }
        friend resultvector compare(resultvector r1, resultvector r2);
};
resultvector compare(resultvector r1, resultvector r2)
{
        if(r1.sum()>=r2.sum())
        {
            return r1;
        }
        else{
            return r2;
        }
    }
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n1, n2;
    cin >> n1 >> n2;
    resultvector r1(n1), r2(n2);
    r1.input();
    r2.input();
    resultvector res = compare(r1, r2);
    res.display();
    return 0;
}