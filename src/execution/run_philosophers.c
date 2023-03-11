#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>

#include "this_is_not_my_libft.h"

#include "philosophers.h"
#include "philo_time.h"

int	run_philosopher(t_philosopher *philosophers)
{
	int	size;
	int	i;
	struct timeval	current_time;

	if (philosophers->number_of_philosophers == 1)
		return (printf("Single philosopher not supported yet\n"), 0);
	size = philosophers->number_of_philosophers;
	i = -1;
	gettimeofday(&current_time, NULL);
	while (++i < size)
	{
		philosophers[i].start_time = current_time;
		if (pthread_create(&philosophers[i].thread, NULL, &philosopher_handler,
				philosophers + i) != 0)
		{
			set_all_threads_should_stop_to_true(philosophers);
			printf("Failed to start all threads\n");
			break ;
		}
	}
	while (size--)
		pthread_join(philosophers[size].thread, NULL);
	return (0);
}
