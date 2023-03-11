#include <stdio.h>
#include <pthread.h>

#include "ft_colors.h"

#include "print_state_change.h"
#include "philosophers.h"
#include "philo_time.h"

static void	print_change(enum e_state state, t_philosopher *philosopher);

int	print_state_change(enum e_state state, t_philosopher *philosopher)
{
	pthread_mutex_lock(philosopher->print_mutex);
	if (should_stop_thread(philosopher))
	{
		pthread_mutex_unlock(philosopher->print_mutex);
		return (-1);
	}
	else
		print_change(state, philosopher);
	pthread_mutex_unlock(philosopher->print_mutex);
	return (0);
}

static void	print_change(enum e_state state, t_philosopher *philosopher)
{
	long long	timestamp = get_timestamp(philosopher->start_time,
			get_current_time());

	if (state == FORK)
		printf("%lli\t%i "YELLOW"has taken a fork\n"COLOR_RESET, timestamp,
			philosopher->id);
	else if (state == EAT)
		printf("%lli\t%i "GREEN"is eating\n"COLOR_RESET, timestamp,
			philosopher->id);
	else if (state == SLEEP)
		printf("%lli\t%i "BLACK_HIGH_INTENSITY"is sleeping\n"COLOR_RESET,
			timestamp, philosopher->id);
	else if (state == THINK)
		printf("%lli\t%i "PURPLE"is thinking\n"COLOR_RESET, timestamp,
			philosopher->id);
	else if (state == DIE)
		printf("%lli\t%i "RED"died\n"COLOR_RESET, timestamp, philosopher->id);
	else
		printf("%lli\t%i "BLUE"died of old age after eating %i times\n"
			COLOR_RESET, timestamp, philosopher->id, philosopher->times_eaten);
}
