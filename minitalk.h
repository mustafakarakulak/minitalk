/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:39:56 by mkarakul          #+#    #+#             */
/*   Updated: 2023/01/19 19:39:56 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include<unistd.h>
# include<signal.h>
# include<stdlib.h>

void	ft_putchar(int c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
int		ft_ascii_toint(char *str);
#endif
