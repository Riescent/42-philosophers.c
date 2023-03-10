#include <sys/time.h>
#include <unistd.h>

struct timeval	get_current_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time);
}

long long	get_timestamp(const struct timeval start_time,
				const struct timeval current_time)
{
	return((current_time.tv_sec - start_time.tv_sec) * 1000LL
		+ (current_time.tv_usec - start_time.tv_usec) / 1000);
}

void	sleep_till(const struct timeval goal)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	// TODO check behaviour if result below 0
	usleep((goal.tv_sec - current_time.tv_sec) * 1000000
		+ (goal.tv_usec - current_time.tv_usec));
}

void add_milliseconds(struct timeval *tv, int n)
{
	tv->tv_usec += n * 1000;
	if (tv->tv_usec >= 1000000)
	{
		tv->tv_sec += tv->tv_usec / 1000000;
		tv->tv_usec %= 1000000;
	}
}

int compare_timeval(const struct timeval t1, const struct timeval t2)
{
	if (t1.tv_sec < t2.tv_sec)
		return (-1);
	else if (t1.tv_sec > t2.tv_sec)
		return (1);
	else if (t1.tv_usec < t2.tv_usec)
		return (-1);
	else if (t1.tv_usec > t2.tv_usec)
		return (1);
	return (0);
}