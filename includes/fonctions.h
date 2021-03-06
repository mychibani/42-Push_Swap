/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 11:02:15 by ychibani          #+#    #+#             */
/*   Updated: 2022/03/24 12:10:20 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FONCTIONS_H
# define FONCTIONS_H

typedef struct s_stack		t_stack;
typedef struct s_data		t_data;
typedef struct s_op			t_op;

struct s_stack
{
	int		data;
	int		index;

	t_stack	*prev;
	t_stack	*next;
};

struct s_data
{
	t_stack		*head;
	size_t		size;
	char		*string;
};

struct s_op
{
	int	pos_a;
	int	pos_b;
	int	rrr;
	int	rr;
	int	rra;
	int	rrb;
	int	ra;
	int	rb;
	int	max_op;
};

enum	e_op
{
	PA,
	PB,
	SA,
	SB,
	SS,
	RA,
	RB,
	RRA,
	RRB,
	RRR,
};

//init
int			_init_stacks_(t_data **a, t_data **b);
int			_init_stacks_(t_data **a, t_data **b);
int			_sorting_prep_(t_data *a);
int			_init_(t_data *a);
int			_is_duplicate_elem_(t_data *a);
int			_is_sorted_stack_(t_data *a);
int			*_init_index_tab(int size);
int			_index_sort(t_data *a);
void		reinit_op(t_op *new);
t_op		*init_op(void);

//parsing
int			_parse_(int ac, char **av, t_data *prog);
int			ft_atoi(char *str);
int			ft_strlen(char *str);
int			ft_isdigit(char c);
int			ft_putstr_fd(char *str, int fd);
int			ft_check_str(char *str);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(char *str);

//lst_utils
void		ft_lstadd_back_data(t_data *a, int data);
void		ft_lstpush_back_data(t_data *data, t_stack *node);
void		ft_lstpush_front_data(t_data *data, t_stack *node);
t_stack		*ft_lstnew_doubly_linked(int data);

//tests_utils
void		ft_print_elem(t_stack *node);
void		_print_data_(t_data *data);
void		_swap_(t_data *data, t_data *b);
void		_print_op_(t_op *op);

//operations
int			pb(t_data *a, t_data *b, char *str);
int			pa(t_data *a, t_data *b, char *str);
int			sa(t_data *a, char *str);
int			sb(t_data *b, char *str);
int			ss(t_data *a, t_data *b, char *str);
int			ra(t_data *a, char *str);
int			rb(t_data *b, char *str);
int			rr(t_data *a, t_data *b, char *str);
int			rra(t_data *a, char *str);
int			rrb(t_data *b, char *str);
int			rrr(t_data *a, t_data *b, char *str);

//algorithms
int			_sorting_prep_(t_data *a);
void		_algo_prep_(t_data *a, t_data *b, size_t opti);
int			_small_sort_(t_data *a);
int			_main_algorithm_(t_data *a, t_data *b, t_op *op);
void		_next_greater_(t_data *a, int to_check, int pos_b, t_op **op);
void		_rotate_(t_data *a, t_data *b, t_op **op);
void		_reset_stack_(t_data *a, t_data *b, t_op *op, t_op *op_to_kill);
int			_calcul_positions_(t_data *a, t_data *b, t_op *op);
int			_sorting_algorithms_(t_data *a, t_data *b, t_op *op);

//algo_utils

int			_find_max_(t_data *stack);
int			_sum_op_(t_op *op);

//checker

char		*__gnl(int fd);
char		*_strjoin(char *s1, char *s2);
int			ft_strcmp(char *s1, char *s2);

//clean

void		_list_clean_(t_data *list, void (*free_data)(void *));
void		_clean_(t_data *a, t_data *b, t_op *op);
#endif
