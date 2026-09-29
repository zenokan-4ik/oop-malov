#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <string>
#include <sstream>

bool ReadNumbers(std::istream& in, std::vector<double>& nums) 
{
    std::string line;
    std::getline(in, line);
    
    if (line.empty()) 
    {
        return true;
    }
    
    std::istringstream iss(line);
    double val;
    while (iss >> val) 
    {
        nums.push_back(val);
    }
    
    return iss.eof();
}

void ProcessNumbers(std::vector<double>& nums) 
{
    if (nums.empty()) return;
    
    std::vector<double> positives;
    
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0) 
        {
            positives.push_back(nums[i]);
        }
    }
    
    double sum = std::accumulate(positives.begin(), positives.end(), 0.0);
    
    double avg = 0;
    if (positives.size() > 0) 
    {
        avg = sum / positives.size();
    }
    
    for (int i = 0; i < nums.size(); i++) 
    {
        nums[i] += avg;
    }
}

void PrintSortedNumbers(std::ostream& out, const std::vector<double>& nums) 
{
    if (nums.empty()) return;
    
    std::vector<double> copy = nums;
    
    std::sort(copy.begin(), copy.end());
    
    out << std::fixed << std::setprecision(3);
    for (int i = 0; i < copy.size(); i++) 
    {
        if (i > 0) out << " ";
        out << copy[i];
    }
    out << std::endl;
}