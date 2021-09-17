#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

template<class T> 
void insertion(std::vector<T>& v){
T temp;
int i;
    for(int j=1;j<v.size();j++){
    temp = v[j];
    i=j-1;
        while(temp<v[i] && i>=0){
          
                v[i+1] = v[i];
                --i;
        }
        v[i+1]=temp;
    }
}

int main(){

    std::vector<int> vec(
    std::istream_iterator<int>(std::cin),
    std::istream_iterator<int>()
    );

    // for(const auto &i : vec){
    //     std::cout << i << "\n";
    // }
    // std::cout << "-SORT-\n";
    
    insertion(vec); 
    
    for(const auto &i : vec){
        std::cout << i << "\n";
    }
    return 0;
}


