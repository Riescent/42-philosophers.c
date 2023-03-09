#include <stdio.h>

#include "ft_colors.h"

#include "print_state_change.h"

void	print_state_change(enum e_state state, size_t timestamp_in_ms,
			size_t philo_id)
{
	if (state == FORK)
		printf("%zu\t%zu "PURPLE"has taken a fork\n"COLOR_RESET,
			   timestamp_in_ms, philo_id);
	if (state == EAT)
		printf("%zu\t%zu "GREEN"is eating\n"COLOR_RESET,
			   timestamp_in_ms, philo_id);
	if (state == SLEEP)
		printf("%zu\t%zu "BLACK_HIGH_INTENSITY"is sleeping\n"COLOR_RESET,
			   timestamp_in_ms, philo_id);
	if (state == THINK)
		printf("%zu\t%zu "YELLOW"is thinking\n"COLOR_RESET,
			   timestamp_in_ms, philo_id);
	if (state == DIE)
		printf("%zu\t%zu "RED"died\n"COLOR_RESET,
			   timestamp_in_ms, philo_id);
}
