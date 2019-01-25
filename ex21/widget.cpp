#include "widget.h"
#include <iostream>

class Widget::WidgetImpl{
    //Private Data
     private:
        int _n;
    public:
        void draw(const Widget &w) const{
            if( w.isVisible()){
                std::cout<<"Draw Widget"<<_n<<std::endl;
            }
        }
        WidgetImpl(int n):_n{n}{}
};

Widget::Widget(int n):pImpl{ std::make_unique<WidgetImpl>(n)} {}
Widget::~Widget()=default;
void Widget::draw(){
    pImpl->draw(*this);
}
bool Widget::isVisible() const{
    return true;
}

Widget &Widget::operator=(Widget &&)=default;

