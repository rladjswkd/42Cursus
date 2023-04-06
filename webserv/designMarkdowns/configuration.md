# Configuration

## validation

1. `{` `}`가 한 쌍으로 들어왔는지   

- `{`가 나오면 +1, `}`가 나오면 -1로 카운트 해 마지막에 0이 되는지 확인한다.
- 중간에 **음수**가 나오면 예외 처리하기

2. `;`으로 지시자가 끝나는지

- 토큰화한 토큰들을 담고 있는 벡터를 기준으로, `;`이 올 수 있는 위치는 다음과 같다.    
    1. `}` 직전 인덱스
    2. 지시자(키워드) 직전 인덱스
    3. 마지막 인덱스  

3. 유효한 keyword가 들어왔는지

    a. block keyword랑 simple directive keyword를 set으로 미리 저장해 검색하기

4. 필수 키워드 존재 여부 확인하기 => 파싱이 끝난 후 location 클래스들의 멤버 변수들에 대해 인자인 vector의 size가 1 이상인지 확인

5. keyword level에 맞게 들어왔는지 확인하기

    - 예를 들면 server block level에 return이 있으면 안된다. 모든 서버에 return이 적용되면 return이 index보다 우선순위가 높기 때문에 무조건 return이 적용된다.

    - 찬규님 노션 context 정리 보고 구현

6. 지시자의 인자로 올바른 값이 들어왔는지 확인하기

    - 지시자별로 여기에 기준 적어놓기

    - 개수, 형식이 다 맞는지 등

7. location 지시자 바로 뒤에는 공백이 와야 한다. 여러 개가 올 수도 있게 처리하거나 하나 이상이 오면 오류로 처리하거나 해야한다.

8. server 등 블록 지시자와 `{` 사이에는 공백이 없어도 되고 있어도 된다.


## Design

- std::getline을 참고해 파싱 함수를 구현하자.

1. 공백 문자가 아닌 문자가 나올 때까지 space, `\n`, `\t` 등 모든 공백 문자들을 계속 넘긴다.

2. 공백 문자가 아닌 문자가 나오면 공백 문자가 나올 때까지 string에 이어 붙인다.

3. 공백 문자가 나오면 현재 string에 쌓여있는 내용을 set에 담겨있는 키워드들이랑 비교한다.

    a. server나 location이라면 block에 해당하는 객체(server 또는 location)를 인스턴스화 하고 해당 객체에 대한 레퍼런스를 인자로 받으며, block을 파싱하는 함수를 호출한다. (파싱한 내용을 레퍼런스 인자에 저장한다.) `parseBlock`

    b. parseBlock 내에서 호출할 함수로, directives를 파싱하는 함수가 필요하다. `parseDirective`

    c. block directive든 일반 directive든 set에 담겨있는 키워드가 아니라면 오류다.

- `parseBlock`
    ```
    첫 번째 인자로 Block& 타입을 받는다. Block 클래스는 Server, Location이 상속받는 상위 클래스로 parseBlock이 Server와 Location을 모두 첫 번째 인자로 받을 수 있게 하기 위해 존재한다.

    
    ```

- 가장 바깥 block 부터 순서대로 파싱하되, 내부 block이 나오면 해당 block에 바깥 block에서 선언된 지시자들을 적용하지 않고, 내부 block은 내부 block 내에 선언된 지시자들만 포함하게 해서 우선 configuration file을 끝까지 파싱한다. 그 후에 바깥 block에 포함된 지시자들을 내부 block 들에 하나씩 추가하는 방식으로 구현하자. 이렇게 하면 바깥 block에 선언됐지만 내부 block보다 라인 순서상 아래에 선언된 지시자들도 내부 block에 적용할 수 있으며, 동일한 지시자일 때 내부 block에 선언된 지시자가 우선순위가 높은데, 우리가 활용할 자료구조인 map의 동작 구조 상 이미 내부에 key가 존재하면 새로운 key - value 쌍이 들어와도 추가되지 않기 떄문에 우선순위가 높은 걸 추가해야 한다. 따라서 별도의 추가 로직 없이 우선순위대로 파싱을 수행할 수 있다.

- cgi 관련
    apache처럼 /cgi-bin/ 경로를 활용한다.

### Lexer

| LEXEME                    | TOKEN                 |
| ---                       | ---                   |
| `server`                  | SERVER                |
| `location`                | LOCATION              |
| `{`                       | LBRACKET              |
| `}`                       | RBRACKET              |
| `;`                       | SEMICOLON             |
| `listen`                  | DIRECTIVE_ONE_ARG     |
| `server_name`             | DIRECTIVE_MUL_ARG     |
| `error_page`              | DIRECTIVE_ERR_PAGE    |
| `client_max_body_size`    | DIRECTIVE_ONE_ARG     |
| `limit_except`            | DIRECTIVE_MUL_ARG     | 
| `redirect`                | DIRECTIVE_ONE_ARG     |
| `alias`                   | DIRECTIVE_ONE_ARG     |
| `autoindex`               | DIRECTIVE_ONE_ARG     |
| `index`                   | DIRECTIVE_MUL_ARG     |
| arguments for directives  | TEXT                  |

파일 경로와 키워드가 담긴 set을 받아 멤버 변수를 초기화하는 생성자

현재 문자가 공백, \n, \t, \r, \f, \v일 때 지금까지 읽어 놓은 word를 토큰화 하는 기능. 공백, \n, \t, \r, \f, \v는 뛰어넘기

현재 문자가 `x`일 때 지금까지 읽어놓은 word를 토큰화 하고 그 이후에 `x`를 토큰화 하는 기능 - `x`에는 {, ;, }가 올 수 있다.

전반적으로 ifstream 내용을 EOF까지 읽어서 토크나이즈 하는 기능.

### Parser

servermap parse(stringvector-tokenized)   
{

}

server 키워드를 만났을 때, {, } 쌍 찾아서 그 사이에 있는 내용으로 server 객체 생성하는 기능

location 키워드를 만났을 때, {, } 쌍 찾아서 그 사이에 있는 내용으로 location 객체 생성하는 기능

Config 멤버 변수 구현 - 인스턴스화가 필요하지 않음. 가장 밖에 선언된 지시자들을 담아주기 위한 구조가 필요할 뿐.

Server 멤버 변수 구현

Location 멤버 변수 구현

전반적으로 토큰화 된 벡터를 받아서 std::map 구조의 서버 목록을 생성하는 기능