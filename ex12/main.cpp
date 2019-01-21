#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include <algorithm>

void foo(){
    std::cout<<"foo"<<std::endl;
}
int main(){
    std::vector<int> values {1,2,3,4,5,6,7,8,9,10};
    int k = 4;

    auto gt = [k](int v)->bool{
      return v > k;
    };

    int gt_count = std::count_if(std::cbegin(values), std::cend(values), gt );
    std::cout<<"count="<<gt_count<<std::endl;
    auto le = [k](int v)->bool{ return v <= k;};
    values.erase(std::remove_if( std::begin(values), std::end(values), le),
                 std::end(values));

    std::cout<<"after remove:\n";
    for( auto v : values){
        std::cout<<v<<" ";
    }
    std::cout<<std::endl;

    std::cout<<"type of gt:"<<typeid(gt).name()<<std::endl;
    return 0;
}
