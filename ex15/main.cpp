#include <iostream>
#include <memory>
#include <utility>

class Widget{
    private:
        int _n;
    public:
        Widget(int n):_n{n}{
            std::cout<<"Ctor n="<<_n<<std::endl;
        }
        Widget():_n{-1}{
            std::cout<<"Empty Ctor n="<<_n<<std::endl;
        }
        ~Widget(){
            std::cout<<"Dtor n="<<_n<<std::endl;
        }
        void show(){
            std::cout<<"show n="<<_n<<std::endl;
        }
};

int main(){
    std::unique_ptr<Widget> w1 {new Widget(10)};
    //c++14
    auto w2 = std::make_unique<Widget>(20);

    Widget * wp = w1.get(); //връща указател
    //auto wp = w1.get(); //връща указател
    wp->show();
    //delete wp;//не е добра идея
    decltype (wp) w3 = w2.release();//освобождава собствеността обекта
    w3->show();
    delete w3;
    if( w2 == nullptr ) std::cout<<"invalid w2"<<std::endl;

    auto w4 = std::make_unique<Widget>(100);
    w4->show();

    w4.reset( new Widget(1000) );//delete old replace
    w4.reset();
    std::cout<<"---"<<std::endl;
    return 0;
}
