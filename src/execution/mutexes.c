#include <pthread.h>

#include "philosophers.h"

void	lock_forks(t_philosopher *philosopher)
{
	if (philosopher->id % 2)
	{
		pthread_mutex_lock(&philosopher->right_fork_mutex);
		pthread_mutex_lock(philosopher->left_fork_mutex);
	}
	else
	{
		pthread_mutex_lock(philosopher->left_fork_mutex);
		pthread_mutex_lock(&philosopher->right_fork_mutex);
	}
}

void	unlock_forks(t_philosopher *philosopher)
{
	pthread_mutex_unlock(&philosopher->right_fork_mutex);
	pthread_mutex_unlock(philosopher->left_fork_mutex);
}

bool	should_stop_thread(t_philosopher *philosopher)
{
	bool	ret;

	pthread_mutex_lock(&philosopher->thread_should_stop_mutex);
	ret = philosopher->thread_should_stop;
	pthread_mutex_unlock(&philosopher->thread_should_stop_mutex);
	return (ret);
}
