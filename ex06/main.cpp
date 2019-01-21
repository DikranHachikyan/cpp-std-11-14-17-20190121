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
    auto w2 = foo();
    w2._label = "Ok";
    std::cout<<"wdg label:"<<wdg._label
            <<"\n w2 label:"<<w2._label
            <<std::endl;
    auto w3 = foo2();
    //w3->_label = "Ok"; //Error
    auto &w4 = foo();
    //w4._label = "Ok"; //Error
    std::cout<<"type of w1:"<<typeid(w1).name()<<std::endl;
    std::cout<<"type of w2:"<<typeid(w2).name()<<std::endl;
    std::cout<<"type of w3:"<<typeid(w3).name()<<std::endl;
    std::cout<<"type of w4:"<<typeid(w4).name()<<std::endl;
    return 0;
}
