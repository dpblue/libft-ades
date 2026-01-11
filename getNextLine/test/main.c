/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 22:09:32 by ade-sarr          #+#    #+#             */
/*   Updated: 2024/05/27 02:24:06 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Programme de test de GNL */

#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

const char	*g_open_error_msg = "Impossible d'ouvrir le fichier !\n";

int	printerr(const char *message, int errcode)
{
	write(2, message, strlen(message));
	return (errcode);
}

int	print_diff(const char *file1, const char *file2)
{
	int		fd1;
	int		fd2;
	char	*line1;
	char	*line2;
	bool	eof;

	fd1 = open(file1, O_RDONLY);
	if (fd1 < 0)
		return (dprintf(2, "Echec sur ouverture du fichier '%s'\n", file1) ,2);
	fd2 = open(file2, O_RDONLY);
	if (fd2 < 0)
		return (close(fd1),
			dprintf(2, "Echec sur ouverture du fichier '%s'\n", file2) ,2);
	eof = false;
	while (!eof)
	{
		line1 = get_next_line(fd1);
		line2 = get_next_line(fd2);
		eof = !(line1 && line2);
		if (line1 && !line2)
			printf("%s comporte plus de lignes que %s\n", file1, file2);
		if (!line1 && line2)
			printf("%s comporte plus de lignes que %s\n", file2, file1);
		if (!eof)
			if (strcmp(line1, line2))
				printf("différence tourvée :\n%s: %s\n%s: %s\n",
					file1, line1, file2, line2);
		free(line1);
		free(line2);
	}
	get_next_line(-1);
	close(fd1);
	close(fd2);
	return (0);
}

int	print_file(const char *filename)
{
	int			fd;
	char		*line;

	fd = 0;
	if (filename)
	{
		fd = open(filename, O_RDONLY);
		if (fd < 0)
			return (printerr(g_open_error_msg, 2));
	}
	line = get_next_line(fd);
	while (line)
	{
		write(1, line, strlen(line));
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

int	main(int argc, char **argv)
{
	static char	*help_msg = "Test de get_next_line() :\n\
	gnl <nom de fichier> : afficher un fichier texte\n\
	gnl 'stdin' : lecture depuis 'stdin' vers 'stdout'\n\
	gnl 'diff' <file1> <file2> : comparer <file1> et <file2> ligne à ligne\n";

	if (argc < 2)
		return (printerr(help_msg, 1));
	if (argc == 2)
	{
		if (strcmp(argv[1], "stdin") == 0)
			return (print_file(NULL));
		else
			return (print_file(argv[1]));
	}
	if (argc == 4 && strcmp(argv[1], "diff") == 0)
		return (print_diff(argv[2], argv[3]));
	return (printerr(help_msg, 1));
}
