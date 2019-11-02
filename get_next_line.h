/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-la-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 20:27:02 by lde-la-g          #+#    #+#             */
/*   Updated: 2019/11/01 19:56:45 by lde-la-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32
# define SIZE_OF 4500

# include "libft/libft.h"
# include <stdlib.h>

int		get_next_line(const int fd, char **line);
void	ft_gnl(int fd, char **s, char **line);
void	ft_freen(void *a);
int		buff_one(char *buff, char *perm);
#endif
