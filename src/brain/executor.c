/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehoundey <ehoundey@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:57:16 by ehoundey          #+#    #+#             */
/*   Updated: 2022/06/20 18:32:53 by ehoundey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "brain.h"
#include "env_var_utils.h"
#include "executor_utils.h"

static char	*get_abs_cmd_path(char *path_splitted, char *cmd)
{
	char	*abs_cmd_path;

	abs_cmd_path = ft_strjoin(path_splitted, "/");
	if (abs_cmd_path == NULL)
		return (NULL);
	abs_cmd_path = ft_append(&abs_cmd_path, cmd);
	if (abs_cmd_path == NULL)
		return (NULL);
	return (abs_cmd_path);
}

static int	init(char **path_splitted[])
{
	char	*path;

	path = get_env_var_value(get_envv(), "PATH");
	if (path == NULL)
		return (EXIT_FAILURE);
	*path_splitted = ft_split(path, ':');
	free(path);
	if (*path_splitted == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/**
 * Возвращает абсолютный путь команды cmd или NULL, если не найден или ошибка
 * *cmd:
 */
static char	*get_abs_cmd(char *cmd)
{
	char	**path_splitted;
	char	*absolute_cmd_path;
	int		i;

	if (access(cmd, F_OK) == 0)
		return (ft_strdup(cmd));
	if (init(&path_splitted) == EXIT_FAILURE)
		return (NULL);
	i = 0;
	while (path_splitted[i])
	{
		absolute_cmd_path = get_abs_cmd_path(path_splitted[i], cmd);
		if (absolute_cmd_path == NULL)
			return (NULL);
		if (access(absolute_cmd_path, F_OK) == 0)
		{
			ft_free_split(path_splitted);
			return (absolute_cmd_path);
		}
		ft_free((void *)&absolute_cmd_path);
		i++;
	}
	ft_free_split(path_splitted);
	return (NULL);
}

/**
 * Выполняет команду в дочернем процессе
 * Ожидает завершения дочернего процесса
 * *exp_tok:
 * *abs_cmd_path:
 * статус завершения дочернего процесса
 */
static int	execute_cmd(t_exp_tok *exp_tok, char *abs_cmd_path)
{
	pid_t	pid;
	int		status;

	status = 0;
	handle_cmd_signals();
	pid = fork();
	if (pid < 0)
		return (EXIT_FAILURE);
	if (pid == 0)
		return (execute_child(exp_tok, abs_cmd_path, status));
	waitpid(pid, &status, 0);
	handle_global_signals();
	return (WEXITSTATUS(status));
}

int	executor(t_exp_tok *exp_tok)
{
	int		exit_status;
	char	*abs_cmd_path;

	if (exp_tok->cmd == NULL)
		return (EXIT_SUCCESS);
	if (clean_exp_tok_cmds(exp_tok) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (is_inbuilt(exp_tok->cmd[0]))
		return (handle_inbuilt_redir(exp_tok));
	abs_cmd_path = get_abs_cmd(exp_tok->cmd[0]);
	if (abs_cmd_path == NULL || ft_strlen(exp_tok->cmd[0]) == 0)
	{
		free(abs_cmd_path);
		ft_fprintf(STDERR_FILENO, "%s: command not found\n", exp_tok->cmd[0]);
		return (EXIT_CMD_NOT_FOUND);
	}
	exit_status = execute_cmd(exp_tok, abs_cmd_path);
	free(abs_cmd_path);
	return (exit_status);
}
