/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 07:58:52 by dlorenzo          #+#    #+#             */
/*   Updated: 2024/12/11 20:40:37 by dlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>	// printf;
#include <ctype.h>	// isalpha;
#include <string.h>	// strlen; memcpy; memmove; strlcpy;

int	main(void)
{
/*
	// Play with size_t & sizeof()
	size_t	size_uint = sizeof(unsigned int);
	size_t	size_ulon = sizeof(unsigned long);
	
	printf("\nSize of size_t in Bytes in this PC:		%zu\n", sizeof(size_t));
	printf("Size of unsigned int in Bytes in this PC:	%zu\n", size_uint);
	printf("Size of unsigned long in Bytes in this PC:	%zu\n", size_ulon);
	printf("This PC has a %zu-bit Architecture\n", sizeof(size_t) * 8);


	// Test ft_isalpha()
	char	c = 'Z';

	printf("\nSample char: %c\n", c);
	printf("\nft_isalpha:	%d\n", ft_isalpha(c));
	printf("isalpha:	%d\n", !!isalpha(c)); // !! force 1 if isalpha <> 0
	// Test ft_isdigit()
	printf("\nft_isdigit:	%d\n", ft_isdigit(c));
	printf("isdigit:	%d\n", !!isdigit(c)); // !! force 1 if isdigit <> 0
	// Test ft_isalnum()
	printf("\nft_isalnum:	%d\n", ft_isalnum(c));
	printf("isalnum:	%d\n", !!isalnum(c)); // !! force 1 if isalnum <> 0
	// Test ft_isascii()
	printf("\nft_isascii:	%d\n", ft_isascii(c));
	printf("isascii:	%d\n", isascii(c));
	// Test ft_isprint()d
	printf("\nft_isprint:	%d\n", ft_isprint(c));
	printf("isprint:	%d\n", !!isprint(c)); // why sometimes isprint <> 0 ?


	// Test ft_strlen()
	char	str[] = "Hello, 42Malaga Cursus! Just Enjoy & Learn";
	
	printf("\nSample string: '%s'\n", str);
	printf("ft_strlen: 	%zu\n", ft_strlen(str));
	printf("strlen:		%zu\n", strlen(str));


	// Test ft_memset()
	char	str1[] = "Hello!";
	char	str2[] = "Hello!";
	
	printf("\nstr1 before ft_memset: '%s'\n", str1);
	printf("str1 size before: %zu INCLUIDO \\0\n", sizeof(str1));
	printf("str1 ft_strlen before: %zu\n", ft_strlen(str1));
	ft_memset(str1, 'x', ft_strlen(str1));
	printf("str1 after ft_memset: '%s'\n", str1);
	printf("str1 size after: %zu INCLUIDO \\0\n", sizeof(str1));
	printf("str1 ft_strlen after: %zu\n", ft_strlen(str1));

	printf("\nstr2 before memset: '%s'\n", str2);
	printf("str2 size before: %zu INCLUIDO \\0\n", sizeof(str2));
	printf("str2 strlen before: %zu\n", strlen(str2));
	memset(str2, 'x', strlen(str2)); // unexpected printf if strlen(str2)+1
	printf("str2 after memset: '%s'\n", str2);
	printf("str2 size after: %zu INCLUIDO \\0\n", sizeof(str2));
	printf("str2 strlen after: %zu\n", strlen(str2));


	// Test ft_bzero()
	char	str1[] = "Hello!";
	char	str2[] = "Hello!";
	
	printf("\nstr1 before ft_bzero '%s'\n", str1);
	printf("str1 size before: %zu INCLUIDO \\0\n", sizeof(str1));
	printf("str1 ft_strlen before: %zu\n", ft_strlen(str1));
	ft_bzero(str1, ft_strlen(str1));
	printf("str1 after ft_bzero '%s'\n", str1);
	printf("str1 size after: %zu INCLUIDO \\0\n", sizeof(str1));
	printf("str1 ft_strlen after: %zu\n", ft_strlen(str1));

	printf("\nstr2 before bzero '%s'\n", str2);
	printf("str2 size before: %zu INCLUIDO \\0\n", sizeof(str2));
	printf("str2 strlen before: %zu\n", strlen(str2));
	bzero(str2, strlen(str2)); // unexpected printf if strlen(str2)+1
	printf("str2 after bzero '%s'\n", str2);
	printf("str2 size after: %zu INCLUIDO \\0\n", sizeof(str2));
	printf("str2 strlen after: %zu\n", strlen(str2));


	// Test ft_memcpy()
//	char	str1[] = "Hello, 42Malaga Cursus! Just Enjoy & Learn";
//	char	des1[50];
	char	*str1 = 0;
	char	*des1 = 0;

	printf("str1 before ft_memcpy '%s'\n", str1);
	printf("des1 before ft_memcpy '%s'\n", des1);
	ft_memcpy(des1, str1, 5);
	printf("str1 after ft_memcpy '%s'\n", str1);
	printf("des1 after ft_memcpy '%s'\n\n", des1);

//	char	str2[] = "Hello, 42Malaga Cursus! Just Enjoy & Learn";
//	char	des2[50];
	char	*str2 = 0;
	char	*des2 = 0;

	printf("str2 before memcpy '%s'\n", str2);
	printf("des2 before memcpy '%s'\n", des2);
	memcpy(des2, str2, 5);
	printf("str2 after memcpy '%s'\n", str2);
	printf("des2 after memcpy '%s'\n", des2);


	// Test ft_memmove()
	//char str1[20] = "     ABCDEFGHIJ     ";
	char *str1 = "thanks to @apellicc for this test !\r\n";
	//char des1[0xF0];

	printf("str1 before ft_memmove '%s'\n", str1);
//	ft_memmove(&str1[6], &str1[5], 10);
//	ft_memmove(des1, &str1[5], ft_strlen(str1));
	ft_memmove("", "" - 1, 0);
	printf("str1  after ft_memmove '%s'\n\n", str1);

	//char str2[20] = "     ABCDEFGHIJ     ";
	char *str2 = "thanks to @apellicc for this test !\r\n";
	//char des2[0xF0];

	printf("str2 before memmove '%s'\n", str2);
//	memmove(&str2[6], &str2[5], 10);
//	memmove(des2, &str2[5], strlen(str2));
	memmove("", "" - 1, 0);
	printf("str2  after memmove '%s'\n", str2);


	// Test ft_strlcpy()
	char src[] = "Hello, world!";
	char dst[10]; // Buffer smaller than src
	printf("Source: '%s'\n", src);
	printf("Destination: '%s'\n", dst);

	size_t result = ft_strlcpy(dst, src, sizeof(dst) - 4);

	printf("Source: '%s'\n", src);
	printf("Destination: '%s'\n", dst);
	printf("Length of src: '%zu'\n", result);

	if (result >= sizeof(dst)) {
		printf("Warning: Truncation occurred. Needed %zu bytes.\n", result);
	}


	// Test ft_strlcat()
	char dst[] = "";
	char src[] = "the cake is a lie !\0I'm hidden lol\r\n";
	printf("Source: '%s'\n", src);
	printf("Destination: '%s'\n", dst);
	printf("size of dst  : '%zu'\n", ft_strlen(dst));
	printf("size of src  : '%zu'\n", ft_strlen(src));

	size_t result = ft_strlcat(dst, src, ft_strlen(src));

	printf("Source: '%s'\n", src);
	printf("Destination: '%s'\n", dst);
	printf("Length of src: '%zu'\n", result);
*/
	// Test ft_toupper() && ft_tolower()
	char min = 'l';
	char may = 'L';
	char nac1 = '0';
	char nac2 = '*';

	printf("min: '%c' - ft_toupper: '%c'\n", min, ft_toupper(min));
	printf("may: '%c' - ft_tolower: '%c'\n", may, ft_tolower(may));
	printf("nac1: '%c' - ft_toupper: '%c'\n", nac1, ft_toupper(nac1));
	printf("nac2: '%c' - ft_tolower: '%c'\n", nac2, ft_tolower(nac2));

	// END of tests
	return (0);
}
