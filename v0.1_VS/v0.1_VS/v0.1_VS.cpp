// v0.1_VS.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <chrono>
#include "funkcijos.h"

int main() {

	
	std::cout << "Pasirinkite ivesties buda:" << std::endl;
	std::cout << "1)Ranka" << std::endl;
	std::cout << "2)Is failo kaip viena eilute" << std::endl;
	std::cout << "3)Is failo po viena eilute" << std::endl;
	std::cout << "4)Generuoti string poras (visi simboliai skirtingi)" << std::endl;
	std::cout << "5)Patikrinti ar yra sutampanciu poru (3 uzd)" << std::endl;
	std::cout << "6)Generuoti string poras (tik paskutinis simbolis skirtingas)" << std::endl;
	std::cout << "7)Hash procentinis skirtingumas bit lygmeny" << std::endl;
	std::string pasirinkimas;
	std::cin >> pasirinkimas;

start:
	std::string pav;
	unsigned long long int failas =0;
	std::vector<int>hex; //Konvertuoja i HEX
	std::vector<std::vector<int>>hex2;
	std::vector<unsigned long long int> suma;//Nuskaitymui po eilute



	if (pasirinkimas == "1")
	{
		std::cin >> pav;
		std::cout << std::endl;
		for (auto i = 0; i < pav.size(); i++)
		{
			int x = int(pav[i]);
			if (x<0)
			{
				x = (x*-1) + 200;
			}

			failas = failas + (x*(i+1));
			//std::cout << failas;
		}
		hex = To_Hex(failas);
		for (int i = 0; i < 32; i++)
		{
			std::cout << std::hex << hex[i];
			//std::cout << hex[i] << std::endl;
			//std::cout << failas;
		}
		std::cout << std::endl;
		goto start;
	}
	else if (pasirinkimas == "2")
	{

		std::cin >> pav;		
		failas = Nuskaitymas_failas(pav);
		hex = To_Hex(failas);
		std::cout << std::endl;
		for (int i = 0; i < 32; i++)
		{
			std::cout << std::hex << hex[i];
			//std::cout  << hex[i];
		}
		std::cout<<std::endl;
	}
	else if (pasirinkimas == "3")
	{
		std::cin >> pav;
		suma = Nuskaitymas_failas_2(pav);

		auto start1 = std::chrono::high_resolution_clock::now();
		for (auto i = 0; i < suma.size(); i++)
		{
			hex = To_Hex(suma[i]);
			hex2.push_back(hex);
		}
		auto finish1 = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsed1 = finish1 - start1;
		std::cout << "Programos vykdymo laikas: "<< elapsed1.count() << " s\n";

		spausdinimas(hex2);

	}
	else if (pasirinkimas == "4")//Random generavimas
	{
		std::cout << "Iveskite generuojamo failo pavadinima: ";
		std::cin >> pav;
		randomChars(pav);
		
	} 
	else if (pasirinkimas == "5")
	{
		std::cout << "Iveskite sugeneruoto failo pavadinima: ";
		std::cin >> pav;
		int kiek_pasikartojo = trecia_uzd(pav);
		std::cout << std::endl;
		std::cout<<"Pasikartojo: " << kiek_pasikartojo<<std::endl;
	}
	else if (pasirinkimas == "6")//Random generavimas
	{
		std::cout << "Iveskite generuojamo failo pavadinima: ";
		std::cin >> pav;
		randomChars2(pav);

	}
	else if (pasirinkimas == "7")
	{
		std::cout << "Iveskite sugeneruoto failo pavadinima: ";
		std::cin >> pav;
		std::vector<double>rezultatai;
		rezultatai = ketvirta_uzd(pav);
		double maxi, mini,average;
		maxi = max(rezultatai);
		mini = min(rezultatai);
		average = avg(rezultatai);

		std::cout << "min sutampa: " << mini << std::endl;
		std::cout << "max sutampa: " << maxi << std::endl;
		std::cout << "vidurkis: " << average << std::endl;
	}
	else
	{
		std::cout << "Iveskite SKAICIU" << std::endl;
		goto start;
	}
	
	


	return 0;

}

