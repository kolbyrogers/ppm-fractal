#include "ActionData.h"

ActionData::ActionData(std::istream &is, std::ostream &os)
    : mIS(is), mOS(os), mDone(false), mGrid(0) 
{
}
ActionData::~ActionData() {
	if (mGrid != 0){
		delete mGrid;
	}
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
NumberGrid& ActionData::getGrid(){
	return *mGrid;
} 
void ActionData::setGrid(NumberGrid *grid){
	if(mGrid != 0) {
		delete mGrid;
	}
	mGrid = grid;
}
