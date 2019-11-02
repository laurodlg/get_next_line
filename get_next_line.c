/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-la-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:44:10 by lde-la-g          #+#    #+#             */
/*   Updated: 2019/11/01 19:38:58 by lde-la-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_freen(void *a)
{
	if (a)
	{
		free(a);
		a = NULL;
	}
}

void	ft_gnl(int fd, char **perm, char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	while (perm[fd][i] != '\0' && perm[fd][i] != '\n')
		i++;
	if ((tmp = ft_strchr(perm[fd], '\n')))
	{
		tmp = ft_strdup(tmp + 1);
		*line = ft_strsub(perm[fd], 0, i);
		free(perm[fd]);
		perm[fd] = NULL;
		if (tmp[0] == '\0')
			perm[fd] = NULL;
		else
			perm[fd] = ft_strdup(tmp);
		ft_freen(tmp);
	}
	else
	{
		ft_freen(tmp);
		*line = ft_strdup(perm[fd]);
		free(perm[fd]);
		perm[fd] = NULL;
	}
}

int		buff_one(char *buff, char *perm)
{
	char	v;

	v = buff[0];
	if (BUFF_SIZE == 1 && v != '\n')
		return (1);
	else if (BUFF_SIZE == 1 && v == '\n')
		return (0);
	if (ft_strchr(perm, '\n'))
		return (0);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	int			readchr;
	char		buff[BUFF_SIZE + 1];
	char		*tmp;
	static char *perm[SIZE_OF];

	if (fd < 0)
		return (-1);
	while ((readchr = read(fd, buff, BUFF_SIZE)) >= 1)
	{
		buff[readchr] = '\0';
		(perm[fd] == NULL) ? perm[fd] = ft_strnew(1) : 0;
		tmp = ft_strjoin(perm[fd], buff);
		free(perm[fd]);
		perm[fd] = ft_strdup(tmp);
		ft_freen(tmp);
		if (check_char(buff, perm[fd]) == 0)
			break ;
	}
	if (readchr < 0)
		return (-1);
	else if (readchr == 0 && perm[fd] == NULL)
		return (0);
	(ft_gnl(fd, perm, line));
	return (1);
}
