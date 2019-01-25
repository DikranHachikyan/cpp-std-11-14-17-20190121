#include <iostream>
#include <utility>
#include <algorithm>

class A{
    private:
        int n {3};
    public:
        A()=default;
        ~A(){std::cout<<"Dtor A"<<std::endl;}
        A(const A &){std::cout<<"Copy Ctor"<<std::endl;}
        A(A &&a){
            std::cout<<"Move Ctor"<<a.n<<std::endl;
        }
        A &operator=( const A &){
            std::cout<<"copy assign"<<std::endl;
            return *this;
        }
        A &operator=( A &&){
            std::cout<<"move assign"<<std::endl;
            return *this;
        }
        void show(){std::cout<<"show"<<std::endl;}
};

void foo(A &a){
    std::cout<<"a is lvalue ref"<<std::endl;
}
void foo(A &&a){
    std::cout<<"a is rvalue ref"<<std::endl;
}
A get(){
    A ob;
    return ob;
}
//
template <typename T> void swap(T &a, T &b){
    T t = std::move(a);
    a = std::move(b);
    b = std::move(t);
}

void print( A &&rhs){
    //A a = rhs;//Copy Ctor
    A a = std::move(rhs);
    a.show();
}
int main(){
    A obj;

    //foo(obj);
    foo(std::move(obj));
    foo(get());
    std::cout<<"-----"<<std::endl;
    //A obj1 = obj; //copy ctor
    A obj1 = std::move(obj);
    A a1;
    A a2;
    //a1 = a2; //copy assign
    a1 = std::move(a2); //move assign

    std::swap(a1,a2);
    std::cout<<"---- print ---"<<std::endl;
    print(get());
    return 0;
}
