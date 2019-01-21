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
            std::cout<<"Show GW"<<std::endl;
        };
};

class Widget:public GenericWidget {
    private:
        std::string _label {"default value"};
    public:
        Widget()=default;
        virtual ~Widget()=default;
        //Copy Ctor
        Widget(const Widget &)=delete;
        //Copy Assignment !!!
        Widget &operator=(const Widget &)=delete;
        virtual void show() override {
            GenericWidget::show();
            std::cout<<"widget show"<<std::endl;
        }

};



int main(){
    GenericWidget *gw = new Widget;
    auto *gw2 = new GenericWidget;
    gw->show();
    auto w { new Widget};

    gw = gw2;
    gw->show();
    w->show();
    w = dynamic_cast<Widget *>(gw);
    w->show();
    std::cout<<"type of gw:"<<typeid(gw).name()
             <<"\ntype of gw2:"<<typeid(gw2).name()
            <<"\ntype of w:"<<typeid(w).name()
             <<std::endl;
    return 0;
}
