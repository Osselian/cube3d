/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 21:04:01 by defimova          #+#    #+#             */
/*   Updated: 2024/07/12 17:29:05 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
Аргументы:
c: Символ для вывода.
fd: Файловый дескриптор, в который выполняется запись.

Возвращаемое значение: нет

Описание:
Выводит символ ’c’ для данного файлового
дескриптора.
*/