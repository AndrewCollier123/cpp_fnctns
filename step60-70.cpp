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
    
    //reading from files with ifstream:
    std::ifstream read_file ("hello.txt");

    /*
    std::vector<std::string> read_names;

    std::string input;  //string reads each input until whitespace is found. "char input;" would read each letter as input
    while(read_file >> input)
    {
        read_names.push_back(input);
    }

    for(std::string read_name : read_names)
    {
        std::cout << read_name << std::endl;
    }
    */

    // other ways to read from a file is using get() and getline()
    char temp_read = read_file.get();   //get() reads just one character
    std::cout << temp_read << std::endl;

    std::string store_line;
    getline(read_file, store_line);
    std::cout << store_line << std::endl;

    //multidimensional arrays and nested vectors
    int multi_array[][3] = {{1,2,3}, {4,5,6},{7,8,9}};  //only need to specify size on inner arrays
    
    for(int row = 0; row < 3; row++)
    {
        for(int col = 0; col < 3; col++)
        {
            std::cout << multi_array[row][col] << "  ";
        }
        std::cout << std::endl;
    }

    //nested vector (not statically sized)
    std::vector<std::vector<int>> nested_vector = {{1,2,3}, {4,5,6},{7,8,9}};
    for(int row = 0; row < 3; row++)
    {
        for(int col = 0; col < 3; col++)
        {
            std::cout << nested_vector[row][col] << "  ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}