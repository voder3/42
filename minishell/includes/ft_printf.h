/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:58:37 by artderva          #+#    #+#             */
/*   Updated: 2019/12/03 19:30:56 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include <stdarg.h>

typedef	struct		s_prin
{
	char	type;
	char	flag[5];
	int		lenw;
	int		prec;
	int		lenm;
}					t_prin;

int					ft_getfs(char **str, t_prin *fors);
int					ft_dis(va_list ap, t_prin fors, char **prin);
int					ft_prchar(va_list ap, t_prin fors, char **prin);
int					ft_prstr(va_list ap, t_prin fors, char **prin);
int					ft_prpoi(va_list ap, t_prin fors, char **prin);
int					ft_prnbr(va_list ap, t_prin fors, char **prin);
int					ft_proct(va_list ap, t_prin fors, char **prin);
int					ft_prund(va_list ap, t_prin fors, char **prin);
int					ft_prhex(va_list ap, t_prin fors, char **prin);
int					ft_prhem(va_list ap, t_prin fors, char **prin);
int					ft_prflo(va_list ap, t_prin fors, char **prin);
int					ft_prper(va_list ap, t_prin fors, char **prin);

char				*ft_prneg(char *str, t_prin fors);

char				*ft_straddc(char *str, char c);
char				*ft_straddcb(int add, char *str);
char				*ft_strndup(char *src, int n);
char				*ft_addzero(char *str, int len);

char				*ft_minus(t_prin fors, char *str, char *tmp);

char				*ft_free(char *str);
char				*ft_free2(char *s1, char *s2);
int					ft_free3(char *str);

char				*ft_lenm_o(long long n, t_prin fors);
char				*ft_lenm_u(long long n, t_prin fors);
char				*ft_lenm_h(long long n, t_prin fors);
char				*ft_lenm_hx(long long n, t_prin fors);

int					ft_printf(const char *format, ...);

#endif
