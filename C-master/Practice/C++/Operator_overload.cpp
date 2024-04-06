#include<iostream>

using namespace std;

class Addition
{
    int l;
    public:

    Addition()
    {

    }
    Addition(int a)
    {
        l = a;
    }

    Addition operator+(Addition const& tmp)
    {
        Addition res;

        res.l = tmp.l + l ;
  
        return res;
    }

    int result()
    {
        return l;
    }

};


int main()
{
    Addition obj1(1) , obj2(3),obj3;

    obj3 = obj1 + obj2;

    cout<<"obj3 result "<<obj3.result()<<endl;

}

