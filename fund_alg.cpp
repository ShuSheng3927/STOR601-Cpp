#include<iostream>
#include<string>
#include<map>
#include <algorithm>
#include <vector>


std::map<char,char> FUND_ALG(std::map<char, std::string>& pref_M, std::map<char,std::string>& pref_F){
    int k;
    int n = 0;
    std::vector<char> MEN;
    std::map<char,char> f_match;
        
    for(auto &[key,value] : pref_F) {
        f_match[key] = 'O';
        value += 'O';
    } 
    for(auto &[key,value] : pref_M) {
        n += 1;
        MEN.push_back(key);
    } 
    char* men = MEN.data();
        
    k = 0;
    
    char x;
    char X;
    char preceed_m;
    
    
    while (k < n){
        X = men[k];
        while (X != 'O'){
            x = pref_M[X][0];
            if (pref_F[x].find(X) < pref_F[x].find(f_match[x])){
                preceed_m = f_match[x];
                f_match[x] = X;
                X = preceed_m;
            }
            if (X != 'O'){
                pref_M[X].erase(pref_M[X].find(x),1);
            }
        }
        k += 1;
    }

    std::map<char,char> match;

    for(auto &[key,value] : f_match) {
        match[value] = key;
    } 
    
    return match;
}