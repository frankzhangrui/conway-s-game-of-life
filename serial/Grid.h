//
//  Grid.h
//  Life of Conner-serial
//
//  Created by RUI Zhang on 3/3/15.
//  Copyright (c) 2015 ruizhang. All rights reserved.
//

#ifndef __Life_of_Conner_serial__Grid__
#define __Life_of_Conner_serial__Grid__
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
class Grid{
public:
    int rows;
    int cols;
    std::vector<int> data;
    Grid(int m, int n){ rows=m;cols=n; data=std::vector<int>(m*n,0);}
    int operator()(int i, int j) const { return data[i*cols+j]; }
    int &operator()(int i, int j) { return data[i*cols+j]; }
    bool OnGrid(int i, int j);
    int sum_of_neighbors(int i,int j);
    int Row() const {return this->rows;}
    int Col() const {return this->cols;}
    void Read(const char* filename);
    void Write(const char* filename);
    int sum();
};

#endif /* defined(__Life_of_Conner_serial__Grid__) */
