#include "stdafx.h"
#include "funkcijos.h"


std::vector<int> To_Hex(std::vector<int> rezultatas)
{
	std::vector<int>hex;
	for (int i = 0; i < 65; i++)
	{
		hex.push_back(0);
	}
	for (auto j = 0; j < rezultatas.size(); j++)
	{
		for (int i = 0; i < 65; i++)
		{
			int x;
			x = rezultatas[j] + static_cast<int>(pow(i, 2));
			hex[i] = hex[i] + x;
		}
	}
	for (int i = 0; i < 65; i++)
	{
		hex[i] = hex[i] % 16;
	}
	return hex;

}

std::vector<int> To_Dec(std::vector<data> enigma, std::vector<char> failas)
{
	std::vector<int> rezultatas;
	for (auto i = 0; i < failas.size(); i++)
	{
		for (auto j = 0; j < enigma.size(); j++)
		{
			if (failas[i] == enigma[j].x)
			{
				rezultatas.push_back(enigma[j].value);
			}
		}
	}
	return rezultatas;
}
std::vector<data> Nuskaitymas_data()
{
	std::vector<data>enigma;
	std::ifstream fd;
	fd.open("data.txt");
	
	while (!fd.eof())
	{
		data Data;
		fd >> Data.x >> Data.value;

		enigma.push_back(Data);
	}
	fd.close();
	return enigma;
}
std::vector<char> Nuskaitymas_failas(std::string pav)
{
	std::vector<char> failas;
	std::ifstream fd;
	fd.open(pav);
	while (!fd.eof())
	{
		char x;
		fd >> x;
		failas.push_back(x);
	}
	return failas;
}