
#include "star.h"
#include "Tols.h"
using namespace std;
int main() {

	system("chcp 1251");

	int num; cin >> num;




	YaScheduleApp* app = new YaScheduleApp(num);

	bool flag = true;
	int choice;
	while (flag) {
		Tols::showMenu();
		std::cout << "������� ������� ������: ";
		std::cin >> choice;
		int numfulm;
		switch (choice) {
		case 1:
			app->showSchedule(num);
			break;
		case 2:
			std::cout << "�����";
			std::cin >> numfulm;

			break;
		case 3:
			flag = false;
			break;
		}

	}
	return 0;

}