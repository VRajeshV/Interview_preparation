#include<iostream>
using namespace std;

class funoverload
{
    public:

    void fun(string s)
    {
        cout<< s <<endl;
    }

    void fun(int i)
    {
        cout<< i <<endl;
    }
};


int main()
{
    funoverload obj;

    obj.fun(1);
    obj.fun("string");
    
}

