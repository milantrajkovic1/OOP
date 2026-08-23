#pragma once
#include <exception>
#include <iostream>
using namespace std;
class Vagon
{
	float masa;
	float masaTereta;
public:
	Vagon(float _masa=0.0f, float _masaTereta=0.0f);

	bool operator>(const Vagon& v)const;
	Vagon operator+(const Vagon& v)const;
	friend ostream& operator<<(ostream& izlaz, const Vagon& v);
	friend istream& operator>>(istream& ulaz, Vagon& v);
};

