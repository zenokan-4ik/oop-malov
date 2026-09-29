#include <iostream>
#include <vector>

bool ReadNumbers(std::istream& in, std::vector<double>& nums);
void ProcessNumbers(std::vector<double>& nums);
void PrintSortedNumbers(std::ostream& out, const std::vector<double>& nums);

int main() 
{
    std::vector<double> nums;
    
    if (!ReadNumbers(std::cin, nums)) 
    {
        std::cout << "ERROR" << std::endl;
        return 0;
    }
    
    if (nums.empty()) 
    {
        return 0;
    }
    
    ProcessNumbers(nums);
    
    PrintSortedNumbers(std::cout, nums);
    
    return 0;
}