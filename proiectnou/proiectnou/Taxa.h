#pragma once
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
#pragma warning(disable:4996)

class Taxa  /// clasa abstracta
{
public:
	virtual double tva() = 0; // metoda virtuala pura
};