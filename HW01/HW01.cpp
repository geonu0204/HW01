#include <iostream>
using namespace std;

void setPotion(int count, int* p_HPPotion, int* p_MPPotion) {
    *p_HPPotion = count;
    *p_MPPotion = count;
}

int main()
{
    const int SIZE = 5;
    int stat[SIZE] = { 0 }; // 0:HP 1:MP 2:공격력 3:방어력

    while (1) {
        cout << "HP와 MP를 입력해주세요: ";
        cin >> stat[0] >> stat[1];

        if (stat[0] > 50 && stat[1] > 50) {
            break;
        }

        cout << "HP나 MP의 값이 너무 작습니다. 다시 입력해주세요." << endl;
    }

    while (1) {
        cout << "공격력과 방어력을 입력해주세요: ";
        cin >> stat[2] >> stat[3];

        if (stat[2] > 0 && stat[3] > 0) {
            break;
        }

        cout << "공격력이나 방어력의 값이 너무 작습니다. 다시 입력해주세요." << endl;
    }

    int choice = 0;
    int HPPotion = 0;
    int MPPotion = 0;

    setPotion(5, &HPPotion, &MPPotion);

    cout << "* 포션이 지급되었습니다. (HP, MP 포션 각 5개)" << endl;

    while (1) {

        cout << "==============================\n" << endl;
        cout << "<스탯 관리 시스템>\n" << endl;
        cout << "1. HP UP\n" << endl;
        cout << "2. MP UP\n" << endl;
        cout << "3. 공격력 UP\n" << endl;
        cout << "4. 방어력 UP\n" << endl;
        cout << "5. 현재 능력치\n" << endl;
        cout << "6. Level UP\n" << endl;
        cout << "0. 나가기\n" << endl;

        cout << "번호를 선택해주세요: ";
        cin >> choice;

        if (choice == 0) {
            cout << "프로그램을 종료합니다." << endl;
            break;
        }

        switch (choice) {

        case 1: // HP
            if (HPPotion <= 0) {
                cout << "포션이 부족합니다." << endl;
                break;
            }

            stat[0] += 20;
            HPPotion--;

            cout << "* HP가 20 증가되었습니다. 포션이 1개 차감됩니다." << endl;
            cout << "현재 HP: " << stat[0] << endl;
            cout << "남은 포션 수: " << HPPotion << endl;
            break;

        case 2: // MP
            if (MPPotion <= 0) {
                cout << "포션이 부족합니다." << endl;
                break;
            }

            stat[1] += 20;
            MPPotion--;

            cout << "* MP가 20 증가되었습니다. 포션이 1개 차감됩니다." << endl;
            cout << "현재 MP: " << stat[1] << endl;
            cout << "남은 포션 수: " << MPPotion << endl;
            break;

        case 3: // 공격력
            stat[2] *= 2;

            cout << "* 공격력이 2배로 증가되었습니다." << endl;
            cout << "현재 공격력: " << stat[2] << endl;
            break;

        case 4: // 방어력
            stat[3] *= 2;

            cout << "* 방어력이 2배로 증가되었습니다." << endl;
            cout << "현재 방어력: " << stat[3] << endl;
            break;

        case 5: // 현재 능력치
            cout << "* HP : " << stat[0]
                << ", MP : " << stat[1]
                << ", 공격력 : " << stat[2]
                << ", 방어력 : " << stat[3]
                << ", 레벨 : " << stat[4] << endl;
            break;

        case 6: // 레벨업
            HPPotion++;
            MPPotion++;
            stat[4]++;

            cout << "레벨업! " << "레벨 " << stat[4] << " 달성" << endl;
            cout << "* 레벨업 보상으로 HP/MP 포션이 지급됩니다." << endl;
            cout << "남은 HP/MP 포션 수 : " << HPPotion << "/" << MPPotion << endl;
            break;

        default:
            cout << "다시 입력해주세요." << endl;
        }
    }

    return 0;
}