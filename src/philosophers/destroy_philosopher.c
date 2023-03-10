#include <pthread.h>
#include <stdlib.h>

#include "philosophers.h"

void	destroy_philosopher(void *philosopher_void)
{
	t_philosopher	*philosopher;

	if (philosopher_void == NULL)
		return ;
	philosopher = philosopher_void;
	pthread_mutex_destroy(&philosopher->right_fork_mutex);
	pthread_mutex_destroy(&philosopher->thread_should_stop_mutex);
	free(philosopher);
}
