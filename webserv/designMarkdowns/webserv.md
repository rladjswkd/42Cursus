# Webserv Design

1. main 함수에서 configuration file 경로나 기본 경로를 받기 `Server 생성자`

    a. 받은 경로를 저장하기 `Server 멤버 변수1`

2. 저장한 configuration file 불러오기 `Server 멤버 함수1`

3. configuration file 파싱하기 `Server 멤버 함수2`

    a. 파싱한 내용을 저장하기 `Server 멤버 변수2`

    b. ServerConfiguration.md 참고

4. 파싱해 저장한 내용대로 socket servers 구성하기 `Server 멤버 함수3`

    a. socket()으로 생성한 socket file descriptors에 bind()로 configuration file에서 파싱한 IP, PORT 등 서버 설정을 엮어주기

    b. 모든 server sockets에 대해 listen()을 호출하기

5. server socket에 대해 I/O event가 발생했을 때 처리하기 `Client 생성자`

    a. accept() 의 첫 번째 인자인 sockfd(server socket)가 bind된 IP, PORT를 getsockname으로 찾고, std::pair로 묶어, 연결된 Client 객체에 저장하기 `Client 멤버 변수1`
    
    b. accept()가 반환한 연결된 socket을 Nonblock으로 만든 후 epoll_ctl에 등록하기

    c. 5번부터는 반복문으로 반복

6. HTTP request message read event가 발생했을 때 처리하기

    a. read event가 발생한 socket file descriptor를 키 값으로 해 대응하는 Client 객체를 찾는다.

    - 연결된 Client 객체들을 std::map으로 담을 클래스 고려하기. HTTP라는 클래스를 만들어서 그 안에 담고 가장 밖에서 수행되는 함수들을 HTTP 클래스에 구현할까? 

    b. recv() 함수로 메시지를 버퍼만큼 읽어와 Client에 저장한다. `Client 멤버 변수 2`, `Client 멤버 함수 2` 

    c. 현재 버퍼 내에 "Transfer-Encoding" 또는 "Content-Length"이 포함되어있는지 확인해, 포함되어 있다면 body까지 읽고, 포함되어있지 않다면 "\r\n\r\n"까지 읽는다.

    - Transfer-Encoding이 있다면 인코딩 방식에 맞게 적절히 읽어준다.

    - Content-Length가 있다면 해당 길이만큼 적절히 읽어준다. (\r\n\r\n 이후부터 카운트)

    - 둘 다 있다면 연결을 끊어버리거나 Transfer-Encoding을 기준으로 해석하기 (RFC 9112 기준)

7. 기준까지 모두 읽었다면 HTTP parser에 전달하기

    ... 메시지 처리 후 응답 메시지 생성

8. HTTP 응답 메시지 저장하기 `Client 멤버 변수 3`

    a. Response 클래스에 멤버 변수로 char 배열로 저장하고 관련해 제공할 기능을 함수로 구현한다. `Response 멤버 변수 1`
    
    - Client 멤버 변수로 std::string을 쓰면 계속해서 send()에 전달할 버퍼 사이즈만큼 substr()를 호출해 새로운 std::string 객체를 생성하고 해당하는 부분을 복사하는 데 시간이 걸리기 때문에 char 배열을 사용하는 게 더 효율적이다.

    - Client의 멤버 변수로 Response 객체를 저장한다.

9. write event가 발생하면 버퍼 사이즈만큼 send() 하기

    a. Response의 멤버 변수 포인터를 버퍼 사이즈만큼 증가시켜 갱신하기

    b. 모든 내용을 온전히 전송하고 난 후에는 연결을 닫기 (close? shutdown?)

    - file에 대한 모든 file descriptor가 close되면 해당 파일은 epoll의 interest list에서 제거된다. (man epoll)

---
- Server 클래스를 인스턴스화 하지않고 정적 함수들만을 활용하는 경우와 관련해 아래 링크를 참고하자.

    https://stackoverflow.com/questions/9321/how-do-you-create-a-static-class-in-c


- socket()은 중복된 file descriptor를 반환하진 않는가?

    https://www.ibm.com/docs/en/aix/7.1?topic=volumes-using-file-descriptors

    당연한 소리지만 socket도 file descriptor이고, file descriptor는 프로세스마다 유일하다.

- 클라이언트에서 연결을 끊으면, epoll은 해당 socket file descriptor를 readable로 인식하고 이벤트를 알린다.

    https://stackoverflow.com/questions/14563134/epoll-loops-on-disconnection-of-a-client

- 서버는 응답 메시지를 생성해서 온전히 전송하고 난 후엔 연결을 끊어야 한다.

    ```
    RFC 9112

    A server MAY reject a request that contains both Content-Length and Transfer-Encoding or process such a request in accordance with the Transfer-Encoding alone. Regardless, the server MUST close the connection after responding to such a request to avoid the potential attacks.
    ```

- 위 설계 내용을 기반으로 필요한 기능들을 추가해 함수로 구현하자.

- Response 클래스는 있는데 Request 클래스는 없으므로 구색 갖추기 용으로 std::string을 상속 받고 그 외의 멤버는 따로 추가하지 않은 클래스를 정의해, std::string 대신 Response 클래스를 쓰자.