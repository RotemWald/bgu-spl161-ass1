#include "../include/cybersecurity.h"

CyberSecurity::CyberSecurity(CyberDNS& server) : cyber_DNS_(server) {
}

void CyberSecurity::LoadNetwork() {
	LoadComputers();
	LoadWires();
}

void CyberSecurity::LoadComputers() {
	using boost::property_tree::ptree;
	ptree pt;

	read_xml("./computers.xml", pt);

	BOOST_FOREACH(ptree::value_type &v, pt.get_child("")) {
		 std::string name = v.second.get_child("name").data();
		 std::string os =  v.second.get_child("os").data();

		 std::cout << "Adding to server: " << name << std::endl;

		 CyberPC* pc = new CyberPC(os, name);
		 cyber_DNS_.AddPC(*pc);

		 std::cout << name << " connected to server" << std::endl;
	}
}

void CyberSecurity::LoadWires() {
	using boost::property_tree::ptree;
	ptree pt;

	read_xml("./network.xml", pt);

	BOOST_FOREACH(ptree::value_type &v, pt.get_child("")) {
		 std::string computer1 = v.second.get_child("pointA").data();
		 std::string computer2 =  v.second.get_child("pointB").data();

		 std::cout << "Connecting " << computer1 << " to " << computer2 << std::endl;

		 cyber_DNS_.GetCyberPC(computer1).AddConnection(computer2);
		 std::cout << "\t" << computer1 << " now connected to " << computer2 << std::endl;

		 cyber_DNS_.GetCyberPC(computer2).AddConnection(computer1);
		 std::cout << "\t" << computer2 << " now connected to " << computer1 << std::endl;
	}
}

void CyberSecurity::RunSimulation() {
	int day = 0;
	int termination_time = 0;
	bool decleardTermination = false;

	using boost::property_tree::ptree;
	ptree pt;

	read_xml("./events.xml", pt);

	BOOST_FOREACH(ptree::value_type &v, pt.get_child("")) {
		std:: cout << "Day : " << day << std::endl;

		if (v.first == "hack" && !decleardTermination) {
			std::string computer = v.second.get_child("computer").data();
			std::string wormName =  v.second.get_child("wormName").data();
			int wormDormancy = std::atoi(v.second.get_child("wormDormancy").data().c_str());
			std::string wormOs =  v.second.get_child("wormOs").data();

			std::cout << "\t" << "Hack occurred on " << computer << std::endl;

			CyberWorm* cyber_worm = new CyberWorm(wormOs, wormName, wormDormancy);
			cyber_DNS_.GetCyberPC(computer).Infect(*cyber_worm);
		}

		else if (v.first == "clock-in" && !decleardTermination) {
			std::string name = v.second.get_child("name").data();
			int workTime =  std::atoi(v.second.get_child("workTime").data().c_str());
			int restTime = std::atoi(v.second.get_child("restTime").data().c_str());
			int efficiency =  std::atoi(v.second.get_child("efficiency").data().c_str());
			
			CyberExpert* cyber_expert = new CyberExpert(name, workTime, restTime, efficiency);
			cyber_DNS_.AddExpert(cyber_expert);

			std::cout << "\t" << "Clock-In: " << name << " began working" <<std::endl;
		}

		else if (v.first == "termination" && !decleardTermination) {
			std::string time = v.second.get_child("time").data();
			termination_time = std::atoi(v.second.get_child("time").data().c_str());
			decleardTermination=true;
		}

		cyber_DNS_.RunRutine();
		day++;
	}

	for (int i = day; i <= termination_time; i++) {
		std:: cout << "Day : " << day << std::endl;

		cyber_DNS_.RunRutine();
		day++;
	}
}

int main(int argc, char **argv) {
	CyberDNS cyber_DNS;
	CyberSecurity cyber_security(cyber_DNS);

	cyber_security.LoadNetwork();
	cyber_security.RunSimulation();
}
