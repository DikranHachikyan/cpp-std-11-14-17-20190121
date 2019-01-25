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
    w1->show();
    //c++14
    auto w2 = std::make_unique<Widget>(20);
    w2->show();

    auto w3 = std::move(w1);
    std::cout<<"w3 show"<<std::endl;
    w3->show();
    //std::cout<<"w1 show"<<std::endl;
    //w1->show();
    if( w1 == nullptr){
        std::cout<<"invalid w1"<<std::endl;
    }
    return 0;
}
