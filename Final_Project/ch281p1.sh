export OMP_NUM_THREADS=1
g++ Chem281P1.cpp -o Chem281P1 -fopenmp -lpthread
./Chem281P1
export OMP_NUM_THREADS=2
./Chem281P1
export OMP_NUM_THREADS=3
./Chem281P1

export OMP_NUM_THREADS=4
./Chem281P1

export OMP_NUM_THREADS=5
./Chem281P1

export OMP_NUM_THREADS=6
./Chem281P1

export OMP_NUM_THREADS=7
./Chem281P1

export OMP_NUM_THREADS=8
./Chem281P1


