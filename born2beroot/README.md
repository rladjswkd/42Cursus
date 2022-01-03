# VirtualBox

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

![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled.png)

Machine Folder는 이미지와 다르게 goinfre로 지정했다.

### Name

virtual machine의 이름으로, 해당 virtual machine의 파일들에 사용된다.

### Machine folder

생성할 virtual machine이 저장될 위치를 지정한다.

### Type & Version

virtual machine에서 실행할 운영체제를 지정한다.

![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%201.png)

### Memory size

virtual machine이 실행될 때 할당될 메모리 크기를 지정한다. (이후에 변경할 수 있다.)

![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%202.png)

### Hard disk

virtual machine이 사용할 가상 하드 디스크에 대한 설정을 할 수 있다.

![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%203.png)

### Hard disk file type

**VDI** : VirtualBox의 native format이며, 다른 virtualization software에선 일반적으로 지원하지 않는다. 단, 다른 virtualization software에서 사용할 수 있는 타입으로 변환하는 것은 어렵지 않다.

**VHD** : Microsoft의 hypervisor(=virtual machine system)인 Hyper-V의 native format이다.

**VMDK** : VMware를 위해 개발된 format이다.

![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%204.png)

### Storage on physical hard disk

<aside>
💡 VirtualBox는 두 타입의 disk image file을 지원한다.

</aside>

1. dynamically allocated file
    1. virtual hard disk에 데이터가 저장될 때마다 disk size를 증가시킨다. → 초기에는 용량이 작다.
2. fixed-size file
    1. 처음부터 지정한 용량의 disk image file을 생성한다. → 용량은 차지하지만, 오버헤드가 적어 상대적으로 빠르다.

![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%205.png)

### File location and size

virtual hard disk image를 저장할 위치를 지정한다.

## 생성한 virtual machine 실행하기

![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%206.png)

1. VirtualBox manager window의 왼쪽 pane, virtual machine list에서 해당 virtual machine을 더블 클릭한다.

### 생성한 virtual machine을 처음 실행할 때

![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%207.png)

실행 가능한 OS가 없는 상태이므로, OS를 설치해줘야 한다.

[운영체제](https://www.debian.org/index.ko.html)

iso 파일을 다운로드 받은 후, first start wizard에서 다운로드 받은 iso 파일을 선택하고 start 버튼을 누른다.

### OS 설치 관련

<aside>
💡 아래의 os 설치 과정에서, sda5를 생성하지 말고, sda6를 sda5로 생성하자. 마지막에 1KB짜리 sda2가 자동으로 생성된다.

</aside>

- os 설치 과정
    
    [4.2. Installing, Step by Step](https://debian-handbook.info/browse/stable/sect.installation-steps.html)
    
    1. graphical interface를 사용하면 안되고, 최소한의 서비스만 설치해야 한다고 매뉴얼에 나와있으므로, 그렇게 설치한다.
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%208.png)
    
    1. language를 English로 고른다. 한글로 설정하면 글자가 깨지는 현상이 있을 수 있다고 한다.
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%209.png)
    
    1. location을 other - asia - Korea, republic of 순서로 설정한다.
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2010.png)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2011.png)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2012.png)
    
    1. locale을 en_US.UTF-8로 설정한다.
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2013.png)
    
    1. keymap을 Korean으로 설정한다.
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2014.png)
    
    1. 매뉴얼에 host name은 인트라 아이디 + 42로 지정하라고 나와있으므로, 그렇게 설정한다.
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2015.png)
    
    1. domain name은 비워두고 넘어간다.
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2016.png)
    
    1. 매뉴얼의 strong password policy를 따라 동일한 글자가 3개 이상 반복되지 않고, 대문자와 숫자를 반드시 포함하며 최소한 10글자인 root password를 설정한다.
    → born2BEROOT로 지정.
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2017.png)
    
    1. root password 재입력.
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2018.png)
    
    1. sudo, user42 그룹에 포함시킬 사용자 계정을 만든다. Full name - Username - password - password check 순
    → gyepark, gyepark, 42seoulJJANG, 42seoulJJANG
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2019.png)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2020.png)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2021.png)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2022.png)
    
    1. 디스크 파티셔닝 - 매뉴얼의 내용과 비슷하게 구성하기 위해 수동 파티셔닝을 선택했다.
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2023.png)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2024.png)
    
    9-1. 매뉴얼 이미지의 sda생성
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2025.png)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2026.png)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2027.png)
    
    9-2. 매뉴얼 이미지의 sda1 - /boot 생성. bootable partition인 primary partition으로 지정.
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2028.png)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2029.png)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2030.png)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2031.png)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2032.png)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2033.png)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2034.png)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2035.png)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2036.png)
    
    9-3. 매뉴얼 이미지의 sda2 생성
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2037.png)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2038.png)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2039.png)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2040.png)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2041.png)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2042.png)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2043.png)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2044.png)
    
    9-3. 매뉴얼 이미지의 sda5 생성
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2045.png)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2046.png)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2047.png)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2048.png)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2049.png)
    
    9-4. encrypted partition을 생성.
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2050.png)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2051.png)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2052.png)
    
    (space로 선택 가능)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2053.png)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2054.png)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2055.png)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2056.png)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2057.png)
    
    (encrypted partition 비밀번호 설정 - encryptedlogicalPARTITION6)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2058.png)
    
    (encrypted partition 비밀번호 재입력을 하면 아래와 같은 화면이 뜬다.)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2059.png)
    
    9-5. encrypted partition에 `/`, `[swap]`, `/home`을 지정.
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2060.png)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2061.png)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2062.png)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2063.png)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2064.png)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2065.png)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2066.png)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2067.png)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2068.png)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2069.png)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2070.png)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2071.png)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2072.png)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2073.png)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2074.png)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2075.png)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2076.png)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2077.png)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2078.png)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2079.png)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2080.png)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2081.png)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2082.png)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2083.png)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2084.png)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2085.png)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2086.png)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2087.png)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2088.png)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2089.png)
    
    1. 파티셔닝 완료
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2090.png)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2091.png)
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2092.png)
    
    1. 추가 설치 미디어 확인 → skip
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2093.png)
    
    1. debian archive mirror country 선택 
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2094.png)
    
    1. debian archive mirror site 선택
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2095.png)
    
    1. HTTP proxy information 입력 → 외부에서 접근할 필요 없으므로 skip
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2096.png)
    
    1. 패키지 사용 통계 정보 전송 참여 여부 → no
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2097.png)
    
    1. predefined software 설치 여부 → 최소한의 서비스만 사용할 것이므로 선택돼있는 SSH server와 standard system utilities를 제외하곤 선택하지 않는다.
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2098.png)
    
    1. boot loader 설치 여부
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2099.png)
    
    1. boot loader를 설치할 위치 지정
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%20100.png)
    
    1. 설치 완료
    
    ![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%20101.png)
    

