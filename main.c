/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 18:05:19 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/06/24 14:36:51 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>
#include "libasm.h"

/*
**	Colors
*/

#define RESET "\x1b[0m"
#define BRIGHT "\x1b[1m"
#define DIM "\x1b[2m"
#define UNDERSCORE "\x1b[4m"
#define BLINK "\x1b[5m"
#define REVERSE "\x1b[7m"
#define HIDDEN "\x1b[8m"

#define BLACK "\x1b[30m"
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define WHITE "\x1b[37m"

#define BOLD_BLACK "\x1b[40m"
#define BOLD_RED "\x1b[41m"
#define BOLD_GREEN "\x1b[42m"
#define BOLD_YELLOW "\x1b[43m"
#define BOLD_BLUE "\x1b[44m"
#define BOLD_MAGENTA "\x1b[45m"
#define BOLD_CYAN "\x1b[46m"
#define BOLD_WHITE "\x1b[47m"

#define MAX_TEST_RANDOM 500
#define DELAY_RANDOM_TEST 7000
#define MAX_LENGH_RANDOM 100

void 		exit_error()
{
	printf(BRIGHT RED "\tError\n");
	exit (EXIT_SUCCESS);
}

void 		print_int_test(int r1, int r2, char *f1, char *f2)
{
	if (r1 != r2)
	{
		printf(BRIGHT YELLOW "\t\t %s :" BRIGHT GREEN" %d\n", f1, r1);
		printf(BRIGHT YELLOW "\t\t %s :" BRIGHT RED" %d\n", f2, r2);
		exit_error();
	}
	else
	{
		printf(BRIGHT YELLOW "\t\t %s :" BRIGHT GREEN" %d\n", f1, r1);
		printf(BRIGHT YELLOW "\t\t %s :" BRIGHT GREEN" %d\n\n", f2, r2);
		return;
	}
}

void 		print_string_test(char *r1, char *r2, char *f1, char *f2)
{
	if (!r1 || !r2)
	{
		printf(BRIGHT YELLOW "\t\t %s :" BRIGHT GREEN" %s\n", f1, r1);
		printf(BRIGHT YELLOW "\t\t %s :" BRIGHT GREEN" %s\n\n", f2, r2);
		return;
	}
	else if (strcmp(r1, r2))
	{
		printf(BRIGHT YELLOW "\t\t %s :" BRIGHT GREEN" %s\n", f1, r1);
		printf(BRIGHT YELLOW "\t\t %s :" BRIGHT RED" %s\n", f2, r2);
		exit_error();
	}
	else
	{
		printf(BRIGHT YELLOW "\t\t %s :" BRIGHT GREEN" %s\n", f1, r1);
		printf(BRIGHT YELLOW "\t\t %s :" BRIGHT GREEN" %s\n\n", f2, r2);
		return;
	}
}

int			generate_random_int(int min, int max)
{
	return((rand() % (max + 1 - min)) + min);
}

char 		*generate_random_string(int forcemax)
{
	char *str;
	int len;
	int i;

	len = generate_random_int(1, forcemax ? forcemax : MAX_LENGH_RANDOM);
	str = malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < len)
	{
		str[i] = generate_random_int(32, 126);
		++i;
	}
	str[i] = '\0';
	return (str);
}

void		test_ft_strdup()
{
	int		r1;
	int		r2;
	int		ntest;
	char	*test;
	char	*test02;

	printf(BRIGHT GREEN "\t - ft_strdup :\n\n"RESET);
	printf(BRIGHT BLUE "\t[1] : "BRIGHT CYAN"''\n");
	print_string_test(strdup(""), ft_strdup(""), "<string.h>", "<libasm.h>");

	printf(BRIGHT BLUE "\t[1] : "BRIGHT CYAN"'     '\n");
	print_string_test(strdup("     "), ft_strdup("     "), "<string.h>", "<libasm.h>");

	printf(BRIGHT BLUE "\t[1] : "BRIGHT CYAN"'42born2code'\n");
	print_string_test(strdup("42born2code"), ft_strdup("42born2code"), "<string.h>", "<libasm.h>");

	printf(BRIGHT BLUE "\t[1] : "BRIGHT CYAN"'0123456789'\n");
	print_string_test(strdup("0123456789"), ft_strdup("0123456789"), "<string.h>", "<libasm.h>");

	printf(BRIGHT BLUE "\t[1] : "BRIGHT CYAN"'NULL'\n");
	print_string_test("SEGMENTATION FAULT", ft_strdup(NULL), "<string.h>", "<libasm.h>");


	getchar();
	ntest = 0;
	while (ntest < MAX_TEST_RANDOM)
	{
		test = generate_random_string(16);
		printf(BRIGHT BLUE "\t[%d] : "BRIGHT CYAN"'%s'\n", ntest + 1, test);
		print_string_test(strdup(test), ft_strdup(test), "<string.h>", "<libasm.h>");
		usleep(DELAY_RANDOM_TEST);
		free(test);
		++ntest;
	}

}

