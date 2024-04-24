#include <iostream> 

#include <iterator> 

#include <map> 

using namespace std; 

int main() 

{

    map<int, int> test; 
    map<int,int> test1;

    // inserting elements 

    test1.insert(pair<int,int>(1,2));
    test1.insert(pair<int,int>(10,2));

    test.insert(pair<int, int>(1, 2)); 

    test.insert(pair<int, int>(2, 3)); 

    map<int, int>::iterator itr; 

    for (itr = test.begin(); itr != test.end(); ++itr) { 

        cout << itr->first <<endl; 

        cout << itr->second << '\n'; 

    } 

    map<int,int>::iterator itr1;

    for(itr=test1.begin();itr1 != test1.end();itr++)
    {
        cout <<itr1->first;
        cout <<itr1->second;
    }

 return 0;

)