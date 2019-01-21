#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
void foo(){
    std::cout<<"foo"<<std::endl;
}
int main(){
    std::string s1 = "Hello Lambda";
    int k = 2;

    auto show = [](const std::string &message){
      std::cout<<message<<std::endl;
    };

    show("Lambda Expression with Param");

    //Capturing
    auto showCap = [s1,k]{
        foo();
        std::cout<<"k="<<k<<" s1="<<s1<<std::endl;
    };

    showCap();
    auto showMut = [&]{
        k=100;
        s1 = "mutable lambda";
    };

    showMut();
    std::cout<<"k="<<k<<" s1="<<s1<<std::endl;

    auto showMix = [=,&k]{
        k++;
        std::cout<<"By Value s1:"<<s1
                 <<"\nBy   Ref k:"<<k
                 <<std::endl;
    };

    showMix();
    return 0;
}
