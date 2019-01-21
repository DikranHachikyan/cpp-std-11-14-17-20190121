#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include <algorithm>

int x = 100;

int main(){
   static int value = 12;
   const int  k = 3;
   //int x=1;
   auto show = [=]{
       x =1;
       value = 2;
       std::cout<<"global var:x="<<x
                <<"\nstatic var: value="<<value
                <<"\nconst int var:k="<<k
                <<std::endl;
    };

    show();
    return 0;
}
