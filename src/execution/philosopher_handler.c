#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>
#include "this_is_not_my_libft.h"

#include "philosophers.h"
#include "philo_time.h"
#include "print_state_change.h"

static int	philosopher_handler_loop(t_philosopher *philosopher,
				int (*function_1)(t_philosopher *, struct timeval *),
				int (*function_2)(t_philosopher *, struct timeval *));
static int	philosopher_eats(t_philosopher *philosopher,
				struct timeval *time_to_die);
static int	philosopher_sleeps(t_philosopher *philosopher,
				struct timeval *time_to_die);

void	*philosopher_handler(void *philosopher_void)
{
	t_philosopher	*philosopher;

	philosopher = philosopher_void;
	if (philosopher->id % 2)
	{
		if (philosopher_handler_loop(philosopher,
				&philosopher_eats, &philosopher_sleeps) < 0)
			return (NULL);
	}
	else
	{
		if (philosopher_handler_loop(philosopher,
				 &philosopher_sleeps, &philosopher_eats) < 0)
			return (NULL);
	}
	print_state_change(DONE, philosopher);
	return (NULL);
}

static int	philosopher_handler_loop(t_philosopher *philosopher,
				int (*function_1)(t_philosopher *, struct timeval *),
				int (*function_2)(t_philosopher *, struct timeval *))
{
	struct timeval time_to_die;

	time_to_die = philosopher->start_time;
	add_milliseconds(&time_to_die, philosopher->time_to_die);
	if (function_1(philosopher, &time_to_die))
		return (-1);
	while (philosopher->number_of_times_to_eat == -1
		|| philosopher->times_eaten < philosopher->number_of_times_to_eat)
	{
		if (function_2(philosopher, &time_to_die))
			return (-1);
		if (function_1(philosopher, &time_to_die))
			return (-1);
	}
	return (0);
}

static int	philosopher_eats(t_philosopher *philosopher,
				struct timeval *time_to_die)
{
	struct timeval	current_time;
	struct timeval	time_to_eat;

	lock_forks(philosopher);
	gettimeofday(&current_time, NULL);
	if (compare_timeval(*time_to_die, current_time) <= 0)
	{
		sleep_till(*time_to_die);
		unlock_forks(philosopher);
		return (philosopher_dies(philosopher));
	}
	*time_to_die = current_time;
	if (print_state_change(EAT, philosopher))
	{
		unlock_forks(philosopher);
		return (-1);
	}
	time_to_eat = *time_to_die;
	add_milliseconds(time_to_die, philosopher->time_to_die);
	add_milliseconds(&time_to_eat, philosopher->time_to_eat);
	if (compare_timeval(*time_to_die, time_to_eat) <= 0)
	{
		sleep_till(*time_to_die);
		unlock_forks(philosopher);
		return (philosopher_dies(philosopher));
	}
	sleep_till(time_to_eat);
	unlock_forks(philosopher);
	philosopher->times_eaten++;
	return (0);
}

static int	philosopher_sleeps(t_philosopher *philosopher,
				struct timeval *time_to_die)
{
	struct timeval	time_to_sleep;

	gettimeofday(&time_to_sleep, NULL);
	add_milliseconds(&time_to_sleep, philosopher->time_to_sleep);
	if (compare_timeval(*time_to_die, time_to_sleep) <= 0)
	{
		sleep_till(*time_to_die);
		return (philosopher_dies(philosopher));
	}
	if (print_state_change(SLEEP, philosopher))
		return (-1);
	sleep_till(time_to_sleep);
	return (print_state_change(THINK, philosopher));
}
