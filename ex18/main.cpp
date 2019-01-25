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
    std::shared_ptr<Widget> w1( new Widget(100));

    std::cout<<"w1 refs:"<<w1.use_count()<<std::endl;

    {
        std::shared_ptr<Widget> w2(w1);
        std::shared_ptr<Widget> w3 = w1;
        std::shared_ptr<Widget> w4 = w1;
        std::cout<<"[block] resf:"<<w1.use_count()<<std::endl;
        w1.reset();
        std::cout<<"[block] w1 resf:"<<w1.use_count()<<std::endl;
        std::cout<<"[block] w3 resf:"<<w3.use_count()<<std::endl;
        std::cout<<"[block] w4 resf:"<<w4.use_count()<<std::endl;
    }

    std::cout<<"w1 refs:"<<w1.use_count()<<std::endl;
    return 0;
}
