#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MASTER 0

int main(int argc, char** argv) {

	int numprocs, procid, len, partner, message;
    int value = 0;
    int value_id_pair[2] = { 0, 0 };
    int recv_value_id_pair[2] = { 0, 0 };
    int max_value_id_pair[2] = { 0, 0 };

	char hostname[MPI_MAX_PROCESSOR_NAME];

	MPI_Init(NULL, NULL);
	MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
	MPI_Comm_rank(MPI_COMM_WORLD, &procid);
	MPI_Get_processor_name(hostname, &len);
	MPI_Status status;
	

	srand(time(NULL));
	value = rand() % numprocs;
    printf("Process %d generated number: %d \n", procid, value);
    value_id_pair[0] = value;
    value_id_pair[1] = procid;
    for (int i = 0; i < numprocs; i++)
    {
        if (i != procid)
        {
            MPI_Send(&value_id_pair, 2, MPI_INT, i, 0, MPI_COMM_WORLD);
            MPI_Recv(&recv_value_id_pair, 2, MPI_INT, i, procid, MPI_COMM_WORLD, &status);
            if (max_value_id_pair[0] < recv_value_id_pair[0])
            {
                max_value_id_pair[0] = recv_value_id_pair[0];
                max_value_id_pair[1] = recv_value_id_pair[1];
            }
            else if (max_value_id_pair[0] == recv_value_id_pair[0])
            {
                if (max_value_id_pair[1] < recv_value_id_pair[1])
                {
                    max_value_id_pair[0] = recv_value_id_pair[0];
                    max_value_id_pair[1] = recv_value_id_pair[1];
                }
            }
        }
    }

    for (int i = 0; i < numprocs;i++)
    {
        if (i != procid)
        {
           
        }
    }


    MPI_Finalize();
    printf("Leader is process %d with the value: %d", max_value_id_pair[1], max_value_id_pair[0]);

	

}