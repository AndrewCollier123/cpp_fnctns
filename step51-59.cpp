#include <iostream>
#include <vector>   // must compile with -std=c++11
#include <array>

void print_vector(std::vector<int> diff_name)
{
    std::cout << "Printed vector array: ";
    for(int i = 0; i < diff_name.size(); i++)
    {
        std::cout << diff_name[i] << " ";
    }
    std::cout << "\n";
}

void print_STLarry(std::array<int, 20> STL_array)
{
    std::cout << "Printed STL array: ";
    for (int i = 0; i < STL_array.size(); i++)
    {
        std::cout << STL_array[i] << " ";
    }
    std::cout << "\n";
}

int main()
{
    std::vector<int> data = {1, 3, 4};
    data.push_back(5);
    std::cout << data[3] << std::endl;
    std::cout << data[data.size() - 1] << std::endl;    //size() function returns num of elements in the array
    data.pop_back();
    std::cout << data.size() << std::endl;
    print_vector(data);

    std::array<int, 20> STL_array = {2, 5, 6};  // standard template library arrays
    std::cout << STL_array.size() << std::endl;
    print_STLarry(STL_array);

    std::vector<int> loop_data = {1,2,3,4,5};
    //templatized array would be: std::array<int, 6> loop_data = {1,2,3,4,5};
    for(int i = 0; i < 5; i++)
    {
        std::cout << loop_data[i] << "  ";
    }
    std::cout << std::endl;

    std::cout << "range based 'for loop': ";
    for(int n : loop_data)
    {
        std::cout << n << "\t";
    }
    std::cout << std::endl;
    return 0;
}