#include<iostream>

using namespace std;

class Base
{
    int a;
    public:

    void input(int l)
    {
        a = l;
    }

    void display()
    {
        cout<<"Base "<<a<<endl;
    }
};

class Derive : public Base
{
    int a;
    public:

    void input(int l)
    {
        a = l;
    }

    void display()
    {
        cout<<"Derive "<<a<<endl;
    }
};

int main()
{
    Derive obj;

    obj.input(2);
    obj.display();


}