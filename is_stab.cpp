#include<iostream>
#include<string>
#include<map>
#include<vector>
#include <algorithm>

int IS_STABLE(std::map<char, std::string>& pref_M, std::map<char,std::string>& pref_F, std::map<char, char>& match){
    char matched_M;
    int stab;
    stab = 0;
    
    int j;
    int i;
    int n {0};
    
    std::vector<char> MEN;
    for(auto &[key,value] : pref_M) {
        n += 1;
        MEN.push_back(key);
    } 
    char* men = MEN.data();
    
    char man;


    for (i=0; i<n;i++){
    man = men[i];
    for (j=0; j<n;j++){
            if (pref_M[man].find(match[man]) > pref_M[man].find(pref_M[man][j])){
                for(auto &[key,value] : match) { 
                    if(value == pref_M[man][j]) { 
                        matched_M = key;
                    } 
                } 
                
                if (pref_F[pref_M[man][j]].find(man) < pref_F[pref_M[man][j]].find(matched_M)){
                    stab = 1;
                    break;
                }
            }
        }
    }
    return stab;
}