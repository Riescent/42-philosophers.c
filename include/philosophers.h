#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

#include "this_is_not_my_libft.h"

typedef struct s_philosopher
{
	bool			thread_should_stop;
	int 			id;
	struct timeval	start_time;
	int 			time_to_die;
	int 			time_to_eat;
	int 			time_to_sleep;
	int 			number_of_times_to_eat;
	pthread_t 		thread;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	right_fork;
}	t_philosopher;

int	run_philosopher(t_dlist *philosophers, const int number_of_philosophers);
t_dlist	*init_philosophers(const int args[5]);
void	destroy_philosopher(void *philosopher_void);

#endif //PHILOSOPHERS_H
