#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

inline int addRandomNumber() { return rand() % 10 + 1; } // 0���� 10���� ���ڸ� �������� ��ġ�ϴ� �Լ�.

void GamePlay(); // �����÷��� �Լ�
void ContinueCheck(); // �ٽ� ���� ���� �Լ�

bool gamePower = true; // ���ӽ��� ����
bool isGameEnd = false; // �������� ���� 

int answerNumber; // ������ ���� �� 
int playerScore; // �÷��̾� ����
int choice = 3; // ��ȸ ��
int playerNumber; // �÷��̾� ���ð�

int main()
{
    cout << "���� ���߱� ����!" << endl;
    cout << "���ڸ� �������� �����մϴ�.\n" << endl;

    srand((unsigned)time(NULL)); 
    answerNumber = addRandomNumber(); // �������� ��ȣ ����

    while (gamePower) // �������Ḧ ������.
    {
        GamePlay(); // �����÷��� �Լ�
    }
    return 0;
}

void GamePlay()
{
    cout << "��ȸ�� " << choice << "��." << endl;
    cout << "���ڸ� �Է��ϼ��� : ";
    cin >> playerNumber; // ���ڸ� �����մϴ�.

    // ���� �÷��̾ ������ ���ڰ� ������ ���ں��� �۰ų� ũ�� ������ ���ݴϴ�. 
    // �׸��� ��ȸ�� ���ҵ˴ϴ�.

    if (playerNumber < answerNumber) {
        cout << "\n.. �÷��̾� ���ڰ� ������ ���ں��� �����ϴ�.\n" << endl;
        choice--; // ��ȸ ����
    }
    else if (playerNumber > answerNumber) {
        cout << "\n.. �÷��̾� ���ڰ� ������ ���ں��� Ů�ϴ�.\n" << endl;
        choice--; // ��ȸ ����
    }
    else if (playerNumber == answerNumber)
    {
        isGameEnd = true; // �������� Ȯ��

        // ��ȸ�� ���� ���� ������ �ٸ��� �޽��ϴ�.
        switch (choice)
        {
        case 3:
            cout << "\n����! �ѹ濡!\n" << endl;
            playerScore += 100;
            break;
        case 2:
            cout << "\n����! 2������!\n" << endl;
            playerScore += 90;
        case 1:
            cout << "\n����! 3������!\n" << endl;
            playerScore += 80;
            break;
        }
    }

    // ��ȸ�� 0���� �Ǹ� ���ӿ���.
    if (choice == 0) {
        cout << "��� Ʋ�Ƚ��ϴ�. 3������ ������ ���߽��ϴ�." << endl;
        isGameEnd = true;
    }

    // ���ӿ��� ������ �Լ� ����
    if (isGameEnd) {
        ContinueCheck();
    }
}

void ContinueCheck()
{
    bool checkYN = true; // YN�� �����Ǵ°��� Ȯ���մϴ�.
    char yn;
    
    cout << "�÷��̾� ���� : " << playerScore << endl;
    cout << "������ ���� : " << answerNumber << endl;

    if (isGameEnd) {
        checkYN = true;
    }

    while (checkYN) // Y �Ǵ� N�� �ԷµǸ� �������� �����ؼ� ��Ȱ��ȭ �մϴ�.
    {
        cout << "\n�ٽ� �� ���ΰ���?" << endl;
        cout << "Y/N : ";

        cin >> yn; // y or n �Է�

        // y : �ٽ� ���� (��� ���� �ʱ�ȭ)
        // n : �������� 
        if (yn == 'Y' || yn == 'y')
        {
            cout << "�ٽ� �����մϴ�!\n" << endl;
            checkYN = false; // yn Ȯ��
            playerScore = 0; // ���� �ʱ�ȭ
            choice = 3; // ��ȸ ����
            answerNumber = addRandomNumber();
            isGameEnd = false; // �������� ��Ȱ��ȭ
        }
        else if (yn == 'N' || yn == 'n') {
            cout << "\n������ �����մϴ�. �÷������ּż� �����մϴ�!" << endl;
            checkYN = false; // yn Ȯ��
            gamePower = false; // ���� ���� ����
        }
        else {
            cout << "\n�߸� �Է��ϼ̽��ϴ�." << endl; // �߸� �Է½� ������ 
        }
    }
}