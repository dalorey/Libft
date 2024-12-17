/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 07:58:52 by dlorenzo          #+#    #+#             */
/*   Updated: 2024/12/17 14:52:20 by dlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>	// printf;
#include <ctype.h>	// isalpha;
#include <string.h>	// strlen; memcpy; memmove; strlcpy;
#include <assert.h> // assert;
#include <stdlib.h> // atoi;
#include <stdint.h> // SIZE_MAX;

void	test_ft_memchr(const void *src, int c, size_t n)
{
	printf("----------------------------------------------------\n");
	printf("Test: Buscando el byte '%c' (ASCII: %d) en %zu bytes.\n", c, c, n);

	// Llamada a la función estándar memchr
	const void	*result_std = memchr(src, c, n);
	// Llamada a tu función ft_memchr
	const void	*result_ft = ft_memchr(src, c, n);

	if (result_ft == result_std)
		printf("✅ Test PASSED. Coinciden los resultados.\n");
	else
	{
		printf("❌ Test FAILED.\n");
		printf("Resultado memchr   : %p\n", result_std);
		printf("Resultado ft_memchr: %p\n", result_ft);
	}
	// Mostrar el contenido de la memoria si el resultado no es NULL
	if (result_ft != NULL)
		printf("Contenido desde ft_memchr: '%s'\n", (char *)result_ft);
	else
		printf("ft_memchr devolvió NULL\n");
}

void test_ft_memcmp(const void *s1, const void *s2, size_t n)
{
    printf("----------------------------------------------------\n");
    printf("Test: Comparando %zu bytes de memoria.\n", n);

    // Llamada a la función estándar memcmp
    int	result_std = memcmp(s1, s2, n);
    // Llamada a tu función ft_memcmp
    int result_ft = ft_memcmp(s1, s2, n);

    printf("memcmp estándar devuelve: %d\n", result_std);
    printf("ft_memcmp devuelve       : %d\n", result_ft);

    if ((result_std == 0 && result_ft == 0) || (result_std > 0 && result_ft > 0) || (result_std < 0 && result_ft < 0)) {
        printf("✅ Test PASSED. Los resultados coinciden.\n");
    } else {
        printf("❌ Test FAILED. Los resultados no coinciden.\n");
    }
}

void print_test_result(const char *desc, int passed)
{
    if (passed)
        printf("[OK]   %s\n", desc);
    else
        printf("[FAIL] %s\n", desc);
}

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
	//char	str1[] = "Hello, 42Malaga Cursus! Just Enjoy & Learn";
	//char	des1[50];
	char	*str1 = 0;
	char	*des1 = 0;

	printf("str1 before ft_memcpy '%s'\n", str1);
	printf("des1 before ft_memcpy '%s'\n", des1);
	ft_memcpy(des1, str1, 5);
	printf("str1 after ft_memcpy '%s'\n", str1);
	printf("des1 after ft_memcpy '%s'\n\n", des1);

	//char	str2[] = "Hello, 42Malaga Cursus! Just Enjoy & Learn";
	//char	des2[50];
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
	//ft_memmove(&str1[6], &str1[5], 10);
	//ft_memmove(des1, &str1[5], ft_strlen(str1));
	ft_memmove("", "" - 1, 0);
	printf("str1  after ft_memmove '%s'\n\n", str1);

	//char str2[20] = "     ABCDEFGHIJ     ";
	char *str2 = "thanks to @apellicc for this test !\r\n";
	//char des2[0xF0];

	printf("str2 before memmove '%s'\n", str2);
	//memmove(&str2[6], &str2[5], 10);
	//memmove(des2, &str2[5], strlen(str2));
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


// Test ft_toupper() && ft_tolower()
	char min = 'l';
	char may = 'L';
	char nac1 = '0';
	char nac2 = '*';

	printf("min: '%c' - ft_toupper: '%c'\n", min, ft_toupper(min));
	printf("may: '%c' - ft_tolower: '%c'\n", may, ft_tolower(may));
	printf("nac1: '%c' - ft_toupper: '%c'\n", nac1, ft_toupper(nac1));
	printf("nac2: '%c' - ft_tolower: '%c'\n", nac2, ft_tolower(nac2));


// Test ft_strchr()
	const char *str = "Hello, world!\0B";
    char c = 'B';

    char *result_ft = ft_strchr(str, c);
	char *result = strchr(str, c);

	printf("String: '%s' - Char: '%c'\n", str, c);
    if (result_ft != NULL) {
		printf("[FT_] El carácter '%c' se encuentra en la posición: %ld\n", c, result_ft - str);
    } else {
		printf("[FT_] El carácter '%c' no se encuentra en la cadena.\n\n", c);
    }

	printf("String: '%s' - Char: '%c'\n", str, c);
    if (result != NULL) {
        printf("El carácter '%c' se encuentra en la posición: %ld\n", c, result - str);
    } else {
        printf("El carácter '%c' no se encuentra en la cadena.\n", c);
    }


// Test ft_strrchr()
	const char *str = "Hello, world!\0B";
    char c = 'o';

    char *result_ft = ft_strrchr(str, c);
	char *result = strrchr(str, c);

	printf("String: '%s' - Char: '%c'\n", str, c);
    if (result_ft != NULL) {
		printf("[FT_] El carácter '%c' se encuentra en la posición: %ld\n", c, result_ft - str);
    } else {
		printf("[FT_] El carácter '%c' no se encuentra en la cadena.\n\n", c);
    }

	printf("String: '%s' - Char: '%c'\n", str, c);
    if (result != NULL) {
		printf("El carácter '%c' se encuentra en la posición: %ld\n", c, result - str);
    } else {
        printf("El carácter '%c' no se encuentra en la cadena.\n", c);
    }


// Test ft_strncmp()
    char *s1 = "abcdef";
    char *s2 = "abcdeg";
    char *s3 = "";
    char *s4 = "abc";
    size_t n;

    printf("======= TESTING ft_strncmp =======\n");

    // Test 0: failed test cases
    char *s5 = "\200";
    char *s6 = "\0";
	n = 1;
    printf("Test 0: Comparar \"%s\" y \"%s\" con n = %zu\n", s5, s6, n);
    printf("Resultado ft_strncmp: %d\n", ft_strncmp(s5, s6, n));
    printf("Resultado strncmp   : %d\n\n", strncmp(s5, s6, n));

    // Test 1: Comparar cadenas iguales
    n = 3;
    printf("Test 1: Comparar \"%s\" y \"%s\" con n = %zu\n", s1, s1, n);
    printf("Resultado ft_strncmp: %d\n", ft_strncmp(s1, s1, n));
    printf("Resultado strncmp   : %d\n\n", strncmp(s1, s1, n));

    // Test 2: Comparar cadenas diferentes (mismo prefijo)
    n = 6;
    printf("Test 2: Comparar \"%s\" y \"%s\" con n = %zu\n", s1, s2, n);
    printf("Resultado ft_strncmp: %d\n", ft_strncmp(s1, s2, n));
    printf("Resultado strncmp   : %d\n\n", strncmp(s1, s2, n));

    // Test 3: Comparar cadenas con longitud n más pequeña que la diferencia
    n = 3;
    printf("Test 3: Comparar \"%s\" y \"%s\" con n = %zu\n", s1, s2, n);
    printf("Resultado ft_strncmp: %d\n", ft_strncmp(s1, s2, n));
    printf("Resultado strncmp   : %d\n\n", strncmp(s1, s2, n));

    // Test 4: Comparar cadena vacía con otra cadena
    n = 3;
    printf("Test 4: Comparar \"%s\" y \"%s\" con n = %zu\n", s3, s1, n);
    printf("Resultado ft_strncmp: %d\n", ft_strncmp(s3, s1, n));
    printf("Resultado strncmp   : %d\n\n", strncmp(s3, s1, n));

    // Test 5: Comparar cadenas vacías
    n = 1;
    printf("Test 5: Comparar \"%s\" y \"%s\" con n = %zu\n", s3, s3, n);
    printf("Resultado ft_strncmp: %d\n", ft_strncmp(s3, s3, n));
    printf("Resultado strncmp   : %d\n\n", strncmp(s3, s3, n));

    // Test 6: Comparar cadenas con n = 0
    n = 0;
    printf("Test 6: Comparar \"%s\" y \"%s\" con n = %zu\n", s1, s2, n);
    printf("Resultado ft_strncmp: %d\n", ft_strncmp(s1, s2, n));
    printf("Resultado strncmp   : %d\n\n", strncmp(s1, s2, n));

    // Test 7: Comparar cadenas con una más corta
    n = 5;
    printf("Test 7: Comparar \"%s\" y \"%s\" con n = %zu\n", s4, s1, n);
    printf("Resultado ft_strncmp: %d\n", ft_strncmp(s4, s1, n));
    printf("Resultado strncmp   : %d\n\n", strncmp(s4, s1, n));

    printf("======= END ft_strncmp TESTS =======\n");


// Test ft_strncmp()
    // Test 1: Búsqueda de un carácter que está presente
    char	str1[] = "Hola Mundo!";
    test_ft_memchr	(str1, 'M', 12);

    // Test 2: Búsqueda de un carácter al final de la cadena
    test_ft_memchr	(str1, '!', 12);

    // Test 3: Búsqueda de un carácter que no está presente
    test_ft_memchr	(str1, 'Z', 12);

    // Test 4: Búsqueda con n = 0 (no debería buscar)
    test_ft_memchr	(str1, 'H', 0);

    // Test 5: Búsqueda en un bloque de memoria con valores especiales
    unsigned char	mem[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    test_ft_memchr	(mem, 5, 10);  // Buscar el valor 5
    test_ft_memchr	(mem, 10, 10); // Valor 10 no existe en el bloque

    // Test 6: NULL como puntero (comprobar si tu función gestiona NULL correctamente)
    test_ft_memchr	(NULL, 'A', 5);


// Test ft_memcmp()
    // Test 0: Comparar bloques de memoria iguales al principio
    char str7[] = "\xff\xaa\xde\x12";
    char str8[] = "\xff\xaa\xde\x12MACOSAAAAA";
    test_ft_memcmp(str7, str8, 4);

    // Test 1: Comparar bloques de memoria idénticos
    char str1[] = "Hola Mundo!";
    char str2[] = "Hola Mundo!";
    test_ft_memcmp(str1, str2, 12);

    // Test 2: Comparar bloques de memoria con una diferencia
    char str3[] = "Hola Mundo!";
    char str4[] = "Hola Mundo?";
    test_ft_memcmp(str3, str4, 12);

    // Test 3: Comparar solo una parte de bloques idénticos
    test_ft_memcmp(str3, str4, 5);

    // Test 4: Comparar bloques de memoria completamente diferentes
    char str5[] = "ABCDE";
    char str6[] = "abcde";
    test_ft_memcmp(str5, str6, 5);

    // Test 5: Comparar bloques con tamaño n = 0
    test_ft_memcmp(str5, str6, 0);

    // Test 6: Comparar bloques con valores binarios
    unsigned char mem1[] = {0, 1, 2, 3, 4, 5};
    unsigned char mem2[] = {0, 1, 2, 3, 4, 6};
    test_ft_memcmp(mem1, mem2, 6);

    // Test 7: Comparar punteros NULL (si implementas protección)
    // Nota: Si ft_memcmp no comprueba punteros NULL, este test puede dar un segfault.
    printf("\nTest con NULL (si manejas punteros NULL):\n");
    test_ft_memcmp(NULL, mem2, 0);
    test_ft_memcmp(mem1, NULL, 0);


// Test ft_strnstr()
    //Test 0: Comparar 2 cadenas
    // char str1[] = "is there a nyacat ?";
    // char str2[] = "is there a nyacat ?";
    // char *out = ft_strnstr(str1, str2, 20);
	// printf("strlen(str2) = %zu\n", strlen(str2));
	// printf("ft_strnstr Output #1: '%s'\n", out);

    //Test 0: Comparar 2 cadenas con len = 15
    // char str1[] = "lorem ipsum dolor sit amet";
    // char str2[] = "dolor";
    // char *out = ft_strnstr(str1, str2, 15);
	// printf("ft_strnstr Output #1: '%s'\n", out);

    //Test 0: Comparar 2 cadenas
    char str1[] = "MZIRIBMZIRIBMZE123";
    char str2[] = "MZIRIBMZE";
    char *out = ft_strnstr(str1, str2, strlen(str2));
	printf("strlen(str2) = %zu\n", strlen(str2));
	printf("ft_strnstr Output #1: '%s'\n", out);

    //Test 1: Comparar 2 cadenas diferentes con len = 0 o 1
    // char str1[] = "abc";
    // char str2[] = "xyz";
    // char *out = ft_strnstr(str1, str2, 1);
	// printf("ft_strnstr Output #1: '%s'\n", out);

    // Test 2: Comparar 2 cadenas vacias con len = 0
    // char str1[] = "";
    // char str2[] = "";
    // char *out = ft_strnstr(str1, str2, 0);
	// printf("ft_strnstr Output #2: '%s'\n", out);

    // Test 3: Comparar 2 cadenas con len = 4, 5 o 6
    // char str1[] = "aaxx";
    // char str2[] = "xx";
    // char *out = ft_strnstr(str1, str2, 1);
	// printf("ft_strnstr Output #3: '%s'\n", out);

    // Test 4: Comparar 2 cadenas con len = 2 o 3
    // char str1[] = "aaxx";
    // char str2[] = "xx";
    // char *out = ft_strnstr(str1, str2, 3);
	// printf("ft_strnstr Output #4: '%s'\n", out);

    // Test 5: Comparar 2 cadenas con len = 3
    // char str1[] = "abcdef";
    // char str2[] = "abc\375xx";
    // char *out = ft_strnstr(str1, str2, 3);
	// printf("ft_strnstr Output #5: '%s'\n", out);

    // Test 6: Comparar 2 cadenas con len = 3
    // char str1[] = "abc";
    // char str2[] = "abc";
    // char *out = ft_strnstr(str1, str2, 7);
	// printf("ft_strnstr Output #6: '%s'\n", out);


// Test ft_strnstr()
    const char *str1 = "   -1234abc";
    const char *str2 = "5678";
    const char *str3 = "   +42";
    const char *str4 = "   0";
    const char *str5 = "NotANumber";


    printf("NUMBER 1: %s\n", str1);  // Salida: -1234
    printf("[FT] Resultado 1: %d\n", ft_atoi(str1));  // Salida: -1234
    printf("[std]Resultado 1: %d\n", atoi(str1));  // Salida: -1234
    printf("NUMBER 2: %s\n", str2);  // Salida: 5678
    printf("[FT] Resultado 2: %d\n", ft_atoi(str2));  // Salida: 5678
	printf("[std]Resultado 2: %d\n", atoi(str2));  // Salida: 5678
    printf("NUMBER 3: %s\n", str3);  // Salida: 42
    printf("[FT] Resultado 3: %d\n", ft_atoi(str3));  // Salida: 42
    printf("[std]Resultado 3: %d\n", atoi(str3));  // Salida: 42
    printf("NUMBER 4: %s\n", str4);  // Salida: 0
    printf("[FT] Resultado 4: %d\n", ft_atoi(str4));  // Salida: 0
	printf("[std]Resultado 4: %d\n", atoi(str4));  // Salida: 0
    printf("NUMBER 5: %s\n", str5);  // Comportamiento indefinido (no numérico)
    printf("[FT] Resultado 5: %d\n", ft_atoi(str5));  // Comportamiento indefinido (no numérico)
    printf("[std]Resultado 5: %d\n", atoi(str5));  // Comportamiento indefinido (no numérico)


// Test ft_calloc()
    printf("=== Test de calloc y ft_calloc ===\n");

	// Test 0
    int *arr1; // ft_ function
	int *arr2; // std function
    size_t n = 5;  // Número de elementos
    // Asigna memoria para 5 enteros
    arr1 = (int *)ft_calloc(n, sizeof(int));
	arr2 = (int *)calloc(n, sizeof(int));
    if (arr1 == NULL)
	{
        printf("[ft_] Error: No se pudo asignar memoria\n");
        return 1;
    }
	if (arr2 == NULL)
	{
		printf("[std] error: No se pudo asignar memoria\n");
		return 1;
	}
    // Mostrar valores inicializados
    for (size_t i = 0; i < n; i++)
	{
        printf("[ft_] arr1[%zu] = %d\n", i, arr1[i]);  // Todos los valores serán 0
    }
	for (size_t i = 0; i < n; i++)
	{
		printf("[std] arr2[%zu] = %d\n", i, arr2[i]);	// Todos los valores serán 0
	}
    // Liberar memoria
    free(arr1);
	free(arr2);

    // Test 1: Comprobar si calloc y ft_calloc devuelven memoria inicializada a cero
    // size_t n = 5;
    size_t size = sizeof(int);

    int *orig = calloc(n, size);
    int *ft = ft_calloc(n, size);

    int test1_passed = 1;
    for (size_t i = 0; i < n; i++) {
        if (orig[i] != 0 || ft[i] != 0) {
            test1_passed = 0;
            break;
        }
    }
    print_test_result("Memoria inicializada a cero", test1_passed);

    // Test 2: Comprobar si ambas funciones asignan la misma cantidad de memoria
    size_t alloc_size = n * size;
    int test2_passed = memcmp(orig, ft, alloc_size) == 0;
    print_test_result("Asignación de la misma cantidad de memoria", test2_passed);

    // Test 3: Comprobar que ambas funciones devuelven NULL en caso de asignación inválida
    void *orig_invalid = calloc(SIZE_MAX, SIZE_MAX);
	void *ft_invalid = ft_calloc(SIZE_MAX, SIZE_MAX);

    int test3_passed = (orig_invalid == NULL && ft_invalid == NULL);
    print_test_result("Manejo de asignación inválida", test3_passed);

    // Liberar memoria
    free(orig);
    free(ft);

    printf("=== Fin de pruebas ===\n");


// Test ft_strdup()
    printf("=== Test de strdup y ft_strdup ===\n");

	// Test 0
	const char *test1 = "Hola Mundo";	// Caso normal
	char *result1_ft_ = ft_strdup(test1);
	printf("result1_ft_: '%s'\n", result1_ft_);
	char *result1_std = ft_strdup(test1);
	printf("result1_std: '%s'\n", result1_std);
	free(result1_ft_);
	free(result1_std);

	const char *test2 = "";				// Cadena vacía
	char *result2_ft_ = ft_strdup(test2);
	printf("result2_ft_: '%s'\n", result2_ft_);
	char *result2_std = strdup(test2);
	printf("result2_std: '%s'\n", result2_std);
	free(result2_ft_);
	free(result2_std);

	// const char *test3 = NULL;			// Caso NULL (verificación manual)
	// char *result3_ft_ = ft_strdup(test3);
	// printf("result3_ft_: '%s'\n", result3_ft_);
	// char *result3_std = strdup(test3);
	// printf("result3_std: '%s'\n", result3_std);
	// free(result3_ft_);
	// free(result3_std);

	// Test 1
	const char *test_cases[] = {
        "Hola Mundo",   // Caso normal
        "",             // Cadena vacía
        NULL            // Caso NULL (verificación manual)
    };

    for (int i = 0; i < 3; i++) {
        const char *input = test_cases[i];
        char *result_std = NULL;
        char *result_ft = NULL;

        // Verificamos si la entrada no es NULL antes de llamar a strdup
        if (input != NULL) {
            result_std = strdup(input);
            result_ft = ft_strdup(input);

            // Comprobación manual
            if (result_std == NULL || result_ft == NULL)
			{
                printf("Error: strdup o ft_strdup devolvió NULL para el caso %d\n", i + 1);
            }
			else if (strcmp(result_std, result_ft) == 0)
			{
                printf("Prueba %d: [PASSED]\n", i + 1);
            }
			else
			{
                printf("Prueba %d: [FAILED] - Las cadenas no coinciden.\n", i + 1);
            }

            // Liberamos la memoria si no es NULL
            free(result_std);
            free(result_ft);
        }
		else
		{
            // Caso NULL: ft_strdup debería devolver NULL
            result_ft = ft_strdup(input);
            if (result_ft == NULL)
			{
                printf("Prueba %d: [PASSED] - ft_strdup devolvió NULL como esperado.\n", i + 1);
            }
			else
			{
                printf("Prueba %d: [FAILED] - ft_strdup no devolvió NULL.\n", i + 1);
                free(result_ft);  // Liberamos si hay un error inesperado
            }
        }
    }

	printf("=== Fin de pruebas ft_strdup ===\n");
*/


	// END of tests
	return (0);
}