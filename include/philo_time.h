#ifndef PHILO_TIME_H
# define PHILO_TIME_H

struct timeval	get_current_time(void);
long long		get_timestamp(struct timeval start_time,
					struct timeval current_time);
void			sleep_till(struct timeval goal);
void 			add_milliseconds(struct timeval *tv, int n);
int 			compare_timeval(struct timeval t1, struct timeval t2);

#endif //PHILO_TIME_H
