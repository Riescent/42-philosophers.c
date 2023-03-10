#ifndef PHILO_TIME_H
# define PHILO_TIME_H

long long	get_timestamp(const struct timeval start_time);
void		sleep_till(const struct timeval current_time,
				const struct timeval goal);
void 		add_milliseconds(struct timeval *tv, int n);

#endif //PHILO_TIME_H
