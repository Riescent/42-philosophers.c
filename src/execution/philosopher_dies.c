#include <pthread.h>
#include <stdio.h>

#include "philosophers.h"
#include "print_state_change.h"
#include "philo_time.h"

static void	set_thread_should_stop_to_true(t_philosopher *philosopher);

int	philosopher_dies(t_philosopher *philosopher)
{
	pthread_mutex_lock(philosopher->print_mutex);
	if (should_stop_thread(philosopher) == false)
		printf("%lli\t%i "RED"died\n"COLOR_RESET,
			get_timestamp(philosopher->start_time, get_current_time()),
			philosopher->id);
	set_all_threads_should_stop_to_true(philosopher);
	pthread_mutex_unlock(philosopher->print_mutex);
	return (-1);
}

void	set_all_threads_should_stop_to_true(t_philosopher *philosophers)
{
	int	size = philosophers->number_of_philosophers;

	philosophers -= philosophers->id - 1;
	while (size--)
		set_thread_should_stop_to_true(philosophers + size);
}

static void	set_thread_should_stop_to_true(t_philosopher *philosopher)
{
	pthread_mutex_lock(&philosopher->thread_should_stop_mutex);
	philosopher->thread_should_stop = true;
	pthread_mutex_unlock(&philosopher->thread_should_stop_mutex);
}
