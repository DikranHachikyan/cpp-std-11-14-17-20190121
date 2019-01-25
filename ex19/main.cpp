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
    auto w2 = std::make_shared<Widget>(1200);
    std::shared_ptr<Widget> t;

    std::weak_ptr<Widget> wkp(w1);

    std::cout<<"weak refs:"<<wkp.use_count()<<"\n"
             <<"shared refs:"<<w1.use_count()
             <<std::endl;

    if( (t = wkp.lock())){
        std::cout<<"t refs:"<<t.use_count()<<"\n"
                <<"weak refs:"<<wkp.use_count()<<"\n"
                <<"shared w1 refs:"<<w1.use_count()
               <<std::endl;

    }
    std::cout<<"is wkp expired:"<<std::boolalpha<<wkp.expired()<<std::endl;
    wkp.reset();
    std::cout<<"is wkp expired:"<<std::boolalpha<<wkp.expired()<<std::endl;

    if( (t = wkp.lock())){
        std::cout<<"t refs:"<<t.use_count()<<"\n"
                <<"weak refs:"<<wkp.use_count()<<"\n"
               <<"shared w1 refs:"<<w1.use_count()
              <<std::endl;

    }
    return 0;
}
