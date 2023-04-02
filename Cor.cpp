#include "Cor.hpp"

#include <cmath>
#include <algorithm>

using namespace std;

Cor::Cor(): r(0.0f), g(0.0f), b(0.0f){}

Cor::Cor(float l): r(l), g(l), b(l){}

Cor::Cor(float r, float g, float b): r(r), g(g), b(b){}

Cor::~Cor(){}

void Cor::clamp(float mini, float maxi)
{
	r = max(mini, min(maxi, r));
	g = max(mini, min(maxi, g));
	b = max(mini, min(maxi, b));
}

void Cor::correcaoGama(float exposicao, float gama)
{
	r = std::pow(r * exposicao, gama);
	g = std::pow(g * exposicao, gama);
	b = std::pow(b * exposicao, gama);
}

Cor& Cor::operator =(const Cor& c)
{
	r = c.r;
	g = c.g;
	b = c.b;
	return *this;
}

Cor& Cor::operator +=(const Cor& c)
{
	r += c.r;
	g += c.g;
	b += c.b;
	return *this;
}

Cor& Cor::operator *=(const Cor& c)
{
	r *= c.r;
	g *= c.g;
	b *= c.b;
	return *this;
}

Cor& Cor::operator *=(float f)
{
	r *= f;
	g *= f;
	b *= f;
	return *this;
}