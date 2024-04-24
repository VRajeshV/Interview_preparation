#include <bits/stdc++.h> 

using namespace std; 

class parent

{ 

public: 

    virtual void print() 

    { cout<< "base class"; } 

}; 

class child:public parent

{ 

public: 

    void print() 

    { cout<< "derived class"; } 

}; 

int main()  

{ 

    parent *p; 

    child c; 

    p = &c; 

    //virtual function, binded at runtime (Runtime polymorphism) 

    p->print();  

    return 0; 

} 