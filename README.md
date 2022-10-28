# Libasm

ASM Library using x64 registers.
This project was done with a intel x64 on MAC OS.


## Usage

- Clone Repository
```bash
git clone https://github.com/vvaucoul/Libasm && cd Libasm
```

- Compilation
```bash
make
```

## Functions

```C
int ft_strlen(const char *str);
char *ft_strcpy(char *s1, const char *s2);
size_t ft_read(int fildes, void *buf, size_t nbyte);
ssize_t ft_write(int fildes, const void *buf, size_t nbyte);
int ft_strcmp(const char *s1, const char *s2);
char *ft_strdup(const char *s1);
```

> Linked List

```C
typedef struct s_list
{
  void *data;
  struct s_list *next;
} t_list;
```

```C
int ft_list_size(t_list *list);
int ft_atoi_base(char const *str, char const *base);
void ft_list_push_front(t_list **list, void *data);
void ft_list_remove_if(t_list **list, void *data_ref, int (*cmp)(), void (*free_fct)(void*));
void ft_list_sort(t_list **list, int (*cmp)());
```
