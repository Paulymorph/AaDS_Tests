/**
 * Unit tests for RailSystem class
 *
 * by Zakharov Sergey aka Zakhse
 * BPI 153
 * 13.03.2017
 */

#include "../src/RailSystem.h"
#include <gtest/gtest.h>

RailSystem rs("../res/services.txt");

int main(int argc, char** argv)
{
    RailSystem rs("../res/services.txt");
    
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(TotalFeeTest, MadridSkopja)
{
    EXPECT_EQ(rs.getCheapestRoute("Madrid", "Skopja").fee, 55);
}

TEST(TotalFeeTest, CopenhagenAthens)
{
    EXPECT_EQ(rs.getCheapestRoute("Copenhagen", "Athens").fee, 275);
}

TEST(TotalFeeTest, SarajevoVienna)
{
    EXPECT_EQ(rs.getCheapestRoute("Sarajevo", "Vienna").fee, 50);
}

TEST(TotalFeeTest, DublinRome)
{
    EXPECT_EQ(rs.getCheapestRoute("Dublin", "Rome").fee, INT_MAX);
}

TEST(TotalDistanceTest, MadridSkopja)
{
    EXPECT_EQ(rs.getCheapestRoute("Madrid", "Skopja").distance, 3100);
}

TEST(TotalDistanceTest, CopenhagenAthens)
{
    EXPECT_EQ(rs.getCheapestRoute("Copenhagen", "Athens").distance, 7000);
}

TEST(TotalDistanceTest, SarajevoVienna)
{
    EXPECT_EQ(rs.getCheapestRoute("Sarajevo", "Vienna").distance, 900);
}
