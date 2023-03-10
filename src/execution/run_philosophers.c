#include <stdio.h>
#include <pthread.h>

#include "this_is_not_my_libft.h"

#include "philosophers.h"
#include "philo_time.h"

int	run_philosopher(t_philosopher *philosophers)
{
	int	size;
	int	i;

	if (philosophers->number_of_philosophers == 1)
		return (printf("Single philosopher not supported yet\n"), 0);
	size = philosophers->number_of_philosophers;
	i = -1;
	while (++i < size)
	{
		if (pthread_create(&philosophers[i].thread, NULL, &philosopher_handler,
				philosophers + i) != 0)
			printf("Handle error\n"); // TODO
	}
	while (size--)
		pthread_join(philosophers[size].thread, NULL);
	return (0);
}
