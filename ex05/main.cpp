#include <iostream>
#include <cstdlib>
#include <vector>
#include <typeinfo>

int main(){
    auto s1 {1};
    auto s2 = {12,3,4,5,6};

    std::cout<<"type of s1:"<<typeid(s1).name()
             <<"\ntype of s2:"<<typeid(s2).name()
             <<std::endl;
    for( auto v: s2){
        std::cout<<v<<std::endl;
    }
    //std::cout<<s2;
    return 0;
}
