# STOR601-Cpp

This is the repository for the STOR601 C++ coursework. 

## Task 1

Task 1 requires us to implement the IS_STABLE algorithm and the fundamental algorithm. The IS_STABLE algorithm is implemented via files is_stab{.cpp / .h / .o}. The fundamental algorithm is implemented via files fund_alg{.cpp / .h / .o}. 

## Task 2

Task 2 requires us to read preference tables from external data files, use the fundamental algorithm to generate a matching, check the matching is stable using the IS_STABLE algorithm, and then print out the matching. 

Reading the preference tables and using that information to generate a matching is achieved by files match_alg{.cpp / .h / .o}. The overall file that executes Task 2 is done by the file main.cpp. 

One should know that the input files for the preference table should be in the same format as the examples pref_M.txt and pref_F.txt. In particular, it should be a txt file with multiple lines, and for each line it should be consisted of characters (breaked by a blanck space) and the first character is the person (e.g. the index for a male) while the remaining characters represent the descending order of that person's preference (e.g. a list of all the indices of females avaiable). 

To execute the main.cpp file in Ubuntu, one should go to the right directory where all the files are stored and run the command line

```
g++ --std=c++17 main.cpp fund_alg.o match_alg.o is_stab.o -o main.out
```

in terminal. The output would be in the main.out file, and it could be accessed in the terminal directly by the command "./main.out". 

If the titles of the preference tables input file are different than the default, one should also change them accordingly in the main.cpp file. To be precise, the arguments in the following line of code should be adjusted accordingly. 

```
std::map<char,char> matching = match_algorithm("pref_M.txt", "pref_F.txt");
```

## Task 3

Task 3 is based on Task 2 but requires an additional argument for the number of iterations that the fundamental algorithm is being run. To execute this task, things should follow almost exactly as that of Task 2, except that one should use the file main_2.cpp instead of main.cpp and use the match_alg_2 instead of match_alg. Also, to change the preference table file names, as well as the number of iterations, it should be done by adjusting the following line of the main_2.cpp file: 

```
std::map<char,char> matching = match_algorithm_2("pref_M.txt", "pref_F.txt",1000);
```

The last argument is the number of iterations. To execute the file, the terminal command would be: 

```
g++ --std=c++17 main_2.cpp fund_alg.o match_alg_2.o is_stab.o -o main_2.out
```

One could also add the optional "-o3" to speed up the execution of code. It could be done as follows: 

```
g++ --std=c++17 -o3 main_2.cpp fund_alg.o match_alg_2.o is_stab.o -o main_2.out
```

A report on the analysis of results from this task can be found as "task3.md". 

## Task 5

This task requires us to provide instructions to someone who wishes to run the codes on a Windows machine. The instructions are as follows. 


1. First, one should download and install a compiler. A possible choice is the VS Code, and a download link can be found [here](https://code.visualstudio.com/download). Detailed instructions on how to get the necessary extra bits for compiling C++ can be found [here](https://code.visualstudio.com/docs/languages/cpp).

2. Download all the files in this repository to a suitable location, go to that location, and open the main.cpp (or main_2.cpp) files in the compiler to make the necessary adjustments.

3. Open WindowsPowerShell, cd to the right directory, and execute as instructed above under Tasks 2 and 3. 
