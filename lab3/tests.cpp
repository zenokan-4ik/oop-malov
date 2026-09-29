#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "TVSet.h"

TEST_CASE("TVSet initial state is off", "[TVSet]") 
{
    TVSet tv;
    REQUIRE_FALSE(tv.IsOn());
    REQUIRE(tv.GetChannel() == 0);
}

TEST_CASE("TVSet turns on at channel 1 initially", "[TVSet]") 
{
    TVSet tv;
    tv.TurnOn();
    REQUIRE(tv.IsOn());
    REQUIRE(tv.GetChannel() == 1);
}

TEST_CASE("TVSet turns off and channel becomes 0", "[TVSet]") 
{
    TVSet tv;
    tv.TurnOn();
    tv.TurnOff();
    REQUIRE_FALSE(tv.IsOn());
    REQUIRE(tv.GetChannel() == 0);
}

TEST_CASE("TVSet remembers channel after turn off", "[TVSet]") 
{
    TVSet tv;
    tv.TurnOn();
    tv.SelectChannel(5);
    tv.TurnOff();
    tv.TurnOn();
    REQUIRE(tv.GetChannel() == 5);
}

TEST_CASE("TVSet SelectChannel works for valid channels", "[TVSet]") 
{
    TVSet tv;
    tv.TurnOn();
    
    REQUIRE(tv.SelectChannel(1));
    REQUIRE(tv.GetChannel() == 1);
    
    REQUIRE(tv.SelectChannel(50));
    REQUIRE(tv.GetChannel() == 50);
    
    REQUIRE(tv.SelectChannel(99));
    REQUIRE(tv.GetChannel() == 99);
}

TEST_CASE("TVSet SelectChannel fails for invalid channels", "[TVSet]") 
{
    TVSet tv;
    tv.TurnOn();
    tv.SelectChannel(5);
    
    REQUIRE_FALSE(tv.SelectChannel(0));
    REQUIRE(tv.GetChannel() == 5);
    
    REQUIRE_FALSE(tv.SelectChannel(100));
    REQUIRE(tv.GetChannel() == 5);
    
    REQUIRE_FALSE(tv.SelectChannel(-1));
    REQUIRE(tv.GetChannel() == 5);
}

TEST_CASE("TVSet SelectChannel fails when TV is off", "[TVSet]") 
{
    TVSet tv;
    REQUIRE_FALSE(tv.SelectChannel(5));
    REQUIRE_FALSE(tv.IsOn());
}

TEST_CASE("TVSet TurnOn does nothing if already on", "[TVSet]") 
{
    TVSet tv;
    tv.TurnOn();
    tv.SelectChannel(10);
    tv.TurnOn();
    REQUIRE(tv.GetChannel() == 10);
}

TEST_CASE("TVSet TurnOff does nothing if already off", "[TVSet]") 
{
    TVSet tv;
    tv.TurnOff();
    REQUIRE_FALSE(tv.IsOn());
    REQUIRE(tv.GetChannel() == 0);
}

TEST_CASE("TVSet multiple on/off cycles", "[TVSet]") 
{
    TVSet tv;
    
    tv.TurnOn();
    tv.SelectChannel(20);
    tv.TurnOff();
    
    tv.TurnOn();
    REQUIRE(tv.GetChannel() == 20);
    tv.SelectChannel(30);
    tv.TurnOff();
    
    tv.TurnOn();
    REQUIRE(tv.GetChannel() == 30);
}