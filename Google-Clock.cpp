#include <iostream>
#include <cmath>

#define M_PI 3.14159265358979323846

void angle(const double Angle, double &X, double &Y)
{
    X = sin(Angle * M_PI / 180);

    //if (X < 0.0000001 && X>0)
    //   X = 0;

    Y = cos(Angle * M_PI / 180);

    //if (Y < 0.0000001 && Y>0)
    //    Y = 0;
}


int main()
{
    int hour, min, sec;

    std::cin >> hour;
    std::cin >> min;
    std::cin >> sec;

    // std::cout << hour << "\t" << min << "\t" << sec << std::endl;

    if (hour > 23)
        exit(-1);
    else if (hour >= 12 && hour <= 23)
        hour -= 12;

    if (min > 60)
        exit(-1);

    if (sec > 60)
        exit(-1);


    const int oneSixty = 360 / 60;
    const int oneSixtyHour = 360 / 12;


    double secAngle = sec;
    secAngle *= oneSixty;

    double minAngle = min;
    minAngle *= oneSixty;
    minAngle += secAngle / 60;

    double hourAngle = hour;
    hourAngle *= oneSixtyHour;
    hourAngle += minAngle / 60;

    // std::cout << hourAngle << "\t" << minAngle << "\t" << secAngle << std::endl;


    //HOUR
    double xHour{}, yHour{};

    angle(hourAngle, xHour, yHour);

    std::cout << "H\t" << hour << "\t" << hourAngle << "\t" << "X: " << xHour << "\tY: " << yHour << std::endl;

    // std::cout << "H\tX: " << xHour << "\tY: " << yHour << std::endl;


    //MIN
    double xMin{}, yMin{};

    angle(minAngle, xMin, yMin);

    std::cout << "M\t" << min << "\t" << minAngle << "\t" << "X: " << xMin << "\tY: " << yMin << std::endl;

    // std::cout << "M\tX: " << xMin << "\tY: " << yMin << std::endl;


    //SEC
    double xSec{}, ySec{};

    angle(secAngle, xSec, ySec);

    // std::cout << "S\tX: " << xSec << "\tY: " << ySec << std::endl;

    std::cout << "S\t" << sec << "\t" << secAngle << "\t" << "X: " << xSec << "\tY: " << ySec << std::endl;
}