/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:22:58 by mkarakul          #+#    #+#             */
/*   Updated: 2023/01/18 12:42:35 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H

# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <signal.h>
# include <stdio.h>

int		ft_atoi(const char *str);

void	ft_itoa(int pid);

#endif