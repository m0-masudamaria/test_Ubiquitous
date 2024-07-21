#ifndef BASIC_FUNCTION_H
#define BASIC_FUNCTION_H

#include <iostream>
#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>

class BasicFunction
{
public:
	BasicFunction();
	~BasicFunction();

	double deg2rad(double deg);

	std::vector<double> vector_sum(std::vector<double> vector1, std::vector<double> vector2);
	
	std::vector<double> vector_dif(std::vector<double> vector1, std::vector<double> vector2);
	
	double vector_norm(std::vector<double> vector_1);

	bool check_rad_range(double* m_rad, short motor_num);

	short rad2goalPosition(double rad_q);

private:
};

#endif // !BASIC_FUNCTION_H
