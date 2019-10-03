#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "struktura.h"
#include <vector>
#include <math.h> 

#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H


std::vector<int>To_Hex(std::vector<int> rezultatas);
std::vector<int> To_Dec(std::vector<data> enigma, std::vector<char> failas);
std::vector<data> Nuskaitymas_data();
std::vector<char> Nuskaitymas_failas(std::string pav);

#endif //FUNKCIJOS_H