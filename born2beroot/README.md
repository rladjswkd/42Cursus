# born2beroot

## VirtualBox란?

<aside>
💡 x86, AMD64/Intel64용 [가상화](https://www.notion.so/Virtualization-f3e9b982984d405bbcea466d10b4d3bc) 도구이다.

</aside>

Windows, Linux, Macintosh, Solaris 운영체제를 가진 physical hardware, computer(**host**)에서 
[다음과 같은 운영체제](https://www.virtualbox.org/wiki/Guest_OSes)(**guest operating system**)를 실행할 수 있다.

이 때 guest operating system은 host 위의 특별한 환경에서 실행할 수 있고, 
이 특별한 환경을 **virtual machine**이라고 한다.

virtual machine은 Virtualbox와 같은 virtualization software가 host의 특정 하드웨어나 기능을 인터셉트해 만든다.

[이 페이지](https://www.virtualbox.org/)에 따르면 Virtualbox는 “**full virtualization**” product이며, 
“원래의 소프트웨어를 모두 가진, 수정되지 않은 운영체제”를 실행할 수 있다는 뜻이라고 한다.

- Java Virtual Machine의 virtual machine과의 차이점
    
    [Virtual machine - Wikipedia](https://en.wikipedia.org/wiki/Virtual_machine)
    
    JVM은 process virtual machine이고, VirtualBox는 system virtual machine이다.
    

## 왜 virtualization이 필요할까?

### 1. 운영 체제 및 소프트웨어 실행 지원

특정 운영체제에서만 실행되는 소프트웨어를 다른 운영체제에서 실행할 수 있다. (특정 운영체제를 virtual machine에서 실행함으로써.)

### 2. infrastructure consolidation

현대는 컴퓨터의 기능이 뛰어나, 최대 성능을 full time으로 필요로 하지 않는다.

따라서 최소 개수의 하드웨어(컴퓨터)에서 virtualization을 이용해 여러 시스템을 실행할 수 있다.

## VirtualBox 설치하기

과카몰리 vnc 환경에서 dmg 파일을 직접 받아서 설치하려 하면 관리자 계정을 요구함.

→ Managed Software Center에서 virtualbox를 검색해서 설치하면 해결할 수 있다.

## Virtual machine 생성하기

VirtualBox를 실행한 후, New를 클릭하고 아래의 정보들을 입력한다.

- 참고 이미지
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled.png)
    

Machine Folder는 참고 이미지와 다르게 goinfre로 지정했다.

### Name

virtual machine의 이름으로, 해당 virtual machine의 파일들에 사용된다.

### Machine folder

생성할 virtual machine이 저장될 위치를 지정한다.

### Type & Version

virtual machine에서 실행할 운영체제를 지정한다.

### Memory size

virtual machine이 실행될 때 할당될 메모리 크기를 지정한다. (이후에 변경할 수 있다.)

- 참고 이미지
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%201.png)
    

### Hard disk

virtual machine이 사용할 가상 하드 디스크에 대한 설정을 할 수 있다.

- 참고 이미지
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%202.png)
    

### Hard disk file type

**VDI** : VirtualBox의 native format이며, 다른 virtualization software에선 일반적으로 지원하지 않는다. 단, 다른 virtualization software에서 사용할 수 있는 타입으로 변환하는 것은 어렵지 않다.

**VHD** : Microsoft의 hypervisor(=virtual machine system)인 Hyper-V의 native format이다.

**VMDK** : VMware를 위해 개발된 format이다.

- 참고 이미지
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%203.png)
    

### Storage on physical hard disk

<aside>
💡 VirtualBox는 두 타입의 disk image file을 지원한다.

</aside>

1. dynamically allocated file
    1. virtual hard disk에 데이터가 저장될 때마다 disk size를 증가시킨다. → 초기에는 용량이 작다.
2. fixed-size file
    1. 처음부터 지정한 용량의 disk image file을 생성한다. → 용량은 차지하지만, 오버헤드가 적어 상대적으로 빠르다.