### OS 설치 완료 이후

![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%20102.png)

os 설치를 완료한 후엔 재부팅이 되고, 설정한 encrypted disk에 대한 비밀번호를 입력해야 한다.

![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%20103.png)

이후엔 생성한 계정으로 로그인해야 한다.

![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%20104.png)

![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%20105.png)

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

![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%20106.png)

how VM works?

KDump, SELinux, AppArmor

partition, encrypted partition

```c
CULTURE Uses of partitioning

Partitioning, an indispensable step in installation, consists in dividing the available space on the hard drives (each subdivision thereof being called a “partition”) according to the data to be stored on it and the use for which the computer is intended. This step also includes choosing the filesystems to be used. All of these decisions will have an influence on performance, data security, and the administration of the server.
```

LVM

apptitude vs apt

SSH and port

how SSH works?

what security problem does it have to connect using SSH as root

UFW firewall

`For CentOS, you have to use UFW instead of the default firewall. To install it, you will probably need DNF.` → DNF

sudo

Linux user group and associated commands

iSCSI SCSI sda

파티션 지정한 크기만큼 생성되지 않고, 조금씩 작게 생성되는 이유?

[SCSI - Wikipedia](https://en.wikipedia.org/wiki/SCSI)

[What is the meaning of `SCSI3 (0,0,0)` in Partition disks during Ubuntu installation?](https://askubuntu.com/questions/1062335/what-is-the-meaning-of-scsi3-0-0-0-in-partition-disks-during-ubuntu-installa)

partition type - primary, logical

[Difference Between Primary Partition and Logical Partition | Compare the Difference Between Similar Terms](https://www.differencebetween.com/difference-between-primary-partition-and-vs-logical-partition/)

partition location - beginning, end

file system

![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%20107.png)

각각의 의미

![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%2033.png)

root, swap, home? 

volume, logical volume

GRUB, boot loader

lsblk

---

[Oracle VM VirtualBox](https://www.virtualbox.org/)

[Oracle VM VirtualBox](https://www.virtualbox.org/)

[Virtual machine - Wikipedia](https://en.wikipedia.org/wiki/Virtual_machine#System_virtual_machines)

[VirtualBox - Wikipedia](https://en.wikipedia.org/wiki/VirtualBox#VirtualBox_Disk_Image)

[VHD (file format) - Wikipedia](https://en.wikipedia.org/wiki/VHD_(file_format))

[VMDK - Wikipedia](https://en.wikipedia.org/wiki/VMDK)

![Untitled](VirtualBox%20991e755a6ccf4ca58516019422404b62/Untitled%20108.png)