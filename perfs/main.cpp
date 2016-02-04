// g++ -std=c++11 -o perfTest main.cpp
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <fstream>
#include <string>

int main(int argc, char const *argv[]) {
    std::string * s = new std::string("abs");
    if (argc < 2)
    {
        system("rm result.csv");
        system("touch result.csv");
        system("echo \"duree(proportion)\" >> result.csv");
        return 0;
    }
    std::cout << "____"<<argv[1]<<"____" << std::endl;

    clock_t init, final;
    init=clock();
    std::system(argv[1]);
    final=clock()-init;
    std::string temps = std::to_string(final);

    std::system(("echo "+temps+">> result.csv").c_str());
    std::cout << "___time used :" << (double)final << std::endl;
    return 0;
}
