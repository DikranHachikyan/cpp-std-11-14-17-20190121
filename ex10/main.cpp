#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

int main(){
    auto show = [](){
      std::cout<<"Lambda Expression"<<std::endl;
    };
    auto show1 = []{
        std::cout<<"Lambda Expression"<<std::endl;
    };
    auto show2 = []()->void{
        std::cout<<"Lambda Expression"<<std::endl;
    };

    show();
    show1();
    show2();
    return 0;
}