void		test_ft_read()
{
	int			fd;
	char		buffer[100];
	char		show[100];
	ssize_t		ret;
	ssize_t		ft_ret;


	printf(BRIGHT GREEN "\t - ft_read :\n\n"RESET);
	printf(BRIGHT BLUE "\t[1] : "BRIGHT CYAN"'read >main.c< >10<'\n");
	fd = open("main.c", O_RDONLY);
	print_int_test(read(fd, buffer, 10), ft_read(fd, buffer, 10), "<unistd.h>", "<libasm.h>");
	print_string_test(strncpy(show, buffer, 10), strncpy(show, buffer, 10), "<unistd.h>", "<libasm.h>");
	close(fd);

	printf(BRIGHT BLUE "\t[2] : "BRIGHT CYAN"'read >Makefile< >80<'\n");
	fd = open("Makefile", O_RDONLY);
	print_int_test(read(fd, buffer, 80), ft_read(fd, buffer, 80), "<unistd.h>", "<libasm.h>");
	print_string_test(strncpy(show, buffer, 80), strncpy(show, buffer, 80), "<unistd.h>", "<libasm.h>");
	close(fd);

	printf(BRIGHT BLUE "\t[3] : "BRIGHT CYAN"'read >missingfile< >10<'\n");
	fd = open("missingfile", O_RDONLY);
	ret = read(fd, buffer, 10);
	print_int_test(ret, ret, "<unistd.h>", "<libasm.h>");
	close(fd);

	printf(BRIGHT BLUE "\t[4] : "BRIGHT CYAN"'read >NULL< >10<'\n");
	fd = open("main.c", O_RDONLY);
	ret = read(fd, NULL, 10);
	printf(BRIGHT YELLOW"\t\t<unistd.h>"BRIGHT GREEN " %zd\n", ret);
	close(fd);
	fd = open("main.c", O_RDONLY);
	ret = read(fd, NULL, 10);
	printf(BRIGHT YELLOW"\t\t<libasm.h>"BRIGHT GREEN " %zd\n", ret);
	close(fd);

	printf(BRIGHT BLUE "\t[5] : "BRIGHT CYAN"'read >42< >10<'\n");
	ret = read(42, buffer, 10);
	printf(BRIGHT YELLOW"\t\t<unistd.h>"BRIGHT GREEN " %zd %s\n", ret, strncpy(show, buffer, 10));
	ret = read(42, buffer, 10);
	printf(BRIGHT YELLOW"\t\t<libasm.h>"BRIGHT GREEN " %zd %s\n", ret, strncpy(show, buffer, 10));
	close(fd);
	fd = open("empty_file", O_RDONLY | O_TRUNC | O_CREAT, 0777);

	printf(BRIGHT BLUE "\t[6] : "BRIGHT CYAN"open(\"empty_file\", O_RDONLY | O_TRUNC | O_CREAT, 0777)' '' '10'\n");
	ret = read(fd, buffer, 10);
	printf(BRIGHT YELLOW"\t\t<unistd.h>"BRIGHT GREEN " %zd %s\n", ret, strncpy(show, buffer, 10));
	ret = read(fd, buffer, 10);
	printf(BRIGHT YELLOW"\t\t<libasm.h>"BRIGHT GREEN " %zd %s\n", ret, strncpy(show, buffer, 10));
	close(fd);
	remove("empty_file");
}

