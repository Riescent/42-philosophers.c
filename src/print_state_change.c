#include <stdio.h>

#include "ft_colors.h"

#include "print_state_change.h"

void	print_state_change(enum e_state state, size_t timestamp_in_ms,
			size_t philo_id)
{
	printf("%zu\t%zu ", timestamp_in_ms, philo_id);
	if (state == FORK)
		printf(PURPLE"has taken a fork\n"COLOR_RESET);
	if (state == EAT)
		printf(GREEN"is eating\n"COLOR_RESET);
	if (state == SLEEP)
		printf(BLACK_HIGH_INTENSITY"is sleeping\n"COLOR_RESET);
	if (state == THINK)
		printf(YELLOW"is thinking\n"COLOR_RESET);
	if (state == DIE)
		printf(RED"died\n"COLOR_RESET);
}
