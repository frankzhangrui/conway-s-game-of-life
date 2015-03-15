//
//  Grid.cpp
//  Life of Conner-serial
//
//  Created by RUI Zhang on 3/3/15.
//  Copyright (c) 2015 ruizhang. All rights reserved.
//

#include "Grid.h"
using namespace std;
void Grid::Read(const char* filename){
    ifstream myfile;
    myfile.open(filename);
    string line;
    myfile>>line;
    for(int i=0;i<rows*cols;++i)
      data[i]=line[i]-'0';
    myfile.close();
}
void Grid::Write(const char* filename){
    ofstream myfile;
    myfile.open(filename);
    string line;
    for(int i=0;i<rows*cols;++i)
        myfile<<data[i];
    myfile<<endl;
}
bool Grid::OnGrid(int i,int j){
    return (i>=0) && (j>=0) && (i<rows) &&(j<cols) ; 
}
int Grid::sum_of_neighbors(int i,int j){
    int sum=0;
    for(int ii=-1; ii<=1;++ii){
        for(int jj=-1;jj<=1;++jj){
          if(OnGrid(ii+i,jj+j)){
            sum=sum+(*this)(ii+i,jj+j);
          }
        }
    }
    sum=sum-(*this)(i,j);
    return sum;
}
int Grid::sum(){
    int sum=0;
    for(int i=0;i<rows*cols;++i)
        sum+=data[i];
    return sum;
}