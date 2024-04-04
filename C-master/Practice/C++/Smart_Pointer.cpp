#include<iostream>
#include<memory>
using namespace std;

class Addition
{

    int a;
    int b;

    public:

    Addition(int l,int m)
    {
        a = l;
        b = m;
    }

    int result()
    {
        return a+b;
    }
};


int main()
{
    //     unique Pointer
    //int a = 1, b=2;
    unique_ptr<Addition> P1(new Addition(1,3));
    cout<< P1->result()<<endl;

    unique_ptr<Addition> P2;

    P2 = move(P1);

    cout<<P2->result()<<endl;
    //cout<<P1->result()<<endl;

    //   shared Pointer

    shared_ptr<Addition> P3(new Addition(3,4));

    cout<<"P3:: "<<P3->result()<<endl;

    shared_ptr<Addition> P4;

    P4 = P3;

    cout<<"P4:: "<<P4->result()<<endl;
    cout<<"P3:: "<<P3->result()<<endl;

    cout<<"count "<<P4.use_count()<<endl;

    // weak pointer

    weak_ptr<Addition> P5(new Addition(5,6));

    weak_ptr<Addition> P6(P5);


    

}