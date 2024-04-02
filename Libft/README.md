## Libft
C 표준 라이브러리의 일부 함수와 그 밖의 유틸리티 함수들을 재구현한 과제입니다.    

### 사용

폴더 내부에서 `make`를 입력하면 정적 라이브러리 `libft.a`를 생성합니다.

### libc
`isalpha` `isdigit` `isalnum` `isascii` `isprint` `strlen` `memset` `bzero` `memcpy` `memmove` `strlcpy` `strlcat` `toupper` `tolower` `strchr` `strrchr` `strncmp` `memchr` `memcmp` `strnstr` `atoi`

아래의 두 함수는 `malloc`을 사용하여 구현합니다.
`calloc` `strdup`

모든 libc 재구현 함수들은 libc 라이브러리와 동일하게 동작합니다.

### utility functions
```c
char *ft_substr(char const *s, unsigned int start, size_t len);
```
- 문자열 `s`의 `start` 인덱스부터 `len` 만큼의 길이를 갖는 부분 문자열을 반환합니다.
- 메모리 할당에 실패할 경우 `NULL`을 반환합니다.
```c
char *ft_strjoin(char const *s1, char const *s2);
```
- 문자열 `s1`에 `s2`를 이어붙인 새로운 문자열을 반환합니다.
- 메모리 할당에 실패할 경우 `NULL`을 반환합니다.
```c
char *ft_strtrim(char const *s1, char const *set);
```
- 문자열 `s1`의 시작과 끝에 위치한 `set`에 포함된 문자들을 제거한 새로운 문자열을 반환합니다.
- 메모리 할당에 실패할 경우 `NULL`을 반환합니다.
```c
char **ft_split(char const *s, char c);
```
- 문자열 `s`를 `c`를 구분자로 활용하여 나눈 문자열 배열을 반환합니다.
- 메모리 할당에 실패할 경우 `NULL`을 반환합니다.
```c
char *ft_itoa(int n);
```
- 정수 `n`을 표현하는 문자열을 반환합니다.
- 메모리 할당에 실패할 경우 `NULL을 반환합니다.
```c
char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
```
- 문자열 `s`의 모든 문자에 함수 `f`를 적용한 새로운 문자열을 반환합니다.
- `f`의 두 번째 인자는 `s` 내의 문자를, 첫 번째 인자는 두 번째 인자의 `s` 내에서의 인덱스를 나타냅니다.
  메모리 할당에 실패할 경우 `NULL`을 반환합니다.
```c
void ft_striteri(char *s, void (*f)(unsigned int, char*));
```
- 문자열 `s`의 모든 문자에 함수 `f`를 적용합니다.
- 문자열을 반환하는 것을 제외하면 `ft_strmapi`와 동일합니다.
```c
void ft_putchar_fd(char c, int fd);
```
- 주어진 파일 디스크립터 `fd`에 문자 `c`를 출력합니다.
```c
void ft_putstr_fd(char *s, int fd);
```
- 주어진 파일 디스크립터 `fd`에 문자열 `s`를 출력합니다.
```c
void ft_putendl_fd(char *s, int fd);
```
- 주어진 파일 디스크립터 `fd`에 문자열 `s`와 개행 문자를 출력합니다.
```c
void ft_putnbr_fd(int n, int fd);
```
- 주어진 파일 디스크립터 `fd`에 정수 `n`을 출력합니다.
---
아래 유틸리티 함수들은 다음과 같은 연결 리스트 구조체를 활용합니다.
```C
typedef struct s_list
{
  void *content;
  struct s_list *next;
} t_list;
```
---
```c
t_list *ft_lstnew(void *content);
```
- 구조체 `t_list`의 `content`는 주어진 인자 `content`로 초기화하고, `next`는 NULL로 초기화한 새로운 노드를 반환합니다.
```c
void ft_lstadd_front(t_list **lst, t_list *new);
```
- 리스트 `lst`의 시작 부분에 새로운 노드 `new`를 연결합니다.
```c
void ft_lstadd_back(t_list **lst, t_list *new);
```
- 리스트 `lst`의 끝 부분에 새로운 노드 `new`를 연결합니다. 
```c
int ft_lstsize(t_list *lst);
```
- 리스트 `lst`의 길이를 반환합니다.
```c
t_list *ft_lstlast(t_list *lst);
```
- 리스트 `lst`의 마지막 노드를 반환합니다.
```c
void ft_lstdelone(t_list *lst, void (*del)(void *));
```
- 노드 `lst`의 `content`를 `del` 함수로 해제(free)한 후, 노드 `lst`를 해제합니다.
```c
void ft_lstclear(t_list **lst, void (*del)(void *));
```
- 리스트 `lst`의 모든 노드에 대해 `content`를 `del` 함수로 해제하고, 노드를 해제합니다.
```c
void ft_lstiter(t_list *lst, void (*f)(void *));
```
- 리스트 `lst`의 모든 노드의 `content`에 함수 `f`를 적용합니다.
```c
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
```
- 리스트 `lst`의 모든 노드의 `content`에 함수 `f`를 적용한 새로운 리스트를 반환합니다.
- 필요 시 `del` 함수를 전달해 노드의 `content`를 지울 수 있습니다.
