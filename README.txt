# 2024 System Programming Project
  본 문서는 인하대학교 시스템프로그래밍 교과목에서 수행한 프로젝트를 설명합니다.
  정적 및 동적 라이브러리 링킹에 관한 구현 내용을 포함합니다.

### Library Description
  addover.c : 사용자로부터 두 정수를 받아 합을 구했을 때 overflow가 발생하는지 detect!
  subover.c : 사용자로부터 두 정수를 받아 차를 구했을 때 overflow가 발생하는지 detect!
    -> libmy.a & libmine.so : 두 정수의 합과 차를 구했을 때 overflow를 감지하는 라이브러리
    
### Instructions to build and test the library (linux code)
  1. static library (libmy.a)
    $ gcc -c addover.c subover.c
    $ ar -r libmy.a addover.o subover.o
    $ gcc -c main.c
    $ gcc -static main.o -L. -lmy -o static
    $ ./static //테스트 파일 실행. 아래 코드부터는 static 테스트 파일 사용법
    Put two integers to add.
    >>2147483647 1 //더할 두 정수 입력
    overflow! //오버플로우 발생
    Put two integers to sub.
    >>-2147483648 1 //뺄 두 정수 입력
    overflow! //오버플로우 발생

  2. shared library (libmine.so)
    $ gcc -c fpic addover.c subover.c
    $ gcc shared -o libmine.so addover.o subover.o
    $ gcc main.c -L. -lmine -o dynamic
    $ export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
    $ ./dynamic //테스트 파일 실행. 아래 코드부터는 dynamic 테스트 파일 사용법
    Put two integers to add.
    >>2147483647 1 //더할 두 정수 입력
    overflow! //오버플로우 발생
    Put two integers to sub.
    >>-2147483648 1 //뺄 두 정수 입력
    overflow! //오버플로우 발생

3. runtime linking
  $ gcc -rdynamic -o runtimelink runtimelinking.c -ldl
  $ ./runtimelink
  ... //테스트 파일 사용법 위와 동일

### Example of usage
캡처 사진 인하대 오픈소스 사이트 참고
