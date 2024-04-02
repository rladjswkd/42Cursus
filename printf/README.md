## ft_printf
libc의 printf를 재구현하는 프로젝트입니다.

```c
int ft_printf(const char *, ...);
```

- `c` `s` `p` `d` `i` `u` `x` `X` `%` 변환 지정자를 허용합니다.
- 플래그 `-` `0` `.`와 `field minimum width`를 허용합니다.
- 플래그 `#` ` ` `+`를 허용합니다. 

※ libc printf의 버퍼 관리 기능은 포함하지 않습니다.

### 사용

디렉터리 내부에서 `make`를 입력하면 정적 라이브러리 `libftprintf.a`를 생성합니다.

