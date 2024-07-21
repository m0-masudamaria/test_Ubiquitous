#include <iostream>
#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>
#include "basic_function.h"

using namespace std;

BasicFunction::BasicFunction()
{

}

BasicFunction::~BasicFunction()
{

}

double BasicFunction::deg2rad(double deg)
{
    return deg * M_PI / 180.0;
}

std::vector<double> BasicFunction::vector_sum(std::vector<double> vector1, std::vector<double> vector2)
{
    std::vector<double> sum;

    if (vector1.size() != vector2.size())
    {
        std::cout << "size is NOT same" << std::endl;
        return sum;
    }

    for (unsigned int i = 0; i < vector1.size(); i++)
    {
        double sum_tmp;
        sum_tmp = vector1[i] + vector2[i];
        sum.push_back(sum_tmp);
    }

    return sum;
}

std::vector<double> BasicFunction::vector_dif(std::vector<double> vector1, std::vector<double> vector2)
{
    std::vector<double> dif;

    if (vector1.size() != vector2.size())
    {
        std::cout << "size is NOT same" << std::endl;

        return dif;
    }

    for (unsigned int i = 0; i < vector1.size(); i++)
    {
        double dif_tmp;
        dif_tmp = vector1[i] - vector2[i];
        dif.push_back(dif_tmp);
    }

    return dif;
}

double BasicFunction::vector_norm(std::vector<double> vector_1)
{
    if (vector_1.size() != 3)
    {
        std::cout << "vector size is NOT 3!" << std::endl;
        return 1000000000.0;
    }

    double sum_squared = 0.0;
    for (unsigned int i = 0; i < vector_1.size(); i++)
    {
        sum_squared += vector_1[i] * vector_1[i];
    }

    return sqrt(sum_squared);
}

bool BasicFunction::check_rad_range(double* m_rad, short motor_num)
{
    //モータの角度が範囲に収まっている必要がある
    double rad_range[5][2] = { {-150.0, 150.0},
                               {-100.0, 100.0},
                               {-142.0, 137.0},
                               {-100.0, 100.0},
                               {-45.0 ,  35.0} };

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            rad_range[i][j] *= M_PI / 180.0;
        }
    }

    while (*m_rad < rad_range[motor_num][0])
    {
        *m_rad += 2.0 * M_PI;
    }

    while (rad_range[motor_num][1] < *m_rad)
    {
        *m_rad -= 2.0 * M_PI;
    }

    if (rad_range[motor_num][0] <= *m_rad && *m_rad < rad_range[motor_num][1])
    {
        return true;
    }
    else
    {
        return false;
    }
}

short BasicFunction::rad2goalPosition(double rad_q)
{
    rad_q = rad_q * 180.0 / M_PI;

    //std::cout << "deg: " << rad_q << std::endl;
    rad_q += 150.0;

    short signal;
    //signal = (rad_q - 0) * (1024 - 0) / (300 - 0) + 0;
    signal = (short)(rad_q * 512.0 / 150.0);

    //std::cout << "signal: " << signal << std::endl;

    return signal;
}