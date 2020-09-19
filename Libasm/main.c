/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschirad <jschirad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:43:58 by jschirad          #+#    #+#             */
/*   Updated: 2020/02/25 17:57:48 by jschirad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

# define STRLEN(x)			printf("`%s` = %d (%d)\n", x, ft_strlen(x), (int)strlen(x));
# define STRCMP(a, b)		printf("`%s`:`%s` = %d (%d)\n", a, b, ft_strcmp(a, b), strcmp(a, b));
# define WRITE(s, x)		printf("^%ld (`%s`:%ld)\n", ft_write(STDOUT_FILENO, s, x), s, x);
# define READ(b, x)			r = ft_read(STDIN_FILENO, buffer, x); printf("`%s`:%ld\n", buffer, r);
# define DUP(s)				tmp = ft_strdup(s); printf("`%s` (`%s`)\n", tmp, s); free(tmp); tmp = NULL;

int		ft_strlen(char const *str);

int		ft_strcmp(char const *s1, char const *s2);

char	*ft_strcpy(char *dst, char const *src);

ssize_t	ft_write(int fd, void const *buf, size_t nbyte);

ssize_t	ft_read(int fd, void *buf, size_t nbyte);

char	*ft_strdup(char const *s1);

int		main(void)
{
	int		i;
	long	r;
	char	buffer[100];
	char	*tmp;
	char	*tmp2;

	r = 0;
	i = 0;
	(void)tmp;
	(void)tmp2;
	while (i < 100)
		buffer[i++] = 0;

	printf("--strlen\n");
	STRLEN("")
	STRLEN("toto")
	STRLEN("totototo")
	STRLEN("0123456789abcdef")
	STRLEN("42")
	STRLEN("1")
	printf("--------[OK]---------\n");

	printf("\n--strcmp\n");
	STRCMP("", "")
	STRCMP("toto", "toto")
	STRCMP("", "toto")
	STRCMP("toto", "")
	STRCMP("toto", "totobar")
	printf("`%s`:`%s` = %d\n", "ba", "ac", ft_strcmp("ab", "cd"));
	printf("`%s`:`%s` = %d <- original\n", "ba", "ac", strcmp("ab", "cd"));
	printf("`%s`:`%s` = %d\n", "TOTO", NULL, ft_strcmp("TOTO", NULL));
	printf("`%s`:`%s` = %d <- original\n", "TOTO", NULL, strcmp("TOTO", ""));
	printf("`%s`:`%s` = %d\n", NULL, "TOTO", ft_strcmp(NULL, "TOTO"));
	printf("`%s`:`%s` = %d <- original\n", NULL, "TOTO", strcmp("", "TOTO"));
	printf("`%s`:`%s` = %d\n", NULL, NULL, ft_strcmp(NULL, NULL));
	printf("`%s`:`%s` = %d <- original\n", NULL, NULL, strcmp("", ""));
	printf("--------[OK]---------\n");

	printf("\n--strcpy\n");
	printf("`%s` (`toto`)\n", ft_strcpy(buffer, "toto"));
	printf("`%s` (empty)\n", ft_strcpy(buffer, ""));
	printf("`%s` (`long message`)\n", ft_strcpy(buffer, "long message"));
		char	s1[] = "Hello world";
	char	s2[20];

	s2[0] = '\0';
	printf("[+] Strcpy [+]\n");
	printf("S1: %s\n", s1);
	printf("S2: %s\n", s2);
	printf("strcpy(s2, s1) return: %s\n", ft_strcpy(s2, s1));
	printf("s2: %s\n", s2);
	printf("[+] END OF STRCPY [+]\n");
	printf("\n");
	printf("--------[OK]---------\n");

	printf("\n--write\n");
	WRITE("toto", 4L)
	WRITE("totototo", 4L)
	WRITE("totototo", 8L)
	WRITE("toto", 2L)
	printf("--------[OK]---------\n");

	printf("\n--read (Makefile)\n");
	READ(buffer, 50)
	READ(buffer, 25)
	READ(buffer, 4)
	READ(buffer, 26)
	READ(buffer, 14)
	READ(buffer, 0)
	printf("--------[OK]---------\n");

	printf("\n--ft_strdup\n");
	tmp2 = ft_strdup("toto");
	DUP(tmp2)
	free(tmp2);
	DUP("totobar")
	DUP("long message")
	DUP("")
	DUP(NULL)
	printf("--------[OK]---------\n");

	return (0);
}
