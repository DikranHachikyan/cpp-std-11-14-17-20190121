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
    w1->show();
    w2->show();

    w1.swap(w2);

    w1->show();
    w2->show();

    Widget *wp = new Widget(1000);
    w2.reset(std::move(wp));
    std::cout<<"wp addr:"<<wp<<" w2 addr"<<w2.get()<<std::endl;
    wp = nullptr;//!!!!
    return 0;
}
