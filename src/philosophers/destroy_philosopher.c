#include <pthread.h>
#include <stdlib.h>

#include "philosophers.h"

void	destroy_philosophers(t_philosopher *philosophers)
{
	size_t	size;

	size = philosophers->number_of_philosophers;
	while (size--)
		destroy_philosopher(philosophers + size);
	free(philosophers);
}

void	destroy_philosopher(t_philosopher *philosopher)
{
	pthread_mutex_destroy(&philosopher->right_fork_mutex);
	pthread_mutex_destroy(&philosopher->thread_should_stop_mutex);
}
