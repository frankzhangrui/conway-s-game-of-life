//
//  Life.cpp
//  Life of Conner-serial
//
//  Created by RUI Zhang on 3/3/15.
//  Copyright (c) 2015 ruizhang. All rights reserved.
//

#include "Life.h"
using namespace std;

Life::Life(int m, int n, int generations){
    rows=m;
    cols=n;
    generation=generations+1;
    for(int i=0;i<generation;++i){
        Grid mygrids(m,n);
        grids.push_back(mygrids);
    }
}

void Life::serial_simulate(const char* file1,const char* file2){
    struct timeval tim1;
    struct timeval tim2;  
    grids[0].Read(file1);
    cout<<"Reading input file:"<< "     "<< file1<<endl;
    cout<<"Number of processes:"<<"     "<<1<<endl;
    cout<<"Starting timer" <<endl;
    cout<<"Generation "<< 0<<"    number of living cells:   "<<grids[0].sum()<<endl;
    gettimeofday(&tim1, NULL);
    for(int i=1;i<generation;++i){
        serial_update(grids[i-1],grids[i]);
        cout<<"Generation "<< i<<"    number of living cells:   "<<grids[i].sum()<<endl;
    }
    gettimeofday(&tim2, NULL);
    double t1=tim1.tv_sec+(tim1.tv_usec/1000000.0); 
    double t2=tim2.tv_sec+(tim2.tv_usec/1000000.0); 
    cout<<"Total wallclock time    "<< t2-t1<<" seconds"<<endl;
    cout<<"Writing output file:    " <<file2<<endl;
    grids[generation-1].Write(file2);
}

void Life::serial_update(Grid& G1, Grid &G2){
    for(int i=0;i<rows;++i){
        for(int j=0;j<cols;++j){
            if ((G1(i,j)==1) && (G1.sum_of_neighbors(i,j)<2)) // loneliness
                G2(i,j)=0;
            if ((G1(i,j)==1) && ((G1.sum_of_neighbors(i,j)==2) || (G1.sum_of_neighbors(i,j)==3))) // 2-3 neighbors
                G2(i,j)=1;
            if ((G1(i,j)==1) && (G1.sum_of_neighbors(i,j)>3))  // overcrowding 
                G2(i,j)=0;
            if ((G1(i,j)==0) && (G1.sum_of_neighbors(i,j)==3)) //reproduction
                G2(i,j)=1;
        }
    }
}





