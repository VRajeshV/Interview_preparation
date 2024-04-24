#include<iostream>  

#include<vector>  

using namespace std;  

int main()  

{  

vector <string> vec_1;  

vector <int> intvec;

intvec.push_back(10);
intvec.push_back(11);

vec_1.push_back("sample code");  

vec_1.push_back("change example");  

for(vector <string>::iterator i=vec_1.begin();i!=vec_1.end();++i)  
{
    cout<<*i;  
}
cout<<endl;
for(vector <int>::iterator i=intvec.begin();i!=intvec.end();i++)
{
    cout << *i;
}

cout<<endl;
return 0;   

} 