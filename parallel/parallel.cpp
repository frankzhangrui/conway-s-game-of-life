#include <iostream>
#include "Life.h"
using namespace std;
int main(int argc, char ** argv) {
	if(argc==6){
    	int m=atoi(argv[1]);
    	int n=atoi(argv[2]);
    	int gen=atoi(argv[3]);
        MPI_Init(&argc, &argv);
    	Life mylife(m,n,gen);
    	mylife.parallel_simulate(argv[4],argv[5]);
    	MPI_Finalize();
    	return 0;
	}
	return 0;
}
