#include <iostream>
#include <cstdlib>

void show(int param){
    std::cout<<"int param"<<param<<std::endl;
}

void show(char *param){
    std::cout<<"int param"<<param<<std::endl;
}

int main(){
    //int *p = NULL;
    int *p = nullptr;

    //show(NULL);
    show(nullptr);
    return 0;
}
