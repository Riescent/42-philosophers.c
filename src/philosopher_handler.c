#include "this_is_not_my_libft.h"
#include "philosophers.h"
#include "philo_time.h"

static void *philosopher_handler(void *arg)
{
	t_dlist			*philosopher_node;
	t_philosopher	*philosopher;
	struct timeval	time_goal;
	// eat -> think -> sleep

	philosopher_node = arg;
	philosopher = philosopher_node->content;
	time_goal = philosopher->start_time;
	if (philosopher->time_to_die < philosopher->time_to_eat)
		add_milliseconds(&time_goal, philosopher->time_to_die);
}
