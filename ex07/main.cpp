#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

class Widget {
    public:
        std::string _label {"default value"};
        Widget(){
            std::cout<<"Ctor Widget"<<std::endl;
        }
        //Copy Ctor
        Widget(const Widget &w){
            _label = w._label;
            std::cout<<"Copy Ctor Widget"<<std::endl;
        }
        //Copy Assignment
        Widget &operator=(const Widget &w){
            _label = w._label;
            std::cout<<"Copy Assignment"<<std::endl;
            return *this;
        }
};

const Widget wdg {};

const Widget &foo(){
    return wdg;
}
const Widget *foo2(){
    return &wdg;
}

int main(){
    const Widget &w1 = foo();
    //w1._label = "Ok"; //Error
    decltype ( foo() ) w2 = foo();
    //w2._label = "Ok";
    decltype ( w1 )  w3 = foo();
    decltype ( foo2()) w4 = foo2();
    std::cout<<"type of w1:"<<typeid(w1).name()<<std::endl;
    std::cout<<"type of w2:"<<typeid(w2).name()<<std::endl;
    std::cout<<"type of w3:"<<typeid(w3).name()<<std::endl;
    std::cout<<"type of w4:"<<typeid(w4).name()<<std::endl;
    return 0;
}
