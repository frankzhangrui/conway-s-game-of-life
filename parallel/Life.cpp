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

void Life::parallel_simulate(const char* file1,const char* file2){
        grids[0].Read(file1);
        int rank, size;
        MPI_Request request;
        MPI_Status status;
        MPI_Comm_rank (MPI_COMM_WORLD, &rank);
        MPI_Comm_size (MPI_COMM_WORLD, &size);
        if(rank==0){
        cout<<"Reading input file:"<< "     "<< file1<<endl;
        cout<<"Number of processes: "<<"     "<<size<<endl;
        cout<<"Starting timer" <<endl;
        }
        double time1;
        double time2;
        time1 = MPI_Wtime();
        for(int i=1;i<generation;++i){
            parallel_update(grids[i-1],grids[i]);
            MPI_Barrier(MPI_COMM_WORLD);
            for(int ii=0;(ii<size);++ii){
                if (ii==rank)
                    continue;
                else{
                    MPI_Sendrecv(&grids[i].data[(rows/size)*rank*cols],(rows/size)*cols,MPI_INT,ii,0,&grids[i].data[(rows/size)*ii*cols],(rows/size)*cols,MPI_INT, ii, 0,MPI_COMM_WORLD, &status);
                }
            }
        }
        time2 = MPI_Wtime();
        if(rank==0){
            for(int i=0;i<generation;++i) cout<<"Generation "<< i<<"    number of living cells:   "<<grids[i].sum()<<endl;
            cout<<"Total wallclock time    "<< time2-time1<<" seconds"<<endl;
            cout<<"Writing output file:    " <<file2<<endl;
            grids[generation-1].Write(file2);
        }
}


void Life::parallel_update(Grid& G1, Grid &G2)
{
    int rank;
    MPI_Comm_rank (MPI_COMM_WORLD, &rank);
    int size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    for(int i=(rows/size)*(rank);i<=(rank+1)*(rows/size)-1;++i){
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
