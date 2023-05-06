#include <iostream>
#include <fstream>
#include <vector>   //requires -std=c++11

int main()
{
    std::cout << "What is the name of the file you want to write to? (type: hello.txt)" << std::endl;
    std::string filename;
    std::cin >> filename;

    std::ofstream file;     //can just add ("hello.txt"); after file
    file.open(filename);     //can add (hello.txt, std::ios::app); to append any text when compiled to the current file instead of replacing it

    if(file.is_open())  //checks if file is open
    {
        std::cout << "file is open" <<  std::endl;
    }

    file << "hello file" << std::endl;
    std::vector<std::string> names;
    names.push_back("bob");
    names.push_back("joe");
    names.push_back("guy");

    for(std::string name : names)
    {
        file << name << std::endl;
    }

    file.close();   // this is unnecessary since it automatically does it for you
    return 0;
}