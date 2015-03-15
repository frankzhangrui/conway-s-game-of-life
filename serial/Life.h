//
//  Life.h
//  Life of Conner-serial
//
//  Created by RUI Zhang on 3/3/15.
//  Copyright (c) 2015 ruizhang. All rights reserved.
//

#ifndef __Life_of_Conner_serial__Life__
#define __Life_of_Conner_serial__Life__

#include "Grid.h"
#include "sys/time.h"
#include "time.h"
class Life{
private:
    int rows;
    int cols;
    int generation;
    std::vector<Grid> grids;
public:
    Life(int m, int n, int generations);
    void serial_simulate(const char* file1,const char* file2);
    void serial_update(Grid& G1, Grid &G2);
};
#endif /* defined(__Life_of_Conner_serial__Life__) */
