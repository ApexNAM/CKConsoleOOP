#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

inline int addRandomNumber() { return rand() % 10 + 1; } // 0부터 10까지 숫자를 무작위로 배치하는 함수.

void GamePlay(); // 게임플레이 함수
void ContinueCheck(); // 다시 시작 판정 함수

bool gamePower = true; // 게임실행 조건
bool isGameEnd = false; // 게임종료 조건 

int answerNumber; // 설정한 정답 값 
int playerScore; // 플레이어 점수
int choice = 3; // 기회 값
int playerNumber; // 플레이어 선택값

int main()
{
    cout << "숫자 맟추기 게임!" << endl;
    cout << "숫자를 랜덤으로 설정합니다.\n" << endl;

    srand((unsigned)time(NULL)); 
    answerNumber = addRandomNumber(); // 무작위로 번호 생성

    while (gamePower) // 게임종료를 판정함.
    {
        GamePlay(); // 게임플레이 함수
    }
    return 0;
}

void GamePlay()
{
    cout << "기회는 " << choice << "번." << endl;
    cout << "숫자를 입력하세요 : ";
    cin >> playerNumber; // 숫자를 설정합니다.

    // 만약 플레이어가 지정한 숫자가 설정된 숫자보다 작거나 크면 판정을 해줍니다. 
    // 그리고 기회가 감소됩니다.

    if (playerNumber < answerNumber) {
        cout << "\n.. 플레이어 숫자가 설정한 숫자보다 적습니다.\n" << endl;
        choice--; // 기회 감소
    }
    else if (playerNumber > answerNumber) {
        cout << "\n.. 플레이어 숫자가 설정한 숫자보다 큽니다.\n" << endl;
        choice--; // 기회 감소
    }
    else if (playerNumber == answerNumber)
    {
        isGameEnd = true; // 게임종료 확인

        // 기회의 수에 따라 점수가 다르게 받습니다.
        switch (choice)
        {
        case 3:
            cout << "\n정답! 한방에!\n" << endl;
            playerScore += 100;
            break;
        case 2:
            cout << "\n정답! 2번만에!\n" << endl;
            playerScore += 90;
        case 1:
            cout << "\n정답! 3번만에!\n" << endl;
            playerScore += 80;
            break;
        }
    }

    // 기회가 0번이 되면 게임오버.
    if (choice == 0) {
        cout << "모두 틀렸습니다. 3번내에 맞추지 못했습니다." << endl;
        isGameEnd = true;
    }

    // 게임오버 판정시 함수 실행
    if (isGameEnd) {
        ContinueCheck();
    }
}

void ContinueCheck()
{
    bool checkYN = true; // YN이 판정되는것을 확인합니다.
    char yn;
    
    cout << "플레이어 점수 : " << playerScore << endl;
    cout << "설정된 점수 : " << answerNumber << endl;

    if (isGameEnd) {
        checkYN = true;
    }

    while (checkYN) // Y 또는 N이 입력되면 거짓으로 변경해서 비활성화 합니다.
    {
        cout << "\n다시 할 것인가요?" << endl;
        cout << "Y/N : ";

        cin >> yn; // y or n 입력

        // y : 다시 시작 (모든 설정 초기화)
        // n : 게임종료 
        if (yn == 'Y' || yn == 'y')
        {
            cout << "다시 시작합니다!\n" << endl;
            checkYN = false; // yn 확인
            playerScore = 0; // 점수 초기화
            choice = 3; // 기회 충전
            answerNumber = addRandomNumber();
            isGameEnd = false; // 게임종료 비활성화
        }
        else if (yn == 'N' || yn == 'n') {
            cout << "\n게임을 종료합니다. 플레이해주셔서 감사합니다!" << endl;
            checkYN = false; // yn 확인
            gamePower = false; // 게임 완전 종료
        }
        else {
            cout << "\n잘못 입력하셨습니다." << endl; // 잘못 입력시 판정됨 
        }
    }
}