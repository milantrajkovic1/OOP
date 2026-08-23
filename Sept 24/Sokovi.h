#pragma once
#include <iostream>
using namespace std;
class Sokovi
{
	char* naziv;
	float zapremina;
	int procenat;
public:
	Sokovi();
	Sokovi(const char* _naziv, float _zapremina, int _procenat);
	Sokovi(const Sokovi& s);
	~Sokovi();
	void zauzmiMem(const char*, float, int);

	Sokovi& operator=(const Sokovi& s);
	friend ostream& operator<<(ostream& izlaz, const Sokovi& s);
	friend istream& operator>>(istream& ulaz, Sokovi& s);

	bool operator>(Sokovi& s);
	bool operator==(Sokovi& s);
	float operator+(float desni);
	float operator+(const Sokovi& s);
};

