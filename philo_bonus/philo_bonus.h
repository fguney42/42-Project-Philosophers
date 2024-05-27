#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H


# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <semaphore.h>
# include <signal.h>




# define YES 1
# define NO 0

# define E_MLC "Malloc Error!\n"
# define E_ARG "Arg Error!\n"

# define FREE 1
# define NFREE 0

# define EMPTY -1

# define EAT "\033[0;36m%ld %d is eating\033[0;37m\n"
# define SLEEP "\033[0;33m%ld %d is sleeping\033[0;37m\n"
# define THINK "\033[0;35m%ld %d is thinking\033[0;37m\n"
# define DIE "\033[0;37m%ld %d is died\033[0;37m\n"
# define TAKEN "\033[0;32m%ld %d has taken a fork\033[0;37m\n"


typedef struct s_table
{
	int				numofphilo;
	int				timetodie;
	int				timetoeat;
	int				timetosleep;
	int				philomusteat;
	int				anyone_dead;
	int				all_eat;
	int				sem_msg;
	int				philo_id;
	int				*philo_index;
	int				philo_ate;
	long			philo_last_eat;
	long			start_time;
	sem_t			*print_lock;
	sem_t			*fork_lock;
	pthread_t		die_check_t;
}					t_table;




int					all_must_ate(t_table *table);
void				sem_kill(t_table *table);
long				get_time(void);


int					create_philo(t_table *table);
void				loop(t_table *table);
void				*die_check(void *t);

int					start(t_table *table, int argc, char **argv);
void				free_all(t_table *table);
void				error_manage(void *kill, char *msg, int code);


int					digit_check(int argc, char **argv);
int					check_args(t_table *table, int argc, char **argv);
int					init(t_table *table, int argc, char **argv);
void				init_sem(t_table *table);
int					ft_atoi(const char *str);
int					ft_strisdigit(const char *str);
int					ft_isdigit(int c);

#endif