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

    // Here we are showing the unique_pointer is pointing to P1.
    // But, then we remove P1 and assign P2 so the pointer now points to P2.
    
    unique_ptr<Addition> P1(new Addition(1,3));
    cout<< P1->result()<<endl;

    unique_ptr<Addition> P2;

    P2 = move(P1);

    cout<<P2->result()<<endl;
    //cout<<P1->result()<<endl;

    //   shared Pointer
    //Here both smart pointer P3 and P4 are pointing to the
    // object Addition to which they both maintain a reference of the object

    shared_ptr<Addition> P3(new Addition(3,4));

    cout<<"P3:: "<<P3->result()<<endl;

    shared_ptr<Addition> P4;

    P4 = P3;

    cout<<"P4:: "<<P4->result()<<endl;
    cout<<"P3:: "<<P3->result()<<endl;

    cout<<"count "<<P4.use_count()<<endl;

    // weak pointer

    // Here both smart pointer P3 and P6 are pointing to the
    // object Addition to which they both does not maintain a reference of the object

    weak_ptr<Addition> P6(P3);

    cout<<"P4:: count"<<P4.use_count()<<endl;

}