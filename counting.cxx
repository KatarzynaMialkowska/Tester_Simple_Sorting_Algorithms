#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>


void counting(std::vector<int>& v){

int max = v[0];
int start = 0, id = 0;

    for(int i=0;i<v.size();i++)
    {
        if(max<v[i])max=v[i];
    }

    std::vector<int>cub(max+1,0);

    for(int i=0;i<v.size();i++)
    {
        cub[v[i]]+=1;
    }

    while(start<=max){
        if(cub[start]!=0){
            for(int i=0;i<cub[start];i++)
            {
                v[id]=start;
                ++id; 
            }
        }
        ++start;
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
    
    counting(vec); 
    
    for(const auto &i : vec){
        std::cout << i << "\n";
    }
    return 0;
}