void		test_ft_write()
{
	int			fd;
	char		buffer[100];
	int r1;
	int r2;


	printf(BRIGHT GREEN "\t - ft_write :\n\n"RESET);
	printf(BRIGHT BLUE "\t[1] : "BRIGHT CYAN"'write(1, '', 0)'\n");
	r1 = write(1, "", 0);
	r2 = ft_write(1, "", 0);
	print_int_test(r1, r2, "<unistd.h>","libasm.h");


	printf(BRIGHT GREEN "\t - ft_write :\n\n"RESET);
	printf(BRIGHT BLUE "\t[2] : "BRIGHT CYAN"'write(1, 'toto', 4)'\n");
	r1 = write(1, "toto", 4);
	r2 = ft_write(1, "toto", 4);
	print_int_test(r1, r2, "<unistd.h>","libasm.h");

	printf(BRIGHT GREEN "\t - ft_write :\n\n"RESET);
	printf(BRIGHT BLUE "\t[3] : "BRIGHT CYAN"'write(1, 'toto', 2)'\n");
	r1 = write(1, "toto", 2);
	r2 = ft_write(1, "toto", 2);
	print_int_test(r1, r2, "<unistd.h>","libasm.h");

	printf(BRIGHT GREEN "\t - ft_write :\n\n"RESET);
	printf(BRIGHT BLUE "\t[4] : "BRIGHT CYAN"'write(1, 'toto', 40)'\n");
	r1 = write(1, "toto", 40);
	r2 = ft_write(1, "toto", 40);
	print_int_test(r1, r2, "<unistd.h>","libasm.h");

	printf(BRIGHT GREEN "\t - ft_write :\n\n"RESET);
	printf(BRIGHT BLUE "\t[5] : "BRIGHT CYAN"'write(1, 42 born 2 code, 6)'\n");
	r1 = write(1, "42 born 2 code", 6);
	r2 = ft_write(1, "42 born 2 code", 6);
	print_int_test(r1, r2, "<unistd.h>","libasm.h");

	printf(BRIGHT GREEN "\t - ft_write :\n\n"RESET);
	printf(BRIGHT BLUE "\t[6] : "BRIGHT CYAN"'write(0, 'toto', 4)'\n");
	r1 = write(0, "toto", 4);
	r2 = ft_write(0, "toto", 4);
	print_int_test(r1, r2, "<unistd.h>","libasm.h");

	printf(BRIGHT GREEN "\t - ft_write :\n\n"RESET);
	printf(BRIGHT BLUE "\t[7] : "BRIGHT CYAN"'write(1, 'toto', 4)'\n");
	r1 = write(1, "toto", 4);
	r2 = ft_write(1, "toto", 4);
	print_int_test(r1, r2, "<unistd.h>","libasm.h");


	printf(BRIGHT GREEN "\t - ft_write :\n\n"RESET);
	printf(BRIGHT BLUE "\t[7] : "BRIGHT CYAN"'open(\"ft_write_test\", O_WRONLY | O_TRUNC | O_CREAT)' '<whichlib.h> toto' '15' (write in a file)'\n");
	fd = open("ft_write_test", O_WRONLY | O_TRUNC | O_CREAT, 0777);
	write(fd, "<unistd.h> toto", 15);
	ft_write(fd, "<libasm.h> toto", 15);
	close(fd);
	fd = open("ft_write_test", O_RDONLY);
	read(fd, buffer, 15);
	printf(BRIGHT YELLOW"\t\t<unistd.h>"BRIGHT GREEN"\t%s\n", buffer);
	read(fd, buffer, 15);
	printf(BRIGHT YELLOW"\t\t<libasm.h>"BRIGHT GREEN"\t%s\n", buffer);
	close(fd);
	remove("ft_write_test");
}

