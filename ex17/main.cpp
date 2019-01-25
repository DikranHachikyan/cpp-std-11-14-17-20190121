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
   auto deleter = [](Widget *wdg){
       std::cout<<"custom deleter"<<std::endl;
       delete wdg;
   };

   std::unique_ptr<Widget, decltype (deleter)> w1(new Widget(100),deleter);

   w1->show();
    return 0;
}
