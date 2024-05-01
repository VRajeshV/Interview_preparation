#include<iostream>
#include<mutex>
using namespace std;

mutex mutex_loc;

class Singleton
{
    private:
    static Singleton *Instance;
    int val = 0;
    Singleton()
    {

    }
    public:
    Singleton(const Singleton& obj) = delete;
    static Singleton *getInsatance()
    {
        lock_guard<mutex> lock(mutex_loc);
        if(Instance == NULL)
        {
            Instance = new Singleton();
        }
        return Instance;
   }

   void setval(int a)
   {
      val = a;
   }

   int getval()
   {
    return val;
   }
};

Singleton* Singleton::Instance= NULL;

int main()
{
    Singleton *obj,*obj1;
    obj = Singleton::getInsatance();
    obj->setval(10);
    cout<<"val "<<obj->getval()<<endl;
    obj1 = Singleton::getInsatance();
    cout<<"val "<<obj1->getval()<<endl;
}