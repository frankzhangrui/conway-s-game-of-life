//
//  main.cpp
//  Life of Conner-serial
//
//  Created by RUI Zhang on 3/3/15.
//  Copyright (c) 2015 ruizhang. All rights reserved.
//

#include <iostream>
#include "Life.h"
using namespace std;
int main(int argc, char ** argv) {
	if(argc==6){
    	int m=atoi(argv[1]);
    	int n=atoi(argv[2]);
    	int gen=atoi(argv[3]);
    	Life mylife(m,n,gen);
    	mylife.serial_simulate(argv[4],argv[5]);
        return 0;
	}
    return 0;
}
