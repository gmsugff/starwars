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

	 std::vector<std::map<std::string, std::string>> race{};
	 std::map<std::string, std::string>Name;
	 std::map<std::string, std::string>BirthYear;
	 std::map<std::string, std::string>Gender;
	 std::map<std::string, std::string>Height;
	 std::map<std::string, std::string>Mass;
	 for (int i = 0; i < result["segments"].size(); i++) {
		
	 Name["Name"] = result["segments"][i]["name"].get<std::string>();
	BirthYear["Birth Year"] = result["segments"][i]["birth_year"].get<std::string>();
	Gender["Gender"] = result["segments"][i]["gender"].get<std::string>();
	Height["Height"] = result["segments"][i]["height"].get<std::string>();
	Mass["Mass"] = result["segments"][i]["mass"].get<std::string>();

	race.push_back(Name);
	race.push_back(BirthYear);
	race.push_back(Gender);
	race.push_back(Height);
	race.push_back(Mass);
		 this->schedule.push_back(race);
	 }
		 Name.clear();
		 BirthYear.clear();
		 Gender.clear();
		 Height.clear();
		 Mass.clear();
		 race.clear();
		 request.clear();
		 return this->schedule;
 }


 

