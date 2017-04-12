//
//  Test.cpp
//  InfectionAssessment
//
//  Created by Paul Danilin on 12/04/2017.
//  Copyright © 2017 Paul Danilin. All rights reserved.
//

#include "Test.h"

#include "grid.h"

static int tests = 0;

void Test(std::string sample_file, int row, int col, int res)
{
    ++tests;
    std::cout << "\nTesting #" << tests << "...\n";
    grid g(sample_file);
    assert(g.getCount(row, col) == res);
    std::cout << "Test #" << tests << " finished OK." << "\n";
}

void Test(std::string samples_folder)
{
    // 1-5
    Test(samples_folder + "/sample0.grid", 4, 0, 2);
    Test(samples_folder + "/sample0.grid", 0, 0, 8);
    Test(samples_folder + "/sample0.grid", 1, 1, 8);
    Test(samples_folder + "/sample0.grid", 2, 5, 3);
    Test(samples_folder + "/sample0.grid", 0, 3, 0);
    
    //6-10
    Test(samples_folder + "/sample1.grid", 0, 0, 14);
    Test(samples_folder + "/sample1.grid", 1, 1, 14);
    Test(samples_folder + "/sample1.grid", 2, 5, 14);
    Test(samples_folder + "/sample1.grid", 1, 8, 14);
    Test(samples_folder + "/sample1.grid", 3, 6, 14);
    
    
    //11-15
    Test(samples_folder + "/sample1.grid", 5, 4, 3);
    Test(samples_folder + "/sample1.grid", 6, 0, 3);
    Test(samples_folder + "/sample1.grid", 5, 2, 3);
    Test(samples_folder + "/sample1.grid", 3, 5, 0);
    Test(samples_folder + "/sample1.grid", 5, 3, 0);
}
