#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>
#include "this_is_not_my_libft.h"

#include "philosophers.h"
#include "philo_time.h"
#include "print_state_change.h"

static int	philosopher_handler_loop(t_philosopher *philosopher);
static int	philosopher_eats(t_philosopher *philosopher,
				struct timeval *time_to_die);
static int	philosopher_sleeps(t_philosopher *philosopher,
				struct timeval time_to_die);

void	*philosopher_handler(void *philosopher)
{
	if (philosopher_handler_loop(philosopher) < 0)
		return (NULL);
	print_state_change(DONE, philosopher);
	return (NULL);
}

static int	philosopher_handler_loop(t_philosopher *philosopher)
{
	struct timeval time_to_die;

	time_to_die = philosopher->start_time;
	add_milliseconds(&time_to_die, philosopher->time_to_die);
	if (philosopher_eats(philosopher, &time_to_die))
		return (-1);
	philosopher->times_eaten++;
	while (philosopher->number_of_times_to_eat == -1
		|| philosopher->times_eaten < philosopher->number_of_times_to_eat)
	{
		if (philosopher_sleeps(philosopher, time_to_die))
			return (-1);
		print_state_change(THINK, philosopher);
		if (philosopher_eats(philosopher, &time_to_die))
			return (-1);
		philosopher->times_eaten++;
	}
	return (0);
}

static int	philosopher_eats(t_philosopher *philosopher,
				struct timeval *time_to_die)
{
	(void)philosopher;
	(void)time_to_die;
	return (-1);
}

static int	philosopher_sleeps(t_philosopher *philosopher,
				struct timeval time_to_die)
{
	(void)philosopher;
	(void)time_to_die;
	return (-1);
}