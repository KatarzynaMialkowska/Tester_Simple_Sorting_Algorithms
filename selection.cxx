#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

template<class T> 
void selection(std::vector<T>& v){
int min;
    for(int j=0;j<v.size()-1;j++){
    min = j;
        for (int i=j+1; i<v.size(); i++) {
            if (v[min] > v[i]){
                v[min] += v[i];
                v[i] = v[min] - v[i];
                v[min] -= v[i];
            }
        }
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
    
    selection(vec); 
    
    for(const auto &i : vec){
        std::cout << i << "\n";
    }
    return 0;
}


