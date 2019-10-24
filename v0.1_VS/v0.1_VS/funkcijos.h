#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "struktura.h"
#include <vector>
#include <math.h> 
#include <random>
#include <chrono>

#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H


std::vector<int> To_Hex(unsigned long long int suma);
std::vector<unsigned long long int> Nuskaitymas_failas_2(std::string pav);
unsigned long long int Nuskaitymas_failas(std::string pav);
void spausdinimas(std::vector<std::vector<int>>hex2);
int randomNum(int a, int b);

void randomChars(std::string pav);
int trecia_uzd(std::string pav);

#endif //FUNKCIJOS_H