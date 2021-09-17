#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

template<class T> 
void bubble(std::vector<T>& v){

    for(int j=0;j<v.size();j++)
    for (int i=0; i<v.size()-1; i++) 
    {
        if (v[i] > v[i+1]){
            v[i] += v[i+1];
            v[i+1] = v[i] - v[i+1];
            v[i] -= v[i+1];
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
    
    bubble(vec); 
    
    for(const auto &i : vec){
        std::cout << i << "\n";
    }
    return 0;
}


