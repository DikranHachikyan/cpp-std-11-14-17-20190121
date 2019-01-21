#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
class GenericWidget{
    public:
        virtual ~GenericWidget(){
            std::cout<<"Dtor GW"<<std::endl;
        }
        virtual void show(){
            std::cout<<"generic widget"<<std::endl;
        }
};

class Widget:public GenericWidget {
    private:
        int *x;
        std::string _label {"default value"};
    public:
        Widget()=default;
        virtual ~Widget()=default;
        //Copy Ctor
        Widget(const Widget &)=delete;
        //Move Ctor
        //Widget(const Widget &&)=delete;
        //Widget(const Widget &w){
        //    _label = w._label;
        //    std::cout<<"Copy Ctor"<<std::endl;
        //}
        //Copy Assignment !!!
        Widget &operator=(const Widget &)=delete;
        virtual void show(){
            std::cout<<"widget show"<<std::endl;
        }

};

void print( Widget &w){
    w.show();
}

int main(){
    Widget w1;

    print(w1);

    //Widget w2 = w1;
    //w2= w1;
    return 0;
}
