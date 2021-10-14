#ifndef _ACTIONDATA_H_
#define _ACTIONDATA_H_

#include <iostream>
#include "PPM.h"
#include "NumberGrid.h"

class ActionData
{
public:
    ActionData(std::istream &is, std::ostream &os);
	~ActionData();
	NumberGrid& getGrid();
    std::istream &getIS();
    std::ostream &getOS();
    PPM &getInputImage1();
    PPM &getInputImage2();
    PPM &getOutputImage();
    bool getDone() const;
    void setDone();
	void setGrid(NumberGrid *grid);
    
private:
    std::istream &mIS;
    std::ostream &mOS;
    PPM mInputImage1;
    PPM mInputImage2;
    PPM mOutputImage;
    bool mDone;
	NumberGrid *mGrid;
};

#endif
