#include<iostream>
using namespace std;

class Reference
{
    private:
    int a,b;
    public:

    void Ref(int &x,int &y)
    {
        x = 30;
        a = x;
        b = y;
    }
    void print()
    {
        cout<<"a :: "<<a<<"b :: "<<b<<endl;
    }
};

int main()
{
    int a = 10;
    Reference obj;
    obj.Ref(a,a);
    obj.print();
}