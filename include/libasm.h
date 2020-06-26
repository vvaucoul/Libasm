/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 14:34:39 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/06/20 20:13:52 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

/*
**	Define .s functions
*/

int		ft_strlen(const char *str);
char	*ft_strcpy(char *s1, const char *s2);
size_t	ft_read(int fildes, void *buf, size_t nbyte);
ssize_t	ft_write(int fildes, const void *buf, size_t nbyte);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *s1);

#endif
