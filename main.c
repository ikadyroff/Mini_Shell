/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlouveni <wlouveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:34:12 by wlouveni          #+#    #+#             */
/*   Updated: 2022/07/07 16:36:46 by wlouveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	*cmd1;
	char	*cmd2;
	int		fd1;
	int		fd2;
	t_node	cmd_list1;
	t_node	cmd_list2;
	
	cmd_list1.fd_in = -1;
	cmd_list1.fd_out = open("file_1", O_RDONLY);
	cmd_list1.args[1] = "ls";
	cmd_list1.args[2] = "-l";
	cmd_list2.fd_in = open("file_2", O_RDWR | O_CREAT, 0644);
	cmd_list2.fd_out = 1;
	cmd_list2.args[1] = "wc";
	cmd_list2.args[2] = "-l";
	return(0);
}
