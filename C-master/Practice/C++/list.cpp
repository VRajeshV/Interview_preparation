#include <iostream>
#include <list>

int main() {
   // create a list of integers
   std::list<int> l;

   // add some elements to the list
   l.push_back(5);
   l.push_back(3);
   l.push_back(8);

   // insert an element at the front of the list
   l.push_front(1);

   // remove an element from the list
   l.pop_back();

   // print the elements in the list
   std::cout << "List: ";
   for (auto i : l) {
       std::cout << i << " ";
   }
   std::cout << std::endl;

   return 0;
}