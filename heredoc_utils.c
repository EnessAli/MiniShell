/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egermen <egermen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 00:06:33 by egermen           #+#    #+#             */
/*   Updated: 2024/08/10 00:06:34 by egermen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <readline/readline.h>
#include <sys/ioctl.h>
#include <unistd.h>

void	killer(int sig)
{
	(void)sig;
	g_check_heredoc = -3;
	ioctl(STDIN_FILENO, TIOCSTI, "\n");
	rl_on_new_line();
}

void	set_heredoc(int sig)
{
	(void)sig;
	g_check_heredoc = -10;
}
