// v0.1_VS.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include "funkcijos.h"

int main() {

	
	std::cout << "Pasirinkite ivesties buda:" << std::endl;
	std::cout << "1)Ranka" << std::endl;
	std::cout << "2)Is failo" << std::endl;
	std::string pasirinkimas;
	std::cin >> pasirinkimas;

start:
	std::string pav;
	std::vector<data>enigma;
	enigma = Nuskaitymas_data(); //Nuskaitoma koduote
	std::vector<long int> rezultatas;
	std::vector<char>failas;
	std::vector<long int>hex;



	if (pasirinkimas == "1")
	{
		std::cin >> pav;
		std::cout << std::endl;
		for (auto i = 0; i < pav.size(); i++)
		{
			failas.push_back(pav[i]);
		}
		rezultatas = To_Dec(failas);
		hex = To_Hex(rezultatas);
		for (int i = 0; i < 65; i++)
		{
			std::cout << std::hex << hex[i];
			//std::cout  << hex[i];
		}
		std::cout << std::endl;
		goto start;
	}
	else if (pasirinkimas == "2")
	{

		std::cin >> pav;		
		failas = Nuskaitymas_failas(pav);
		rezultatas = To_Dec(failas);
		hex = To_Hex(rezultatas);
		std::cout << std::endl;
		for (int i = 0; i < 65; i++)
		{
			std::cout << std::hex << hex[i];
			//std::cout  << hex[i];
		}
		std::cout<<std::endl;
	}
	else
	{
		std::cout << "Iveskite SKAICIU" << std::endl;
		goto start;
	}

	

	system("pause");
	return 0;

}

