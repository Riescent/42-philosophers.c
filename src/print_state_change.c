#include <stdio.h>

#include "ft_colors.h"

#include "print_state_change.h"
#include "philosophers.h"
#include "philo_time.h"

void	print_state_change(enum e_state state, t_philosopher *philosopher)
{
	const long long	timestamp = get_timestamp(philosopher->start_time,
			get_current_time());

	if (state == FORK)
		printf("%lli\t%i "PURPLE"has taken a fork\n"COLOR_RESET, timestamp,
			philosopher->id);
	if (state == EAT)
		printf("%lli\t%i "GREEN"is eating\n"COLOR_RESET, timestamp,
			philosopher->id);
	if (state == SLEEP)
		printf("%lli\t%i "BLACK_HIGH_INTENSITY"is sleeping\n"COLOR_RESET,
			timestamp, philosopher->id);
	if (state == THINK)
		printf("%lli\t%i "YELLOW"is thinking\n"COLOR_RESET, timestamp,
			philosopher->id);
	if (state == DIE)
		printf("%lli\t%i "RED"died\n"COLOR_RESET, timestamp, philosopher->id);
	if (state == DONE)
		printf("%lli\t%i "BLUE"died of old age after eating %i times\n"
				COLOR_RESET, timestamp, philosopher->id,
				philosopher->times_eaten);
}
