#include <stdio.h>
#include <pthread.h>

#include "this_is_not_my_libft.h"

#include "philosophers.h"
#include "philo_time.h"

static void *philosopher_handler(void *arg);

int	run_philosopher(t_dlist *philosophers, const int number_of_philosophers)
{
	t_dlist			*cursor;
	t_philosopher	*philosopher;

	if (number_of_philosophers == 1)
		return (printf("Single philosopher not supported yet\n"), 0);
	if (ft_dlstsize(philosophers) != number_of_philosophers)
		printf("Unexpected number of philosophers\n");
	cursor = philosophers;
	while (cursor != NULL)
	{
		philosopher = cursor->content;
		if (pthread_create(&philosopher->thread, NULL, philosopher_handler,
			cursor) != 0)
			printf("Handle error\n"); // TODO
		cursor = cursor->next;
	}
	cursor = philosophers;
	while (cursor != NULL)
	{
		philosopher = cursor->content;
		pthread_join(philosopher->thread, NULL);
		cursor = cursor->next;
	}
}
