#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include <vector>
#include <sstream>
#include <string>

bool ReadNumbers(std::istream& in, std::vector<double>& nums);
void ProcessNumbers(std::vector<double>& nums);
void PrintSortedNumbers(std::ostream& out, const std::vector<double>& nums);

TEST_CASE("ReadNumbers parses valid input", "[ReadNumbers]") 
{
    std::istringstream input("1.0 2 3.659512");
    std::vector<double> nums;
    
    bool result = ReadNumbers(input, nums);
    
    REQUIRE(result == true);
    REQUIRE(nums.size() == 3);
    REQUIRE(nums[0] == Approx(1.0));
    REQUIRE(nums[1] == Approx(2.0));
    REQUIRE(nums[2] == Approx(3.659512));
}

TEST_CASE("ReadNumbers handles empty input", "[ReadNumbers]") 
{
    std::istringstream input("");
    std::vector<double> nums;
    
    bool result = ReadNumbers(input, nums);
    
    REQUIRE(result == true);
    REQUIRE(nums.empty());
}

TEST_CASE("ReadNumbers returns false on invalid input", "[ReadNumbers]") 
{
    std::istringstream input("abc");
    std::vector<double> nums;
    
    bool result = ReadNumbers(input, nums);
    
    REQUIRE(result == false);
}

TEST_CASE("ReadNumbers returns false on mixed invalid input", "[ReadNumbers]") 
{
    std::istringstream input("- 2 3");
    std::vector<double> nums;
    
    bool result = ReadNumbers(input, nums);
    
    REQUIRE(result == false);
}

TEST_CASE("ProcessNumbers adds average of positives", "[ProcessNumbers]") 
{
    std::vector<double> nums = {1.0, 2.0, 3.0};
    
    ProcessNumbers(nums);
    
    REQUIRE(nums[0] == Approx(3.0));
    REQUIRE(nums[1] == Approx(4.0));
    REQUIRE(nums[2] == Approx(5.0));
}

TEST_CASE("ProcessNumbers with mixed positive and negative", "[ProcessNumbers]") 
{
    std::vector<double> nums = {4.0, 16.0, -30.0, 10.0};
    
    ProcessNumbers(nums);
    
    REQUIRE(nums[0] == Approx(14.0));
    REQUIRE(nums[1] == Approx(26.0));
    REQUIRE(nums[2] == Approx(-20.0));
    REQUIRE(nums[3] == Approx(20.0));
}

TEST_CASE("ProcessNumbers with all negatives leaves unchanged", "[ProcessNumbers]") 
{
    std::vector<double> nums = {-1.0, -703.0, -3.659512, -11.0};
    
    ProcessNumbers(nums);
    
    REQUIRE(nums[0] == Approx(-1.0));
    REQUIRE(nums[1] == Approx(-703.0));
    REQUIRE(nums[2] == Approx(-3.659512));
    REQUIRE(nums[3] == Approx(-11.0));
}

TEST_CASE("ProcessNumbers with empty vector does nothing", "[ProcessNumbers]") 
{
    std::vector<double> nums;
    
    ProcessNumbers(nums);
    
    REQUIRE(nums.empty());
}

TEST_CASE("ProcessNumbers with single positive number", "[ProcessNumbers]") 
{
    std::vector<double> nums = {5.0};
    
    ProcessNumbers(nums);
    
    REQUIRE(nums[0] == Approx(10.0));
}

TEST_CASE("PrintSortedNumbers outputs sorted with precision 3", "[PrintSortedNumbers]") 
{
    std::vector<double> nums = {3.0, 4.0, 5.0};
    std::ostringstream output;
    
    PrintSortedNumbers(output, nums);
    
    REQUIRE(output.str() == "3.000 4.000 5.000\n");
}

TEST_CASE("PrintSortedNumbers sorts unsorted input", "[PrintSortedNumbers]") 
{
    std::vector<double> nums = {5.0, 3.0, 4.0};
    std::ostringstream output;
    
    PrintSortedNumbers(output, nums);
    
    REQUIRE(output.str() == "3.000 4.000 5.000\n");
}

TEST_CASE("PrintSortedNumbers handles negative numbers", "[PrintSortedNumbers]") 
{
    std::vector<double> nums = {-15.0, -10.0, -5.0};
    std::ostringstream output;
    
    PrintSortedNumbers(output, nums);
    
    REQUIRE(output.str() == "-15.000 -10.000 -5.000\n");
}

TEST_CASE("Full pipeline - Example 1", "[Integration]") 
{
    std::istringstream input("1.0 2 3.659512");
    std::vector<double> nums;
    
    REQUIRE(ReadNumbers(input, nums) == true);
    ProcessNumbers(nums);
    
    std::ostringstream output;
    PrintSortedNumbers(output, nums);
    
    REQUIRE(output.str() == "3.220 4.220 5.879\n");
}

TEST_CASE("Full pipeline - Example 2", "[Integration]") 
{
    std::istringstream input("4 16 -30 10");
    std::vector<double> nums;
    
    REQUIRE(ReadNumbers(input, nums) == true);
    ProcessNumbers(nums);
    
    std::ostringstream output;
    PrintSortedNumbers(output, nums);
    
    REQUIRE(output.str() == "-20.000 14.000 20.000 26.000\n");
}

TEST_CASE("Full pipeline - Example 3", "[Integration]") 
{
    std::istringstream input("-1.0004000 -703 -3.659512 -11");
    std::vector<double> nums;
    
    REQUIRE(ReadNumbers(input, nums) == true);
    ProcessNumbers(nums);
    
    std::ostringstream output;
    PrintSortedNumbers(output, nums);
    
    REQUIRE(output.str() == "-703.000 -11.000 -3.660 -1.000\n");
}