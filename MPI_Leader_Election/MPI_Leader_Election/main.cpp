#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MASTER 0

int main(int argc, char** argv) {

	int numprocs, procid, len, partner, message;
	int value = 0, max = 0, recvvalue = 0;

	char hostname[MPI_MAX_PROCESSOR_NAME];

	MPI_Init(NULL, NULL);
	MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
	MPI_Comm_rank(MPI_COMM_WORLD, &procid);
	MPI_Get_processor_name(hostname, &len);
	MPI_Status status;
	

	srand(time(NULL));
	value = rand() % numprocs;

	if (procid == MASTER)
	{
		MPI_Send(&value, 1, MPI_INT, procid + 1, 1, MPI_COMM_WORLD);
	}
	else
	{

	}

	MPI_Send(&subvector, step, MPI_INT, i, i, MPI_COMM_WORLD);
	MPI_Recv(&subvector, step, MPI_INT, MASTER, procid, MPI_COMM_WORLD, &status);

	

}