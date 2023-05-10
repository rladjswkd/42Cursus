# HttpConf
## types
```
typedef std::string	            Host;
typedef std::string	            Port;
typedef std::pair<Host, Port>	SocketAddr;
```

## members
### private
- `serverBlocks` : *std::map< SocketAddr, MappedSocketAddr >*
    ```
    server block들을 저장한다.
    ```
- `directives` : *std::map< Directive, std::set\<Argument> >*
    ```
    Http block에 정의된 지시자들을 저장한다.
    ```

## functions
### private

- `addServerConf()`

    ```
    serverBlocks에 추가한다. 
    ```

### public

- `HttpConf(const char *)`
    ```
    멤버 filePath를 초기화
    ```
- `parse()`
    ```
    filePath에 해당하는 파일에서 정보를 추출
    ```



# ServerConf
- ServerConf(std::map< Directive, std::set< Argument > >);
- addLocationConf()

# LocationConf
- LocationConf(std::map < Directive, std::set< Argument > >);
- setDirective(Directive, Argument)


private functions

- 서버 객체를 찾는 함수 -> accept에 활용한 서버 파일 디스크립터를 인자로 받는다. getsockopt로 host, port 번호를 가져오고 그 정보로 서버 객체를 찾은 후, 이 객체를 local을 찾는 데 활용하기 위한 함수.

pubulic functions

1. 서버 bind 시 필요한 host, port 정보 반환 -> map iterator 돌면서 pair의 first를 vector에 담아 vector로 반환

2. location 객체를 찾는 함수 -> 서버 객체를 찾는 함수를 호출해 서버 객체를 가져온 후, http request message의 URI를 키값으로 하는 location을 찾는다.

    - URI에 따라 location을 선택하는 기준

        - URI가 location uri로 시작해야 한다

        - URI와 일치하는 부분이 가장 긴 location을 선택한다

        [예시 1] URI가 /temp/, location1이 /temp/, location2가 /temp/tomp/

            location1이 선택된다.

        [예시 2] URI가 /temp, location1이 /temp/, location2가 /temp/tomp/

            아무 location도 선택되지 않고 404로 반환한다.

        [예시 3] URI가 /temp/tomp/, location1이 /temp/, location2가 /temp/tomp/

            location2가 선택된다.
        
        [예시 4] URI가 /temp/tomp, location1이 /temp/, location2가 /temp/tomp/

            location1이 선택된다.

        [예시 5] URI가 /temptomp, location1이 /temp/, location2가 /temp/tomp/

            아무 location도 선택되지 않고 404로 반환한다.

        [특수 예시 1] URI가 /temp, location1이 /temp, location2가 /temp/

            우선 이 예시는 URI가 /로 끝나지 않으며, location에도 일치하는 location이 있는 경우를 말한다.
            이땐 location1이 선택된다.
            location1에 return이 있다면 무조건 return이 수행된다.
            하지만 index만 있다면 301 상태 코드와 /temp/ Location header field로 리다이렉트 응답을 해야한다.

        [특수 예시 2] URI가 /tempppppp, location1이 /temp, location2가 /temp/

            만약 location1에 return이 있다면 location1이 선택되고 return으로 리다이렉트 된다.
            하지만 location1에 return이 없고 index만 있다면, 서버에 의해 /tempppppp/로 리다이렉트되기 때문에 404가 뜰것이다.
