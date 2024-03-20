# IoT_projects

## ✔️ Smart Door Lock
### : 라즈베리파이를 활용한 도어락 프로그램

- 개요 : 도어락 회로를 구성하여 라즈베리파이를 통해 작동시키기
- 사용 기술 : `Python`, `RaspberryPi`
- 관련 교과목 : IoT 응용
- 역할 : 회로 설계 및 코드 구현
- 기간 : 2023년 5월 23일 ~ 2023년 6월 12일
- 프로젝트 설명
  
 IoT 응용 수업에서 라즈베리파이를 이용하여 도어락 기능을 구현하는 프로젝트를 진행하였습니다. 프로젝트의 목표는 키패드에 패스워드를 입력하고 맞을 경우 피에로 부저에서 소리가 나면서 서보 모터가 180도 회전 후 0도로 돌아오는 기능을 만드는 것이었습니다. 저는 회로 설계와 구현을 하는 역할을 맡았습니다. 라즈베리파이와 회로를 연결하고 작동을 시켜 도어락 기능을 구현하는데에 성공하였습니다.

 그러나 프로젝트 진행 중, 휴대폰과 라즈베리파이 간의 블루투스 통신 설정에서 어려움을 겪었습니다. 블루투스 통신 프로토콜에 대한 이해가 부족해서인지 여러 차례 시도하였지만 결국 문제 해결에 실패하였습니다. 이러한 어려움을 극복하기 위해 블루투스 대신 SMTP 프로토콜을 활용하여 데이터를 메일로 전송하는 방법으로 접근 방식을 찾아보았습니다. 결국 기간 내에 구현해내지 못하였지만, 프로토콜에 대해 추가적인 공부를 하면서 통신 프로토콜에 대한 이해도를 높일 수 있었습니다.

▶️ 회로 구성

  ![1111111](https://github.com/RosaDamascena/IoT_projects/assets/95911613/05e5fd7b-e6a8-41e8-ac67-e1fd4ed90a26)
  ![캡처](https://github.com/RosaDamascena/IoT_projects/assets/95911613/9390bd36-3d7e-4474-9262-9b69c22421f9)
 <img width="1378" alt="회로" src="https://github.com/RosaDamascena/IoT_projects/assets/95911613/0dcf7031-c571-40db-b905-85799c877dc3">


▶️ 시연 결과

<img width="391" alt="keypad" src="https://github.com/RosaDamascena/IoT_projects/assets/95911613/c40d380e-e85c-4501-8f53-16c719a50303">
<img width="377" alt="input_key" src="https://github.com/RosaDamascena/IoT_projects/assets/95911613/49f428e5-2c75-41d2-ac5d-0c8b0e3dabc2">