- 참고 이미지
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%204.png)
    

### File location and size

virtual hard disk image를 저장할 위치를 지정한다.

- 참고 이미지
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%205.png)
    

## 생성한 virtual machine 실행하기

- VirtualBox manager window의 왼쪽 pane, virtual machine list에서 해당 virtual machine을 더블 클릭한다.
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%206.png)
    

### 생성한 virtual machine을 처음 실행할 때

- 실행 가능한 OS가 없는 상태이므로, OS를 설치해줘야 한다.
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%207.png)
    

[여기](https://www.debian.org/index.ko.html)에서 iso 파일을 다운로드 받은 후, first start wizard에서 다운로드 받은 iso 파일을 선택하고 start 버튼을 누른다.

### OS 설치 관련

<aside>
💡 아래의 os 설치 과정에서, sda5를 생성하지 말고, sda6를 sda5로 생성하자. 마지막에 1KB짜리 sda2가 자동으로 생성된다.

</aside>

- os 설치 과정
    1. graphical interface를 사용하면 안되고, 최소한의 서비스만 설치해야 한다고 매뉴얼에 나와있으므로, 그렇게 설치한다.
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%208.png)
    
    1. language를 English로 고른다. 한글로 설정하면 글자가 깨지는 현상이 있을 수 있다고 한다.
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%209.png)
    
    1. location을 other - asia - Korea, republic of 순서로 설정한다.
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2010.png)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2011.png)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2012.png)
    
    1. locale을 en_US.UTF-8로 설정한다.
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2013.png)
    
    1. keymap을 Korean으로 설정한다.
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2014.png)
    
    1. 매뉴얼에 host name은 인트라 아이디 + 42로 지정하라고 나와있으므로, 그렇게 설정한다.
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2015.png)
    
    1. domain name은 비워두고 넘어간다.
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2016.png)
    
    1. 매뉴얼의 strong password policy를 따라 동일한 글자가 3개 이상 반복되지 않고, 대문자와 숫자를 반드시 포함하며 최소한 10글자인 root password를 설정한다.
    → born2BEROOT로 지정.
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2017.png)
    
    1. root password 재입력.
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2018.png)
    
    1. sudo, user42 그룹에 포함시킬 사용자 계정을 만든다. Full name - Username - password - password check 순
    → gyepark, gyepark, 42seoulJJANG, 42seoulJJANG
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2019.png)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2020.png)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2021.png)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2022.png)
    
    1. 디스크 파티셔닝 - 매뉴얼의 내용과 비슷하게 구성하기 위해 수동 파티셔닝을 선택했다.
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2023.png)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2024.png)
    
    9-1. 매뉴얼 이미지의 sda생성
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2025.png)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2026.png)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2027.png)
    
    9-2. 매뉴얼 이미지의 sda1 - /boot 생성. bootable partition인 primary partition으로 지정.
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2028.png)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2029.png)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2030.png)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2031.png)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2032.png)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2033.png)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2034.png)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2035.png)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2036.png)
    
    9-3. 매뉴얼 이미지의 sda2 생성
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2037.png)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2038.png)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2039.png)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2040.png)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2041.png)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2042.png)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2043.png)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2044.png)
    
    9-3. 매뉴얼 이미지의 sda5 생성
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2045.png)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2046.png)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2047.png)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2048.png)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2049.png)
    
    9-4. encrypted partition을 생성.
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2050.png)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2051.png)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2052.png)
    
    (space로 선택 가능)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2053.png)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2054.png)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2055.png)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2056.png)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2057.png)
    
    (encrypted partition 비밀번호 설정 - encryptedlogicalPARTITION6)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2058.png)
    
    (encrypted partition 비밀번호 재입력을 하면 아래와 같은 화면이 뜬다.)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2059.png)
    
    9-5. encrypted partition에 `/`, `[swap]`, `/home`을 지정.
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2060.png)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2061.png)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2062.png)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2063.png)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2064.png)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2065.png)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2066.png)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2067.png)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2068.png)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2069.png)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2070.png)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2071.png)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2072.png)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2073.png)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2074.png)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2075.png)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2076.png)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2077.png)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2078.png)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2079.png)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2080.png)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2081.png)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2082.png)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2083.png)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2084.png)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2085.png)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2086.png)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2087.png)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2088.png)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2089.png)
    
    1. 파티셔닝 완료
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2090.png)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2091.png)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2092.png)
    
    1. 추가 설치 미디어 확인 → skip
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2093.png)
    
    1. debian archive mirror country 선택 
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2094.png)
    
    1. debian archive mirror site 선택
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2095.png)
    
    1. HTTP proxy information 입력 → 외부에서 접근할 필요 없으므로 skip
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2096.png)
    
    1. 패키지 사용 통계 정보 전송 참여 여부 → no
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2097.png)
    
    1. predefined software 설치 여부 → 최소한의 서비스만 사용할 것이므로 선택돼있는 SSH server와 standard system utilities를 제외하곤 선택하지 않는다.
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2098.png)
    
    1. boot loader 설치 여부
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2099.png)
    
    1. boot loader를 설치할 위치 지정
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%20100.png)
    
    1. 설치 완료
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%20101.png)
    

