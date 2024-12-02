# Libft
Primer proyecto como estudiante de 42Malaga

Parte 1 - Funciones de libc
Implementar las siguientes funciones (No requieren de funciones autorizadas):
• ft_isalpha
• ft_isdigit
• ft_isalnum
• ft_isascii
• ft_isprint
• ft_strlen
• ft_memset
• ft_bzero
• ft_memcpy
• ft_memmove
• ft_strlcpy
• ft_strlcat
• ft_toupper
• ft_tolower
• ft_strchr
• ft_strrchr
• ft_strncmp
• ft_memchr
• ft_memcmp
• ft_strnstr
• ft_atoi
Para implementar estas otras dos funciones, tendrás que utilizar malloc():
• ft_calloc
• ft_strdup

Parte 2 - Funciones adicionales
• ft_substr
• ft_strjoin
• ft_strtrim
• ft_split
• ft_itoa
• ft_strmapi
• ft_striteri
• ft_putchar_fd
• ft_putstr_fd
• ft_putendl_fd
• ft_putnbr_fd

Parte bonus
utilizar la siguiente estructura para representar un nodo de tu lista. Añade
la declaración a tu archivo libft.h:
  typedef struct s_list
  {
  void *content;
  struct s_list *next;
  } t_list;
Los miembros de la estructura t_list son:
• content: la información contenida por el nodo.
void *: permite guardar cualquier tipo de información.
• next: la dirección del siguiente nodo, o NULL si el siguiente nodo es el último.

Implementa las siguientes funciones para utilizar fácilmente tus listas:
ft_lstnew
ft_lstadd_front
ft_lstsize
ft_lstlast
ft_lstadd_back
ft_lstdelone
ft_lstclear
ft_lstiter
ft_lstmap
