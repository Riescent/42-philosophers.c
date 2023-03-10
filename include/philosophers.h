#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

#include "this_is_not_my_libft.h"

typedef struct s_philosopher
{
	bool			thread_should_stop;
	pthread_mutex_t	thread_should_stop_mutex;
	int 			id;
	int 			number_of_philosophers;
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

t_philosopher	*init_philosophers(const int args[5]);
int				run_philosopher(t_philosopher *philosophers);
void			*philosopher_handler(void *philosopher_void);
void			destroy_philosophers(t_philosopher *philosophers);
void			destroy_philosopher(t_philosopher *philosopher);
int				compare_timeval(struct timeval t1, struct timeval t2);

void		set_all_threads_should_stop_to_true(t_philosopher *philosophers);


#endif //PHILOSOPHERS_H
