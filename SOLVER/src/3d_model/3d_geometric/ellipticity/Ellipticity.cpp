// Ellipticity.cpp
// created by Kuangdai on 4-Jun-2016 
// ellipticity

#include "Ellipticity.h"
#include <sstream>
#include "XMath.h"

double Ellipticity::getDeltaR(double r, double theta, double phi, double rElemCenter) const {
    if (r < tinyDouble) {
        return 0.;
    }
    double f = XMath::getFlattening(r);
    double b = pow(1. - f, 2. / 3.) * r;
    double a = b / (1. - f);
    double tmp = pow(a * cos(theta), 2.) + pow(b * sin(theta), 2.);
    return a * b / sqrt(tmp) - r;
}

// bool Ellipticity::getNablaDeltaR(double r, double theta, double phi, double rElemCenter,
//     double &deltaR_r, double &deltaR_theta, double &deltaR_phi) const {
//     double tmp = pow(mA * cos(theta), 2.) + pow(mB * sin(theta), 2.);    
//     deltaR_r = (mA * mB / sqrt(tmp) - mR) / mR;
//     deltaR_theta = mA * mB * (mA * mA - mB * mB) * cos(theta) * sin(theta) / mR / pow(tmp, 1.5);
//     deltaR_phi = 0.;
//     return true;
// }

std::string Ellipticity::verbose() const {
    std::stringstream ss;
    ss << "\n======================= 3D Geometric =======================" << std::endl;
    ss << "  Model Name           =   Ellipticity" << std::endl;
    ss << "  Scope                =   Global" << std::endl;
    if (XMath::getFlattening() == 0.)
        ss << "  Inverse Flattening   =   " << "Infinity" << std::endl;
    else
        ss << "  Inverse Flattening   =   " << 1. / XMath::getFlattening() << std::endl;
    ss << "======================= 3D Geometric =======================\n" << std::endl;
    return ss.str();
}
