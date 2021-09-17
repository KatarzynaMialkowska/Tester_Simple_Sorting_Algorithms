#ifndef T_H
#define T_H

#include "queue.hxx"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <ctime>
#include <random>
#include <iomanip>
#include <sstream>
#include <chrono>
#include <fstream>
#include <cstdio>

void radix(std::vector<int> v){
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

void counting(std::vector<int> v){
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

template<class T> 
void insertion(std::vector<T> v){
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

template<class T> 
void selection(std::vector<T> v){
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


template<class T> 
void bubble(std::vector<T> v){

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


template<class T> 
void stdsort(std::vector<T> v){

    std::sort (v.begin(), v.end()); 

}




void generator(std::vector<int>& v, const int& n, const int&& max){

    std::uniform_int_distribution<int> dist1 ( 0, max );
    std::mt19937 gen ( time ( NULL ) );
    
    for( int i = 0; i < n; i++ )
    {
        v.push_back(dist1(gen));
    }

}



#endif