### OS 설치 완료 이후

- os 설치를 완료한 후엔 재부팅이 되고, 설정한 encrypted disk에 대한 비밀번호를 입력해야 한다.
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%20102.png)
    
- 이후엔 생성한 계정으로 로그인해야 한다.
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%20103.png)
    
- 파티션 확인 `lsblk`
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%20104.png)
    

## root user와 일반 username user가 있는 지 확인

### /etc/passwd 파일

[/etc/passwd](https://linuxize.com/post/etc-passwd-file/) 파일의 line은 각 user에 대한 정보를 담고 있으며, `:`를 구분자로 다음 7개의 fields로 나뉜다.

1. `username`
2. `encrypted password` → x는 password가 /etc/shadow 파일에 저장된 것을 나타낸다.
3. `UID number` → UID = user id
4. `GID number` → GID = group id
5. `full name of the user` → [GECOS](https://en.wikipedia.org/wiki/Gecos_field)
6. `user home directory`
7. `login shell` → defaults to /bin/bash
- [그 밖의 방법 참고](https://linuxize.com/post/how-to-list-users-in-linux/)

### user 확인 방법

`less /etc/passwd` 또는 `cat /etc/passwd`

## Sudo

### Sudo package 설치하기

Debian을 설치한 직후엔 [sudo](https://wiki.debian.org/sudo/)가 설치되지 않은 상태이므로, 먼저 설치를 해준다.

- 1. root 계정으로 로그인한다. `su -`명령을 입력하면, 로그아웃하지 않고 root 계정을 쓸 수 있다.
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%20105.png)
    
- 2. OS를 update, upgrade한다.
    
    ```c
    apt update
    apt upgrade
    ```
    
- 3. sudo package 설치
    
    `apt install sudo`
    
- 4. 설치 확인
    
    `sudo apt list --installed | grep sudo`
    
    - [그 밖의 방법 참고](https://linuxize.com/post/how-to-list-installed-packages-on-debian/)

[Debian에서 sudo 구성 (arcserve.com)](https://documentation.arcserve.com/Arcserve-UDP/available/7.0/KOR/Bookshelf_Files/HTML/UDPLUG/Content/AgentforLinuxUserGuide/udpl_config_sudo_debian.htm)

[How to install sudo on a Debian minimal server - TechRepublic](https://www.techrepublic.com/article/how-to-install-sudo-on-a-debian-minimal-server/)

### Sudo 그룹에 user 추가하기

[Debian superuser rights (sudo, visudo) | Serverspace](https://serverspace.io/support/help/debian-superuser-rights-sudo-visudo/)

sudo 명령과 관련된 모든 설정은 configuration file인 /etc/sudoers에 들어있지만, 직접적으로 해당 파일에 접근해 변경하기보다 `visudo` 명령어를 통해 접근하는 걸 추천한다.

1. `usermod -a -G sudo [username]` 명령 활용
    1. [username] 사용자에게 모든 권한을 부여한다.
    2. 재 로그인이 필요하다.
2. `visudo` 명령 활용 → sudoers 파일 변경
    1. [username] 사용자에게 권한의 일부만 부여할 수 있다.
    2. ctrl + o 입력 후 엔터 클릭으로 저장하고 ctrl + x로 에디터를 빠져나올 수 있다.

### 특정 user가 포함된 groups 확인하기

아래의 명령어를 통해 확인할 수 있다.

`groups [username]`

### Sudo rules

[Sudoers Manual](https://www.sudo.ws/docs/man/1.8.15/sudoers.man/#SUDOERS_OPTIONS)

`man sudoers`

[sudoers(5) - sudo - Debian buster - Debian Manpages](https://manpages.debian.org/buster/sudo/sudoers.5.en.html)

**1. 유효하지 않은 비밀번호 입력 횟수 3회로 제한하기**

기본 설정 값이 3회이므로 변경할 것이 없다.

![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%20106.png)

**2. 유효하지 않은 비밀번호 입력 시 custom message 출력하기**

**Strings**

![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%20107.png)

**3. sudo와 관련된 input, ouput 모두 /var/log/sudo/ 폴더에 저장하기**

**Boolean Flags**

![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%20108.png)

**Strings**

![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%20109.png)

**4. TTY mode 설정**

**Boolean Flags**

![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%20110.png)

![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%20111.png)

## user42 group 생성 후 intra id user 추가하기

1. 그룹 생성하기
    
    `groupadd [groupname]`
    
2. 유저 추가하기
    
    `usermod -a -G [username]`
    

## Password policy 설정하기 - root 계정도 적용

### 시스템의 모든 계정 및 새 계정에 동일한 password policy 적용하기

- 참고) 계정 당 password policy 설정하기
    
    [chage(1) - passwd - Debian bullseye - Debian Manpages](https://manpages.debian.org/bullseye/passwd/chage.1.en.html)
    
    `chage -l [username]`명령어로 username user의 password policy와 기한 정보를 알 수 있다.
    
    참고) **root 계정의 [username]은 root다.**
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%20112.png)
    
    **30 일마다 비밀번호 만료** `sudo chage -M 30 [username]`
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%20113.png)
    
    **다음 비밀번호 변경 일은 최소 2일 후로 설정** `sudo chage -m 2 [username]`
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%20114.png)
    
    **비밀번호 만료 7일 전에 경고 메시지 띄우기** → 기본 설정이 7일
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%20115.png)
    

[Linux set default password expiry for all new users](https://www.cyberciti.biz/tips/linux-set-default-password-expiry-for-all-new-users.html)

[Force Users To Use Strong Passwords In Debian And Ubuntu](https://ostechnix.com/force-users-use-strong-passwords-debian-ubuntu/)

[How to enforce password complexity on Linux](https://www.networkworld.com/article/2726217/how-to-enforce-password-complexity-on-linux.html)

[pam_cracklib(8) - libpam-cracklib - Debian stretch - Debian Manpages](https://manpages.debian.org/stretch/libpam-cracklib/pam_cracklib.8.en.html)

- **30 일마다 비밀번호 만료** → `PASS_MAX_DAYS`
- **다음 비밀번호 변경 일은 최소 2일 후로 설정** → `PASS_MIN_DAYS`
- **비밀번호 만료 7일 전에 경고 메시지 띄우기** → `PASS_WARN_AGE`

`/etc/login.defs` configuration file의 160 ~ 162번 줄의 값 변경

![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%20116.png)

- **최소 10 자, 대문자와 숫자 각각 최소 하나 포함, 3 자 이상 동일한 글자 연속 비허용**
    
    `minlen`, `ucredit`, `dcredit`, `maxrepeat`
    
- **username 포함 비허용**
    
    `reject_username`
    
- ***(root 계정엔 적용되지 않음)* 이전 비밀번호에 포함되지 않은 글자를 최소한 7글자 포함하기**
    
    `difok`
    
    `enforce_for_root` : : root 사용자로 로그인한 후 일반 사용자 계정의 암호를 변경할 때, 암호 정책에 위배되어도 에러 메시지만 출력하고 넘어가는데 해당 설정을 하면 root 사용자도 암호 정책을 지켜야만 변경할 수 있다.
    
- 1. libpam-cracklib 모듈 설치
    
    `sudo apt install libpam-cracklib`
    
- 2. DEB-based systems의 password policy 정보는 /etc/pam.d/common-password에 있다. 이 파일을 수정한다.
    
    `sudo nano /etc/pam.d/common-password`
    
    common-password 파일이 열리면, 아래 내용을 찾아서 수정하거나 없다면 필요한 options를 추가한다.
    
    ```bash
    password required pam_cracklib.so minlen=10 ucredit=-1 dcredit=-1 maxrepeat=3 reject_username difok=7 enforce_for_root
    ```
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%20117.png)
    
    참고) [maximum credit을 다루는 options에 음수를 입력하면 그 절댓값은 반드시 포함해야 하는 최소 개수를 의미한다.](https://www.cyberciti.biz/faq/securing-passwords-libpam-cracklib-on-debian-ubuntu-linux/)
    

### **configuration file을 수정한 후엔, root 계정을 포함해 virtual machine 상의 모든 계정의 비밀번호를 변경해야 한다.**

`sudo passwd` : 현재 사용중인 계정의 비밀번호 변경

`sudo passwd [username]` : [username] 계정의 비밀번호 변경 → `sudo passwd root`

## SSH Server on Debian

[How to Enable SSH on Debian 11](https://linoxide.com/how-to-enable-ssh-on-debian/)

[sshd_config(5) - openssh-server - Debian jessie - Debian Manpages](https://manpages.debian.org/jessie/openssh-server/sshd_config.5.en.html)

### SSH package 설치하기

Debian을 설치한 직후엔 SSH가 설치되지 않은 상태이므로, 먼저 설치를 해준다.

- 1. root 계정으로 로그인한다. `su -`명령을 입력하면, 로그아웃하지 않고 root 계정을 쓸 수 있다.
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%20105.png)
    
- 2. OS를 update한다.
    
    `sudo apt update`
    
- 3. openssh-server 패키지를 설치한다.
    
    `sudo apt install openssh-server`
    
- 4. 설치 확인
    
    `sudo systemctl status ssh`
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%20118.png)
    
- `sudo systemctl start ssh` : ssh service를 실행하는 명령어
- `sudo systemctl enable ssh` : 시스템 부팅 시에 ssh service가 실행되게 지정하는 명령어

### SSH Port 변경하기

SSH 관련 설정 정보는 /etc/ssh/sshd_config configuration file에 있다.

![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%20119.png)

![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%20120.png)

### SSH를 이용해 root 계정을 사용할 수 없게 막기

![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%20121.png)

![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%20122.png)

### Firewall settings - UFW

Debian을 설치한 직후엔 UFW가 설치되지 않은 상태이므로, 먼저 설치를 해준다.

UFW는 기본적으로 incoming connections는 모두 막고 outgoing connections는 모두 허용한다.

- 1. root 계정으로 로그인한다. `su -`명령을 입력하면, 로그아웃하지 않고 root 계정을 쓸 수 있다.
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%20105.png)
    
- 2. OS를 update한다.
    
    `sudo apt update`
    
- 3. UFW를 설치한다.
    
    `sudo apt install ufw`
    
- 4. 설정한 4242 port를 허용한다.
    
    `sudo ufw allow 4242`
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%20123.png)
    
- 5. UFW를 활성화한다.
    
    `sudo ufw enable`
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%20124.png)
    
- `sudo ufw status` : UFW의 동작 상태와 rules를 확인할 수 있는 명령어.

![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%20125.png)

- `sudo systemctl enable ufw` : 시스템 부팅 시 ufw를 동작하게 하는 명령어.

## monitoring.sh 작성하기

[wall(1) - bsdutils - Debian jessie - Debian Manpages](https://manpages.debian.org/jessie/bsdutils/wall.1.en.html)

[cron - Wikipedia](https://en.wikipedia.org/wiki/Cron)

[cron(8) - cron - Debian bullseye - Debian Manpages](https://manpages.debian.org/bullseye/cron/cron.8.en.html)

<aside>
💡 **wall** 명령으로 필요한 내용을 출력하는 걸 **cron**을 이용해 10분마다 출력하게 하기

</aside>

- [Architecture](https://manpages.debian.org/stretch/coreutils/uname.1.en.html)
    
    `uname -a`
    
- [The number of physical processors](https://myshell.co.uk/blog/2012/07/how-to-determine-the-number-of-physical-cpus-on-linux/)
    
    `cat /proc/cpuinfo | grep "physical id" | sort | uniq | wc -l`
    
- [The number of virtual processors](https://myshell.co.uk/blog/2012/07/how-to-determine-the-number-of-physical-cpus-on-linux/)
    
    `cat /proc/cpuinfo | grep "^processor" | wc -l`
    
- [Memory usage](https://www.cyberciti.biz/faq/how-to-check-memory-debian-linux/)
    
    [awk 원하는 컬럼만 출력](https://zetawiki.com/wiki/Awk_%EC%9B%90%ED%95%98%EB%8A%94_%EC%BB%AC%EB%9F%BC%EB%A7%8C_%EC%B6%9C%EB%A0%A5)
    
    total : `free --mega | awk 'NR==2' | cut -f 14 -d ' '` 또는 `free --mega | awk 'NR == 2 {print $2}'`
    
    used : `free --mega | awk 'NR==2 {print $3}'`
    
- [Disk usage](https://en.wikipedia.org/wiki/Df_(Unix))
    
    utilization rate = used / (used + available)
    
    available : `df -h --total | grep total | awk '{print $3}' | tr -d 'G'`
    
    used : `df -h --total | grep total | awk '{print $2}' | tr -d 'G'`
    
    total : `df -h  --total | grep total | awk '{print $1}' | tr -d 'G'`
    
- 

## dhclient (udp) 제거하기

## virtual machine 백업하기 - snapshot

### snapshot

virtual machine의 상태를 저장하는 것으로, 이후에 이를 이용해 해당 상태로 되돌릴 수 있다.

### snapshot 확인 방법

VirtualBox Manager에서 원하는 virtual machine 이름 오른쪽의 List 버튼을 클릭하고, Snapshots를 선택한다.

snapshot을 생성하기 전에는 Current State만 존재한다.

### snapshot 생성하기

Virtual machine이 **running** 상태일 때, VirtualBox Manager에서 Take 버튼을 클릭한다.
Virtual machine이 **powered off** 상태거나 **saved** 상태일 때, virtual machine 이름 오른쪽의 List 버튼을 클릭하고, Snapshots 메뉴에 들어가서 Take 버튼을 클릭한다.

### snapshot을 이용해 되돌리기

virtual machine 이름 오른쪽의 List 버튼을 누르고 Shapshots 메뉴에 들어간 후, 원하는 snapshot을 마우스 오른쪽 버튼으로 클릭 후 Restore 메뉴를 선택한다.

## Import / Export

### Export

- 1. virtualbox manager에서 Tools의 Export를 누른다.
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%20126.png)
    
- 2. export할 virtual machine을 선택한다.
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%20127.png)
    
- 3. Appliance setting을 설정한다. (그냥 Continue)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%20128.png)
    
- 4. 원한다면 필요한 정보를 입력한 후, Export 버튼을 누른다. (더블 클릭 후 입력가능)
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%20129.png)
    

### Import

- 1. Tools → Import
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%20130.png)
    
- 2. export했던 파일 찾아서 선택하기
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%20131.png)
    
- 3. virtual machine 생성할 위치 지정 후 import
    
    ![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%20132.png)
    

how VM works?

KDump, SELinux, AppArmor

partition, encrypted partition

```c
CULTURE Uses of partitioning

Partitioning, an indispensable step in installation, consists in dividing the available space on the hard drives (each subdivision thereof being called a “partition”) according to the data to be stored on it and the use for which the computer is intended. This step also includes choosing the filesystems to be used. All of these decisions will have an influence on performance, data security, and the administration of the server.
```

[Linux Partition HOWTO](https://tldp.org/HOWTO/Partition/index.html)

LVM

apptitude vs apt

SSH and port

[ssh(1) - openssh-client - Debian bullseye - Debian Manpages](https://manpages.debian.org/bullseye/openssh-client/ssh.1.en.html)

```c
SSH is a network protocol for secure communication between a client and a server. This enables you to remotely connect to your Debian machine to perform commands, file transfer, or administrative tasks. SSH provides strong authentication using passwords and public key authentication. Once the connection is established, the data that is transmitted is encrypted.
```

how SSH works?

/etc/ssh/ssh_config, /etc/ssh/sshd_config

[What is the difference between ssh_config and sshd_config](https://prasadlinuxblog.wordpress.com/2012/09/13/what-is-the-difference-between-ssh_config-and-sshd_config/)

[Changing SSH Port: Should I modify only sshd_config, or also ssh_config?](https://serverfault.com/questions/343533/changing-ssh-port-should-i-modify-only-sshd-config-or-also-ssh-config)

UFW firewall

`For CentOS, you have to use UFW instead of the default firewall. To install it, you will probably need DNF.` → DNF

[How to Enable SSH on Debian 11 (linoxide.com)](https://linoxide.com/how-to-enable-ssh-on-debian/)

sudo

Linux user group and associated commands

iSCSI SCSI sda

[SCSI - Wikipedia](https://en.wikipedia.org/wiki/SCSI)

[What is the meaning of `SCSI3 (0,0,0)` in Partition disks during Ubuntu installation?](https://askubuntu.com/questions/1062335/what-is-the-meaning-of-scsi3-0-0-0-in-partition-disks-during-ubuntu-installa)

파티션 지정한 크기만큼 생성되지 않고, 조금씩 작게 생성되는 이유? → 기본 단위가 메가바이트여서.

partition type - primary, logical

[Difference Between Primary Partition and Logical Partition | Compare the Difference Between Similar Terms](https://www.differencebetween.com/difference-between-primary-partition-and-vs-logical-partition/)

partition location - beginning, end

file system

![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%20133.png)

각각의 의미

![Untitled](born2beroot%20991e755a6ccf4ca58516019422404b62/Untitled%2033.png)

root, swap, home? 

volume, logical volume

GRUB, boot loader

[BootLoader](https://wiki.debian.org/BootLoader)

lsblk

apt, apt-get

[Chapter 8. The Debian package management tools](https://www.debian.org/doc/manuals/debian-faq/pkgtools.en.html#apt-get)

apt 사용 시 WARNING: apt does not have a stable CLI interface. Use with caution in scripts. 에러 발생 이유

etc/passwd 파일

daemon in linux

port forwarding

usermod -a vs usermod -a -G and usermod -g

/etc/login.defs

PAM(Pluggable Authentication Modules), libpam-cracklib

DEB-based system

physical processor virtual processor

---

참고 사이트

[Oracle VM VirtualBox](https://www.virtualbox.org/)

[Virtualization - Oracle VM VirtualBox](https://www.virtualbox.org/wiki/Virtualization)

[Virtual machine - Wikipedia](https://en.wikipedia.org/wiki/Virtual_machine#System_virtual_machines)

[VirtualBox - Wikipedia](https://en.wikipedia.org/wiki/VirtualBox#VirtualBox_Disk_Image)

[VHD (file format) - Wikipedia](https://en.wikipedia.org/wiki/VHD_(file_format))

[VMDK - Wikipedia](https://en.wikipedia.org/wiki/VMDK)

[4.2. Installing, Step by Step](https://debian-handbook.info/browse/stable/sect.installation-steps.html)

[](https://linuxize.com/post/how-to-list-installed-packages-on-debian/)

[](https://linuxize.com/post/how-to-list-users-in-linux/)

[](https://linuxize.com/post/etc-passwd-file/)

[Gecos field - Wikipedia](https://en.wikipedia.org/wiki/Gecos_field)

[sudo](https://wiki.debian.org/sudo/)

[Debian에서 sudo 구성](https://documentation.arcserve.com/Arcserve-UDP/available/7.0/KOR/Bookshelf_Files/HTML/UDPLUG/Content/AgentforLinuxUserGuide/udpl_config_sudo_debian.htm)

[How to install sudo on a Debian minimal server](https://www.techrepublic.com/article/how-to-install-sudo-on-a-debian-minimal-server/)

[Limiting root access with sudo, part 1](https://www.techrepublic.com/article/limiting-root-access-with-sudo-part-1/)

[Debian superuser rights (sudo, visudo) | Serverspace](https://serverspace.io/support/help/debian-superuser-rights-sudo-visudo/)

[sudoers(5) - sudo - Debian buster - Debian Manpages](https://manpages.debian.org/buster/sudo/sudoers.5.en.html)

[](https://linuxize.com/post/how-to-create-groups-in-linux/)

[Linux chage Command - Change Password Expire Date](https://linuxtect.com/linux-chage-command-change-password-expire-date/)

[chage(1) - passwd - Debian bullseye - Debian Manpages](https://manpages.debian.org/bullseye/passwd/chage.1.en.html)

[Linux set default password expiry for all new users](https://www.cyberciti.biz/tips/linux-set-default-password-expiry-for-all-new-users.html)

[Force Users To Use Strong Passwords In Debian And Ubuntu](https://ostechnix.com/force-users-use-strong-passwords-debian-ubuntu/)

[How to force users to use secure passwords on Ubuntu/Debian Linux](https://www.cyberciti.biz/faq/securing-passwords-libpam-cracklib-on-debian-ubuntu-linux/)

[How to enforce password complexity on Linux](https://www.networkworld.com/article/2726217/how-to-enforce-password-complexity-on-linux.html)

[pam_cracklib(8) - libpam-cracklib - Debian stretch - Debian Manpages](https://manpages.debian.org/stretch/libpam-cracklib/pam_cracklib.8.en.html)

[How to Enable SSH on Debian 11](https://linoxide.com/how-to-enable-ssh-on-debian/)

[ssh 를 22번이 아닌 다른 포트 사용](https://www.lesstif.com/lpt/ssh-22-20776114.html)

[sshd_config(5) - openssh-server - Debian jessie - Debian Manpages](https://manpages.debian.org/jessie/openssh-server/sshd_config.5.en.html)

[Categorized List of HOWTOs](https://tldp.org/HOWTO/HOWTO-INDEX/categories.html)

[ssh(1) - openssh-client - Debian bullseye - Debian Manpages](https://manpages.debian.org/bullseye/openssh-client/ssh.1.en.html)

[wall(1) - bsdutils - Debian jessie - Debian Manpages](https://manpages.debian.org/jessie/bsdutils/wall.1.en.html)

[uname(1) - coreutils - Debian stretch - Debian Manpages](https://manpages.debian.org/stretch/coreutils/uname.1.en.html)

[awk 원하는 컬럼만 출력](https://zetawiki.com/wiki/Awk_%EC%9B%90%ED%95%98%EB%8A%94_%EC%BB%AC%EB%9F%BC%EB%A7%8C_%EC%B6%9C%EB%A0%A5)

[df invocation (GNU Coreutils 9.0)](https://www.gnu.org/software/coreutils/manual/html_node/df-invocation.html#df-invocation)

[df (Unix) - Wikipedia](https://en.wikipedia.org/wiki/Df_(Unix))