void		test_ft_strcmp()
{
	int		r1;
	int		r2;
	int		ntest;
	char	*test;
	char	*test02;

	printf(BRIGHT GREEN "\t - ft_strcmp :\n\n"RESET);
	printf(BRIGHT BLUE "\t[1] : "BRIGHT CYAN"''\n");
	print_int_test(strcmp("", ""), ft_strcmp("", ""), "<string.h>", "<libasm.h>");

	printf(BRIGHT BLUE "\t[2] : "BRIGHT CYAN"'      '\n");
	print_int_test(strcmp("      ", "      "), ft_strcmp("      ", "      "), "<string.h>", "<libasm.h>");

	printf(BRIGHT BLUE "\t[3] : "BRIGHT CYAN"'42born2code'\n");
	print_int_test(strcmp("42born2code", "42born2code"), ft_strcmp("42born2code", "42born2code"), "<string.h>", "<libasm.h>");

	printf(BRIGHT BLUE "\t[4] : "BRIGHT CYAN"'42born2code | 42born'\n");
	print_int_test(strcmp("42born2code", "42born"), ft_strcmp("42born2code", "42born"), "<string.h>", "<libasm.h>");

	printf(BRIGHT BLUE "\t[5] : "BRIGHT CYAN"'42 | 2code'\n");
	print_int_test(strcmp("42", "2code"), ft_strcmp("42", "2code"), "<string.h>", "<libasm.h>");

	printf(BRIGHT BLUE "\t[6] : "BRIGHT CYAN"'bbonjour | bbbonjour'\n");
	print_int_test(strcmp("bbonjour", "bbbonjour"), ft_strcmp("bbonjour", "bbbonjour"), "<string.h>", "<libasm.h>");

	printf(BRIGHT BLUE "\t[7] : "BRIGHT CYAN"'1234567 | 1234567'\n");
	print_int_test(strcmp("1234567", "1234567"), ft_strcmp("1234567", "1234567"), "<string.h>", "<libasm.h>");

	printf(BRIGHT BLUE "\t[8] : "BRIGHT CYAN"'1234 | 56789'\n");
	print_int_test(strcmp("1234", "56789"), ft_strcmp("1234", "56789"), "<string.h>", "<libasm.h>");

	printf(BRIGHT BLUE "\t[9] : "BRIGHT CYAN"'424242 | '\n");
	print_int_test(strcmp("424242", ""), ft_strcmp("424242", ""), "<string.h>", "<libasm.h>");

	printf(BRIGHT BLUE "\t[10] : "BRIGHT CYAN"' | 424242'\n");
	print_int_test(strcmp("", "424242"), ft_strcmp("", "424242"), "<string.h>", "<libasm.h>");

	printf(BRIGHT BLUE "\t[11] : "BRIGHT CYAN"' NULL| NULL'\n");
	printf(BRIGHT YELLOW "\t\t %s :" BRIGHT GREEN" %s\n", "<string.h>", "SEGMENTATION FAULT");
	printf(BRIGHT YELLOW "\t\t %s :" BRIGHT GREEN" %d\n\n", "<libasm.h>", ft_strcmp(NULL, NULL));

	printf(BRIGHT BLUE "\t[12] : "BRIGHT CYAN"' NULL| 42'\n");
	printf(BRIGHT YELLOW "\t\t %s :" BRIGHT GREEN" %s\n", "<string.h>", "SEGMENTATION FAULT");
	printf(BRIGHT YELLOW "\t\t %s :" BRIGHT GREEN" %d\n\n", "<libasm.h>", ft_strcmp(NULL, "42"));

	printf(BRIGHT BLUE "\t[13] : "BRIGHT CYAN"' 42| NULL'\n");
	printf(BRIGHT YELLOW "\t\t %s :" BRIGHT GREEN" %s\n", "<string.h>", "SEGMENTATION FAULT");
	printf(BRIGHT YELLOW "\t\t %s :" BRIGHT GREEN" %d\n\n", "<libasm.h>", ft_strcmp("42", NULL));

	printf(BRIGHT BLUE "\t[14] : "BRIGHT CYAN"' | NULL'\n");
	printf(BRIGHT YELLOW "\t\t %s :" BRIGHT GREEN" %s\n", "<string.h>", "SEGMENTATION FAULT");
	printf(BRIGHT YELLOW "\t\t %s :" BRIGHT GREEN" %d\n\n", "<libasm.h>", ft_strcmp("", NULL));

	printf(BRIGHT BLUE "\t[15] : "BRIGHT CYAN"'\xff\xff | \xff\xff\xfe'\n");
	print_int_test(strcmp("\xff\xff", "\xff"), ft_strcmp("\xff\xff", "\xff"), "<string.h>", "<libasm.h>");

	printf(BRIGHT BLUE "\t[16] : "BRIGHT CYAN"'\xff\xff | \xff\xff\xfe'\n");
	print_int_test(strcmp("\xff\xff", "\xff\xff\xfe"), ft_strcmp("\xff\xff", "\xff\xff\xfe"), "<string.h>", "<libasm.h>");

	printf(BRIGHT BLUE "\t[17] : "BRIGHT CYAN"'\xfe | \xff'\n");
	print_int_test(strcmp("\xfe", "\xff"), ft_strcmp("\xfe", "\xff"), "<string.h>", "<libasm.h>");

	printf(BRIGHT BLUE "\t[18] : "BRIGHT CYAN"'\xfe | \xfe'\n");
	print_int_test(strcmp("\xfe", "\xfe"), ft_strcmp("\xfe", "\xfe"), "<string.h>", "<libasm.h>");

}

