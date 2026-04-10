/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adarmoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:49:31 by adarmoya          #+#    #+#             */
/*   Updated: 2026/02/25 15:01:14 by adarmoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
int		ft_putnbr(int n);
int		ft_putstr(char *s);
int		ft_putnbr_un(unsigned int n);
int		ft_put_hex(unsigned int n, char k);
int		ft_put_address(void *ptr);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *s);

#endif
