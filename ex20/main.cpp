#include <iostream>
#include <memory>
#include <utility>
class B;

class A{
    private:
        std::shared_ptr<B> _b;
    public:
        A():_b{nullptr}{std::cout<<"Ctor A"<<std::endl;}
        ~A(){std::cout<<"Dtor A"<<std::endl;}
        void setB(std::shared_ptr<B> b){ _b = b;}
        void count(){
            std::cout<<"A refs:"<<_b.use_count()<<std::endl;
        }
};

class B{
    private:
        std::weak_ptr<A> _a;
    public:
        B(std::shared_ptr<A> a):_a{a}{std::cout<<"Ctor B"<<std::endl;}
        ~B(){std::cout<<"Dtor B"<<std::endl;}
        void count(){
            std::cout<<"B refs:"<<_a.use_count()<<std::endl;
        }
};


int main(){

    auto objA = std::make_shared<A>();
    auto objB = std::make_shared<B>(objA);
    objA->setB(objB);
    objA->count();
    objB->count();
    return 0;
}
