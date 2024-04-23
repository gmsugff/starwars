#include <string>
#include "star.h"
using json = nlohmann::json;
using namespace std;
YaScheduleApp::YaScheduleApp()
{

}

YaScheduleApp::YaScheduleApp(int & num)
{
	this->num = num;


}

nlohmann::json YaScheduleApp::makeRequest(httplib::Client* client, std::string request)
{
	if (auto response = client->Get(request)) {
		if (response->status == 200) {
			return json::parse(response->body);
		}
		else {
			std::cout << "Bad request " << response->status << std::endl;
		}
	}
	return *new json;
}
string YaScheduleApp::getCityCode(int& num)
{
	std::string request = this->peopleClient;
	request += "/ people /" + num;

	std::string code = this->makeRequest(this->starClient, request)["code"].get<std::string>();
	return code;
}

 std::vector<std::vector<std::map<std::string, std::string>>> YaScheduleApp::mapStarOpen()
 {
	 std::string request = this->peopleClient;
	 request += "/people/" + num;

	 json result = this->makeRequest(this->starClient, request);

	 std::vector<std::vector<std::map<std::string, std::string>>> race;

	 for (int i = 0; i < result["segments"].size(); i++) {
		 std::map<std::string, std::string> personData;
		 personData["Name"] = result["segments"][i]["name"].get<std::string>();
		 personData["Birth Year"] = result["segments"][i]["birth_year"].get<std::string>();
		 personData["Gender"] = result["segments"][i]["gender"].get<std::string>();
		 personData["Height"] = result["segments"][i]["height"].get<std::string>();
		 personData["Mass"] = result["segments"][i]["mass"].get<std::string>();

		 std::vector<std::map<std::string, std::string>> singlePersonData;
		 singlePersonData.push_back(personData);

		 race.push_back(singlePersonData);
	 }

	 return race;
 }

 void YaScheduleApp::showSchedule( int& num)
 { 
	 std::vector <std::vector <std::map <std::string, std::string>>> schedule,
		 getCityCode(num);
	 for (int i = 0; i < schedule.size(); i++) {
		 for (int j = 0; j < schedule[i].size(); j++) {
			 std::cout << schedule[i][j][" Name"] << " ";
			 std::cout << schedule[i][j]["Birth Year"] << " ";
			 std::cout << schedule[i][j]["gender"] << " ";
			 std::cout << schedule[i][j]["height"] << " ";
			 std::cout << schedule[i][j]["mass"] << " " << endl << endl;

		 }
	 }
	 system("chcp 1251");
 }
 

