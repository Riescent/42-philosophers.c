#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>
#include "this_is_not_my_libft.h"

#include "philosophers.h"
#include "philo_time.h"
#include "print_state_change.h"

void	*philosopher_handler(t_dlist *philosopher_node)
{
	t_philosopher	*philosopher;
	struct timeval	time_to_die;
	long			eat_count;
	// eat -> think -> sleep

	philosopher = philosopher_node->content;

	time_to_die = philosopher->start_time;
	add_milliseconds(&time_to_die, philosopher->time_to_die);

	if (philosopher_eats(philosopher, philosopher_node, &time_to_die))
		return (NULL);
	eat_count = philosopher_handler_loop();
	if (eat_count >= 0)
		printf("Philosopher %d has eaten %ld times\n", philosopher->id,
			eat_count - 1);
	return (NULL);
}

long	philosopher_handler_loop()
{
	long	eat_count;

	eat_count = 1;
	while (philosopher->number_of_times_to_eat == -1
		|| eat_count < philosopher->number_of_times_to_eat) {
		if (philosopher_sleeps(philosopher, philosopher_node, &time_to_die))
			return (-1);
		print_state_change(THINK, get_timestamp(philosopher->start_time,
												get_current_time()), philosopher->id);
		if (philosopher_eats(philosopher, philosopher_node, time_to_die))
			return (-1);
		eat_count++;
	}
	return (eat_count);
}

static int philosopher_eats()