#ifndef PRINT_STATE_CHANGE_H
# define PRINT_STATE_CHANGE_H

#include "philosophers.h"

enum e_state
{
	FORK,
	EAT,
	SLEEP,
	THINK,
	DIE,
	DONE,
};

int	print_state_change(enum e_state state, t_philosopher *philosopher);

#endif
