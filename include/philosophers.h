#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

#include "this_is_not_my_libft.h"

typedef struct s_philosopher
{
	bool			thread_should_stop;
	pthread_mutex_t	thread_should_stop_mutex;
	int 			id;
	struct timeval	start_time;
	int 			time_to_die;
	int 			time_to_eat;
	int 			time_to_sleep;
	int 			number_of_times_to_eat;
	int 			times_eaten;
	pthread_t 		thread;
	pthread_mutex_t	*left_fork_mutex;
	pthread_mutex_t	right_fork_mutex;
}	t_philosopher;

int		run_philosopher(t_dlist *philosophers, int number_of_philosophers);
void	*philosopher_handler(t_dlist *philosopher_node);
t_dlist	*init_philosophers(const int args[5]);
void	destroy_philosopher(void *philosopher_void);
int		compare_timeval(struct timeval t1, struct timeval t2);

#endif //PHILOSOPHERS_H
