#ifndef PRINT_STATE_CHANGE_H
# define PRINT_STATE_CHANGE_H

# include <stddef.h>

enum e_state
{
	FORK,
	EAT,
	SLEEP,
	THINK,
	DIE,
};

void	print_state_change(enum e_state state, size_t timestamp_in_ms,
			size_t philo_id);

#endif
