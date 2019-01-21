#include <iostream>
#include <cstdlib>
#include <vector>
#include <typeinfo>

class Widget{};
struct Point{
        int x;
        int y;
};

struct{
        int x;
        int y;
} point {2,3};

int main(){
    Widget *p = new Widget;
    auto x {10.0F};
    auto w {new Widget};
    auto pn { Point {}};

    //auto pn1 { struct {int x} p{};};

    std::cout<<"type of x:"<<typeid(x).name()<<std::endl;
    std::cout<<"type of w:"<<typeid(w).name()<<std::endl;
    std::cout<<"type of pn:"<<typeid(pn).name()<<std::endl;

    return 0;
}
