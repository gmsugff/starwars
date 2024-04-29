#include "star.h"
#include "Tols.h"
#define CPPHTTPLIB_OPENSSL_SUPPORT
using namespace std;
int main() {

	system("chcp 1251");
	int num; cin >> num;

	
		Tols* ahp=new Tols();
	 YaScheduleApp* app=new YaScheduleApp(num);
	bool flag = true;
	int choice;
	while (flag) {
		ahp->showMenu();

		std::cout << "¬ведите варинат ответа: ";
		std::cin >> choice;
			
		
		switch (choice) {
		case 1:
		
			
			app->getCityCode(num);
			ahp->showSchedule(num);
			break;
		case 2:
			flag = false;
			break;
		}

	}
	return 0;

}