#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include <string>

std::string TrimBlanks(std::string const& str);

TEST_CASE("TrimBlanks removes no spaces", "[TrimBlanks]") 
{
    REQUIRE(TrimBlanks("hello") == "hello");
}

TEST_CASE("TrimBlanks removes leading spaces", "[TrimBlanks]") 
{
    REQUIRE(TrimBlanks(" hello") == "hello");
}

TEST_CASE("TrimBlanks removes trailing spaces", "[TrimBlanks]") 
{
    REQUIRE(TrimBlanks("hello ") == "hello");
}

TEST_CASE("TrimBlanks removes both leading and trailing spaces", "[TrimBlanks]") 
{
    REQUIRE(TrimBlanks(" hello ") == "hello");
}

TEST_CASE("TrimBlanks removes multiple leading spaces", "[TrimBlanks]") 
{
    REQUIRE(TrimBlanks("   hello") == "hello");
}

TEST_CASE("TrimBlanks removes multiple trailing spaces", "[TrimBlanks]") 
{
    REQUIRE(TrimBlanks("hello   ") == "hello");
}

TEST_CASE("TrimBlanks removes multiple spaces on both sides", "[TrimBlanks]") 
{
    REQUIRE(TrimBlanks("   hello   ") == "hello");
}

TEST_CASE("TrimBlanks returns empty for string of only spaces", "[TrimBlanks]") 
{
    REQUIRE(TrimBlanks("   ") == "");
}

TEST_CASE("TrimBlanks returns empty for single space", "[TrimBlanks]") 
{
    REQUIRE(TrimBlanks(" ") == "");
}

TEST_CASE("TrimBlanks returns empty for empty string", "[TrimBlanks]") 
{
    REQUIRE(TrimBlanks("") == "");
}

TEST_CASE("TrimBlanks preserves spaces in the middle", "[TrimBlanks]") 
{
    REQUIRE(TrimBlanks("  hello world  ") == "hello world");
}

TEST_CASE("TrimBlanks handles string with only one non-space character", "[TrimBlanks]") 
{
    REQUIRE(TrimBlanks("  a  ") == "a");
}

TEST_CASE("TrimBlanks handles tabs as non-space characters", "[TrimBlanks]") 
{
    REQUIRE(TrimBlanks(" \thello\t ") == "\thello\t");
}

TEST_CASE("TrimBlanks handles string with spaces and tabs in middle", "[TrimBlanks]") 
{
    REQUIRE(TrimBlanks("  hello \t world  ") == "hello \t world");
}