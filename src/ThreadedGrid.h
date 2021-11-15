#ifndef THREADEDGRID_H
#define THREADEDGRID_H

#include "NumberGrid.h"
#include "ThreadedVector.h"

class ThreadedGrid : public NumberGrid {
protected:
  ThreadedVector<int> mTaskList;

public:
  ThreadedGrid();
  ThreadedGrid(const int &height, const int &width);
  virtual ~ThreadedGrid();
  virtual void calculateAllNumbers();
  virtual void worker();
};

#endif /* THREADEDGRID_H */