void		test_ft_strcpy()
{
	char	dst[200];
	int		r1;
	int		r2;
	int		ntest;
	char	*test;

	printf(BRIGHT GREEN "\t - ft_strcpy :\n\n"RESET);
	printf(BRIGHT BLUE "\t[1] : "BRIGHT CYAN"''\n");
	print_string_test(strcpy(dst, ""), ft_strcpy(dst, ""), "<string.h>", "<libasm.h>");

	printf(BRIGHT BLUE "\t[2] : "BRIGHT CYAN"'42born2code'\n");
	print_string_test(strcpy(dst, "42born2code"), ft_strcpy(dst, "42born2code"), "<string.h>", "<libasm.h>");

	printf(BRIGHT BLUE "\t[3] : "BRIGHT CYAN"'0123456789'\n");
	print_string_test(strcpy(dst, "0123456789"), ft_strcpy(dst, "0123456789"), "<string.h>", "<libasm.h>");

	printf(BRIGHT BLUE "\t[4] : "BRIGHT CYAN"'NULL'\n");
	print_string_test("SEGMENTATION FAULT", ft_strcpy(dst, NULL), "<string.h>", "<libasm.h>");


	getchar();
	ntest = 0;
	while (ntest < MAX_TEST_RANDOM)
	{
		test = generate_random_string(0);
		printf(BRIGHT BLUE "\t[%d] : "BRIGHT CYAN"'%s'\n", ntest + 1, test);
		print_string_test(strcpy(dst, test), ft_strcpy(dst, test), "<string.h>", "<libasm.h>");
		usleep(DELAY_RANDOM_TEST);
		free(test);
		++ntest;
	}

}

void		test_ft_strlen()
{
	int r1;
	int r2;
	int ntest;
	char *test;


	printf(BRIGHT GREEN "\t - ft_strlen :\n\n"RESET);
	printf(BRIGHT BLUE "\t[1] : "BRIGHT CYAN"''\n");
	print_int_test(strlen(""), ft_strlen(""), "<string.h>", "<libasm.h>");
	printf(BRIGHT BLUE "\t[2] : "BRIGHT CYAN"'     '\n");
	print_int_test(strlen("     "), ft_strlen("     "), "<string.h>", "<libasm.h>");
	printf(BRIGHT BLUE "\t[3] : "BRIGHT CYAN"'42born2code'\n");
	print_int_test(strlen("42born2code"), ft_strlen("42born2code"), "<string.h>", "<libasm.h>");
	printf(BRIGHT BLUE "\t[4] : "BRIGHT CYAN"'   42   born   2   code'\n");
	print_int_test(strlen("   42   born   2   code"), ft_strlen("   42   born   2   code"), "<string.h>", "<libasm.h>");
	printf(BRIGHT BLUE "\t[5] : "BRIGHT CYAN"'0123456789'\n");
	print_int_test(strlen("0123456789"), ft_strlen("0123456789"), "<string.h>", "<libasm.h>");
	printf(BRIGHT BLUE "\t[6] : "BRIGHT CYAN"'NULL'\n");
	print_int_test(0, ft_strlen(NULL), "<string.h>", "<libasm.h>");
	getchar();
	ntest = 0;
	while (ntest < MAX_TEST_RANDOM)
	{
		test = generate_random_string(0);
		printf(BRIGHT BLUE "\t[%d] : "BRIGHT CYAN"'%s'\n", ntest + 1, test);
		print_int_test(strlen(test), ft_strlen(test), "<string.h>", "<libasm.h>");
		usleep(DELAY_RANDOM_TEST);
		free(test);
		++ntest;
	}
}

int		main(int argc, char **argv)
{
	srand(time(NULL));
	test_ft_strlen();
	getchar();
	test_ft_strcpy();
	getchar();
	test_ft_strcmp();
	getchar();
	test_ft_strdup();
	getchar();
	test_ft_read();
	getchar();
	test_ft_write();
	getchar();
	return 0;
}
