#! /bin/bash

cd serial 
make
./test_serial  5 5 5 small_input small_output
echo "validating the correctness of sequential program"
./test_serial  500 500 5 large_input large_output
make clean
cd ..
cd parallel 
make 
mpirun -np 5 test_parallel 500 500 5 large_input large_output
make clean