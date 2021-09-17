#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iterator>
#include "queue.hxx"

void radix(std::vector<int>& v){

int max = v[0], id = 0, count = 0, temp, m, p =1;
Quene<int,1000000000>s1[10];

    for(int i=0;i<v.size();i++)
    {
        if(max<v[i])max=v[i];
    }
    int howManyDigits = (int)log10(max) + 1;
    for(int i=0; i<howManyDigits; i++)
    {
        m = pow(10, i+1);
        p = pow(10, i);

        for(int j=0; j<v.size(); j++)
        {
            temp = v[j] % m;
            id = temp / p;
            s1[id].push(v[j]);
        }
        count = 0;
        for(int k=0; k<10; k++) 
        {
            while(!s1[k].empty()) 
            {
                v[count] = (s1[k].pop());
                count++;
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
    
    radix(vec); 
    
    for(const auto &i : vec){
        std::cout << i << "\n";
    }
    return 0;
}


