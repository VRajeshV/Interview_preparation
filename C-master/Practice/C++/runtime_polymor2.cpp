#include<iostream>

using namespace std;

class Base
{
    int a=9;
    public:

    void input(int l)
    {
        a = l;
    }

    virtual void display()
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

    void display() override
    {
        cout<<"Derive "<<a<<endl;
    }
};

int main()
{
    Base* obj1;
    Derive obj;
    obj1 = &obj;
    // compile time poly
    obj.input(2);
    // runtime poly
    obj1->display();
    obj1->Base::display();    
}
