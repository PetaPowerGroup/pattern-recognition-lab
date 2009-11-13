#ifndef BASE_H
#define BASE_H

#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<valarray>
#include<list>
#include<queue>
#include<algorithm>
#include<cmath>
#include<cstdio>




typedef std::vector<double> Lagrange;
typedef  Lagrange* PLagrange;
typedef std::valarray<double> Element;
typedef Element* PElement;
typedef std::pair<PElement, int> Sample;
typedef Sample* PSample;
typedef std::vector<Sample> Samples;
typedef Samples* PSamples;
typedef std::vector<PSample>* PDSamples; 
typedef std::vector<Element> Elementi;
typedef Elementi* PElementi;
typedef std::vector<PElement> PPElementi;
typedef std::vector<PElement>* PDElementi;
typedef std::vector<int> Ypsilon;
typedef Ypsilon* PYpsilon;






#endif