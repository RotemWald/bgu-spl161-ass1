#ifndef INCLUDE_CYBERSECURITY_H_
#define INCLUDE_CYBERSECURITY_H_

#include <cstdlib>
#include <iostream>
#include <string>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>

#include "../include/cyberdns.h"
#include "../include/cyberexpert.h"

class CyberSecurity {
private:
	CyberDNS& cyber_DNS_;
public:
	CyberSecurity(CyberDNS& server);
	void LoadNetwork();
	void LoadComputers();
	void LoadWires();
	void RunSimulation();
};

#endif
