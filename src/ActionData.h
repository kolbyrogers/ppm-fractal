#ifndef _ACTIONDATA_H_
#define _ACTIONDATA_H_

#include <iostream>
#include "PPM.h"

class ActionData
{
    // Data Members:
    std::istream &mIS;
    std::ostream &mOS;
    PPM mInputImage1;
    PPM mInputImage2;
    PPM mOutputImage;
    bool mDone;

    // Methods:
    ActionData(std::istream &is, std::ostream &os);
    std::istream &getIS();
    std::ostream &getOS();
    PPM &getInputImage1();
    PPM &getInputImage2();
    PPM &getOutputImage();
    bool getDone() const;
    void setDone();
};

#endif
