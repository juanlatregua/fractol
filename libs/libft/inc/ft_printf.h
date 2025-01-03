/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilva-m <jsilva-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 09:35:34 by jsilva-m          #+#    #+#             */
/*   Updated: 2024/10/25 10:10:57 by jsilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*---------------------------  Librerias  ------------------------------------*/
# include "./libft.h"
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/*---------------------------  Macros  ---------------------------------------*/
# define PRINTF_FLAG "0+-# hl"

/*---------------------------  Estructuras  ----------------------------------*/
typedef struct s_flags
{
	int		len_h;
	int		len_hh;
	int		len_l;
	int		len_ll;

}			t_flags;

typedef struct s_block
{
	int		ret;
	int		i;
	char	type;
	char	*s;
	va_list	ap;
	t_flags	flags;

}			t_block;

/*---------------------------  Funciones  ------------------------------------*/
int			ft_printf(const char *str, ...);
void		reset_block_pf(t_block *b);
// Funciones de chequeo
void		checkflags_pf(const char *str, t_block *b);
void		checktypes_pf(const char *str, t_block *b);
// Funciones para convertir
void		ft_converter_cs(char type, t_block *b);
void		ft_converter_id(t_block *b);
void		ft_converter_u(t_block *b);
void		ft_converter_x(char type, t_block *b);
void		ft_converter_o(t_block *b);
void		ft_converter_p(t_block *b);
// Funciones para imprimir

void		print_char_pf(char c, t_block *b);
void		print_str_pf(t_block *b);
void		print_null_pf(t_block *b);
void		print_dig_pf(t_block *b);

#endif
