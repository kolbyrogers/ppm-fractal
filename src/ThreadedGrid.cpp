#include "ThreadedGrid.h"
#include <thread>

ThreadedGrid::ThreadedGrid() : NumberGrid() {}
ThreadedGrid::ThreadedGrid(const int &height, const int &width)
    : NumberGrid(height, width) {}
ThreadedGrid::~ThreadedGrid() {}

void ThreadedGrid::calculateAllNumbers() {
  std::vector<std::thread> threads;
  unsigned int max_cores = 4;

  for (int row = 0; row < getHeight(); row++) {
    this->mTaskList.push_back(row);
  }

  for (unsigned int i = 0; i < max_cores; i++) {
    threads.push_back(std::thread(&ThreadedGrid::worker, this));
  }

  for (unsigned int i = 0; i < threads.size(); i++) {
    threads[i].join();
  }
}
void ThreadedGrid::worker() {
  std::vector<int> workerTasks;

  while (mTaskList.size() > 0) {
    workerTasks.resize(0);
    mTaskList.pop_back(workerTasks, 1);

    if (workerTasks.size() > 0) {
      int row = workerTasks[0];
      for (int col = 0; col < getWidth(); col++) {
        setNumber(row, col, calculateNumber(row, col));
      }
    }
  }
}
