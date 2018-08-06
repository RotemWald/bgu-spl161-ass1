#include "../include/cyberdns.h"
#include "../include/cyberexpert.h"

using namespace std;

CyberDNS::CyberDNS() : cyber_DNS_(), Admins() {
}

void CyberDNS::AddPC(CyberPC& cyber_pc_) {
	cyber_DNS_.insert(pair<const std::string, CyberPC &>(cyber_pc_.getName(), cyber_pc_));
}

CyberPC& CyberDNS::GetCyberPC(const std::string& cyber_pc_name) const {
	return cyber_DNS_.at(cyber_pc_name);
}

std::vector<std::string> CyberDNS::GetCyberPCList() {
	std::vector<string> vector;

	for (std::map<const std::string, CyberPC &>::iterator it=cyber_DNS_.begin(); it!=cyber_DNS_.end(); ++it) {
    	vector.push_back(it->first);
    }

    return vector;
}

CyberExpert* CyberDNS::GetCyberExpert(int i) {
	return Admins.at(i);
}

const std::vector<CyberExpert*>& CyberDNS::GetCyberExpertPointersList() {
	return Admins;
}

void CyberDNS::AddExpert(CyberExpert* cyber_expert) {
	Admins.push_back(cyber_expert);
}

CyberDNS::~CyberDNS() {
	for (std::map<const std::string, CyberPC &>::iterator it=cyber_DNS_.begin(); it!=cyber_DNS_.end(); ++it) {
    		delete &(it->second);
	}

	for (std::vector<CyberExpert*>::iterator it=Admins.begin(); it!=Admins.end(); it++) {
		delete (*it);
	}
}

void CyberDNS::RunRutine() {
	std::vector<std::string> pclist = this->GetCyberPCList();
	std::vector<std::string>::reverse_iterator pcit = pclist.rbegin();

	for (std::vector<CyberExpert*>::iterator it=Admins.begin(); it!=Admins.end(); it++) {
		if ((*it)->isReadytoStart()) {
			for (int w=0; w<(*it)->getExpertefficiency(); ++w) {
				if (pcit<pclist.rend()) {
					(**it).Clean(this->GetCyberPC(*pcit));
					pcit++;
				}
			}
		}

		(*it)->endDay();
	}

	for (std::map<const std::string, CyberPC &>::reverse_iterator it=cyber_DNS_.rbegin(); it!=cyber_DNS_.rend(); ++it)
	{
		(it->second).Run(*this);
	}
}
