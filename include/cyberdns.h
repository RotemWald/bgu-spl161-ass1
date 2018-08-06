#ifndef CYBERDNS_H
#define CYBERDNS_H

#include <iostream>
#include <string>
#include <map>
#include <vector>

#include "../include/cyberpc.h"

class CyberExpert; //Forward decleration
class CyberPC; //Forward deceleration

class CyberDNS
{
private:
	std::map<const std::string, CyberPC &> cyber_DNS_;	//Hash map to hold PC names and pointers
	std::vector<CyberExpert *> Admins; //Vector to hold CyberExpert pointers

public:
	CyberDNS();
	virtual ~CyberDNS();
	void AddPC(CyberPC & cyber_pc_);
	CyberPC & GetCyberPC(const std::string & cyber_pc_name) const;
	std::vector<std::string> GetCyberPCList(); 		// Return list of PC's as a vector of strings.

	CyberExpert* GetCyberExpert(int i);
	const std::vector<CyberExpert*>& GetCyberExpertPointersList();
	void AddExpert(CyberExpert * cyber_expert_);
	void RunRutine();
};

#endif
