#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
int main(){

    std::vector<int> vec(
    std::istream_iterator<int>(std::cin),
    std::istream_iterator<int>()
    );

    // for(const auto &i : vec){
    //     std::cout << i << "\n";
    // }
    // std::cout << "-SORT-\n";
    
    std::sort (vec.begin(), vec.end()); 
    
    for(const auto &i : vec){
        std::cout << i << "\n";
    }
    return 0;
}


