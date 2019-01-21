#include <iostream>
#include <cstdlib>
class Widget {
    private:
        int _x {5};
        int _y = 6; //Ok!
    public:
        Widget( int x, int y):_x {x}, _y {y} {
            std::cout<<"Ctor Widget 1"<<std::endl;
        }
        //Widget():Widget(0,0){
        //    std::cout<<"Ctor Widget 2"<<std::endl;
        //}
        Widget(){
            std::cout<<"Ctor Widget 2"<<std::endl;
        }

        void show(){
            std::cout<<"x="<<_x<<" y="<<_y<<std::endl;
        }
};

int main(){
    Widget w0 {}; //Ok
    Widget w1;
    Widget w2 {3,4};

    w0.show();
    w1.show();
    w2.show();
    return 0;
}
