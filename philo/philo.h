#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
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


typedef struct s_philo
{
	int				philo_id;
	int				r_fork_id;
	int				l_fork_id;
	int				eat_count;
	long			last_eat;
	pthread_t		id;
	pthread_t		print;
	struct s_table	*table;
}					t_philo;

typedef struct s_table
{
	int				numofphilo;
	int				timetodie;
	int				timetoeat;
	int				timetosleep;
	int				philomusteat;
	int				anyone_dead;
	int				all_eat;
	long			start_time;
	t_philo			*philos;
	pthread_mutex_t	print_m;
	pthread_mutex_t	*forks;
}					t_table;


int					digit_check(int argc, char **argv);
int					check_args(t_table *table, int argc, char **argv);
int					init_philo(t_table *table);
int					init_forks(t_table *table);
int					init(t_table *table, int argc, char **argv);


void				meal(t_philo *philo);
void				sleeping(t_philo *philo);
void				think(t_philo *philo);


int					all_must_ate(t_table *table);
long				get_time(void);
void				time_skip(long time);
void				print_status(char *msg, t_philo *philo, long current);


int					create_philo(t_table *table);
int					all_must_ate(t_table *table);
void				*loop(void *tab);

int					start(t_table *table, int argc, char **argv);
void				free_all(t_table *table);
void				error_manage(void *kill, char *msg, int code);
int					ft_atoi(const char *str);
int					ft_strisdigit(const char *str);
int					ft_isdigit(int c);

#endif