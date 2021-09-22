#include "ActionData.h"

ActionData::ActionData(std::istream &is, std::ostream &os)
    : mIS(is), mOS(os), mDone(false)
{
}
std::istream &ActionData::getIS()
{
    return mIS;
}
std::ostream &ActionData::getOS()
{
    return mOS;
}
PPM &ActionData::getInputImage1()
{
    return mInputImage1;
}
PPM &ActionData::getInputImage2()
{
    return mInputImage2;
}
PPM &ActionData::getOutputImage()
{
    return mOutputImage;
}
bool ActionData::getDone() const
{
    return mDone;
}
void ActionData::setDone()
{
    mDone = true;
}
