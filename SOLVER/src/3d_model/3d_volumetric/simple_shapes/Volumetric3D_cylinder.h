// Volumetric3D_cylinder.h
// created by Kuangdai on 16-May-2016 
// a cylinder-shaped heterogeneity

#pragma once
#include "Volumetric3D.h"

class Volumetric3D_cylinder: public Volumetric3D {
public:
    
    void initialize(const std::vector<std::string> &params);
    
    bool get3dProperties(double r, double theta, double phi, double rElemCenter,
        double &dvpv, double &dvph, double &dvsv, double &dvsh, double &drho) const;
    
    ReferenceTypes getReferenceType() const {return mReferenceType;};
    
    std::string verbose() const;
    
    void setSource(double srcLat, double srcLon, double srcDep) {
        mSrcLat = srcLat;
        mSrcLon = srcLon;
        mSrcDep = srcDep;
    }
    
private:
    // anchor points of the cylinder
    double mD1, mD2;
    double mLat1, mLat2;
    double mLon1, mLon2;
    
    // Gaussian parameters
    double mRadius;         // radius of the cylinder
    double mHWHM_lateral;   // halfwidth at half maximum; how the perturbation fades laterally outside the cylinder
    double mHWHM_top_bot;   // halfwidth at half maximum; how the perturbation fades longitudinally outside the cylinder
    double mMaxAxis;        // value inside the cylinder
    
    // reference type
    ReferenceTypes mReferenceType;
    
    // source-centered
    bool mSourceCentered = false;
    double mSrcLat = 0.;
    double mSrcLon = 0.;
    double mSrcDep = 0.;
    
    // optional 
    bool mChangeVp = true;
    bool mChangeVs = true;
    bool mChangeRho = true;
};
