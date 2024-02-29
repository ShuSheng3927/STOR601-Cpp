#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include "fund_alg.h"
 
std::map<char, char> match_algorithm(std::string filename1, std::string filename2){
    std::ifstream file1(filename1);
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
 

    std::ifstream file2(filename2);
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
 

    std::map<char, char> matching = FUND_ALG(table1, table2);
    
    return matching;
}