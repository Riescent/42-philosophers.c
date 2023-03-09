#include <sys/time.h>

long long	get_timestamp(const struct timeval start_time)
{
	struct timeval current_time;

	gettimeofday(&current_time, NULL);
	return((current_time.tv_sec - start_time.tv_sec) * 1000LL
		+ (current_time.tv_usec - start_time.tv_usec) / 1000);
}
