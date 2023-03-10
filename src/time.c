#include <sys/time.h>
#include <unistd.h>

long long	get_timestamp(const struct timeval start_time)
{
	struct timeval current_time;

	gettimeofday(&current_time, NULL);
	return((current_time.tv_sec - start_time.tv_sec) * 1000LL
		+ (current_time.tv_usec - start_time.tv_usec) / 1000);
}

void	sleep_till(const struct timeval current_time, const struct timeval goal)
{
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