#include<iostream>
#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/stat.h>
using namespace std;
int main(void){
	int segment_id;
	char * shared_memory;
	struct shmid_ds shmbuffer;
	int segment_size;
	const int shared_segment_size = 0x6400;
	int pid;
	/* Allocate a shared memory segment */
	segment_id = shmget( IPC_PRIVATE, shared_segment_size,
			IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR );
	/* Attach the shared memory segment. */
	shared_memory = (char*) shmat( segment_id, 0, 0 );
	//printf("shared memory attached at address %p\n", shared_memory);
	/* Determine the segment's size. */
	shmctl( segment_id, IPC_STAT, &shmbuffer );
	segment_size = shmbuffer.shm_segsz;
	/* Write a string to the shared memory segment. */
	if( pid=fork()>0 ){//child
		sprintf(shared_memory, "Child at: 	%p\n", shared_memory);
	}else{//parent
		printf("%s", shared_memory);
		printf("Parent at: 	%p\n", shared_memory );
	}
	/* detach the shared memory segment. */
	//shmdt( shared_memory );
	/* Reattach the shared memory segment, at a different address. */
	//shared_memory = (char*) shmat( segment_id, (void*)0x50000000, 0 );
	//printf("Shared memory attached at address %p\n", shared_memory);
	/* Print out the string from shared memory. */
	//printf("%s\n", shared_memory);
	/* Detach the shared memory segment. */
	shmdt( shared_memory );
	/* Deallocate the shared memory segment. */
	shmctl( segment_id, IPC_RMID, 0 );
	return 0;
}
