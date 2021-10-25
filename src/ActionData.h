#ifndef _ACTIONDATA_H_
#define _ACTIONDATA_H_

#include "NumberGrid.h"
#include "PPM.h"
#include <iostream>

class ActionData {
public:
  ActionData(std::istream &is, std::ostream &os);
  ~ActionData();
  NumberGrid &getGrid();
  std::istream &getIS();
  std::ostream &getOS();
  PPM &getInputImage1();
  PPM &getInputImage2();
  PPM &getOutputImage();
  bool getDone() const;
  void setDone();
  void setGrid(NumberGrid *grid);
  ColorTable &getTable();

private:
  std::istream &mIS;
  std::ostream &mOS;
  PPM mInputImage1;
  PPM mInputImage2;
  PPM mOutputImage;
  bool mDone;
  NumberGrid *mGridPointer;
  ColorTable mColorTable;
};

#endif
