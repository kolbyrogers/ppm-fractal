#include "ActionData.h"

ActionData::ActionData(std::istream &is, std::ostream &os)
    : mIS(is), mOS(os), mDone(false), mGridPointer(0), mColorTable(16) {
  Color color1(0, 255, 0);
  Color color2(255, 0, 255);
  mColorTable.insertGradient(color1, color2, 0, 15);
}
ActionData::~ActionData() {
  if (mGridPointer != 0) {
    delete mGridPointer;
  }
}
std::istream &ActionData::getIS() { return mIS; }
std::ostream &ActionData::getOS() { return mOS; }
PPM &ActionData::getInputImage1() { return mInputImage1; }
PPM &ActionData::getInputImage2() { return mInputImage2; }
PPM &ActionData::getOutputImage() { return mOutputImage; }
bool ActionData::getDone() const { return mDone; }
NumberGrid &ActionData::getGrid() { return *mGridPointer; }
ColorTable &ActionData::getTable() { return mColorTable; }

void ActionData::setDone() { mDone = true; }
void ActionData::setGrid(NumberGrid *grid) {
  if (mGridPointer != 0) {
    delete mGridPointer;
  }
  mGridPointer = grid;
}
