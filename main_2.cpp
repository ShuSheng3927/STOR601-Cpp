#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include "fund_alg.h"
#include "is_stab.h"
#include "match_alg_2.h"
#include <chrono>
 

int main(){
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    
    std::map<char,char> matching = match_algorithm_2("pref_M.txt", "pref_F.txt",1000);
    
    
    std::ifstream file1("pref_M.txt");
    std::map<char, std::string> table1;
    std::string line1;
    while (std::getline(file1, line1)) {
        std::istringstream iss(line1);

        char key1;
        char value1;
        std::string val1 {""};

        iss >> key1;
 
        while (iss >> value1) {
            val1 += value1;
        }
        table1[key1] = val1;
    }
    file1.close();
 

    std::ifstream file2("pref_F.txt");
    std::map<char, std::string> table2;
    std::string line2;

    while (std::getline(file2, line2)) {
        std::istringstream iss(line2);
        char key2;
        char value2;
        std::string val2 {""};
        iss >> key2;
        while (iss >> value2) {
            val2 += value2;
        }
        table2[key2] = val2;
    }

    file2.close();

    if (IS_STABLE(table1,table2,matching) == 0){
        std::cout << "Algorithm Result:" << std::endl;
        for (auto &[key,value] : matching) {
            std::cout << key << " matches with " << value << std::endl;
        }
    }

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    std::cout << "Time difference = " << std::chrono::duration_cast
    <std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;

    return(0);
}