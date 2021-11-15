#ifndef THREADEDVECTOR_H
#define THREADEDVECTOR_H
#include <mutex>
#include <vector>

template <typename T> class ThreadedVector {
public:
  typedef typename std::vector<T>::size_type size_type;

  ThreadedVector();
  ThreadedVector(size_type n);

  void back(T &value);
  void back(std::vector<T> &values, const size_type n);

  void clear();

  bool empty();

  const T &operator[](const size_type n);

  void pop_back();
  void pop_back(const size_type n);
  void pop_back(std::vector<T> &values, const size_type n);

  void push_back(const T &value);
  void push_back(const std::vector<T> &values);

  void resize(size_type n);
  void resize(size_type n, const T &value);

  size_type size();

protected:
  std::mutex mReadLock;
  std::mutex mWriteLock;
  std::vector<T> mData;

private:
};

template <typename T> ThreadedVector<T>::ThreadedVector() {}

template <typename T>
ThreadedVector<T>::ThreadedVector(size_type n) : mData(n) {}

template <typename T> void ThreadedVector<T>::back(T &value) {
  mReadLock.lock();

  value = mData.back();

  mReadLock.unlock();
}

template <typename T>
void ThreadedVector<T>::back(std::vector<T> &values, const size_type n) {
  mReadLock.lock();

  for (size_type i = 0; i < n && i < mData.size(); i++) {
    values.push_back(mData[mData.size() - i - 1]);
  }

  mReadLock.unlock();
}

template <typename T> void ThreadedVector<T>::clear() {
  mWriteLock.lock();
  mReadLock.lock();

  mData.clear();

  mReadLock.unlock();
  mWriteLock.unlock();
}

template <typename T> bool ThreadedVector<T>::empty() {
  mReadLock.lock();

  bool value = mData.empty();

  mReadLock.unlock();
  return value;
}

template <typename T>
const T &ThreadedVector<T>::operator[](const size_type n) {
  mReadLock.lock();

  T &value = mData[n];

  mReadLock.unlock();

  return value;
}

template <typename T> void ThreadedVector<T>::pop_back() {
  mWriteLock.lock();
  mReadLock.lock();

  mData.pop_back();

  mReadLock.unlock();
  mWriteLock.unlock();
}

template <typename T> void ThreadedVector<T>::pop_back(const size_type n) {
  mWriteLock.lock();
  mReadLock.lock();

  for (size_type i = 0; i < n && mData.size() > 0; i++) {
    mData.pop_back();
  }

  mReadLock.unlock();
  mWriteLock.unlock();
}

template <typename T>
void ThreadedVector<T>::pop_back(std::vector<T> &values, const size_type n) {
  mWriteLock.lock();
  mReadLock.lock();

  for (size_type i = 0; i < n && mData.size() > 0; i++) {
    values.push_back(mData.back());
    mData.pop_back();
  }

  mReadLock.unlock();
  mWriteLock.unlock();
}

template <typename T> void ThreadedVector<T>::push_back(const T &value) {
  mWriteLock.lock();
  mReadLock.lock();

  mData.push_back(value);

  mReadLock.unlock();
  mWriteLock.unlock();
}

template <typename T>
void ThreadedVector<T>::push_back(const std::vector<T> &values) {
  mWriteLock.lock();
  mReadLock.lock();

  for (size_type i = 0; i < values.size(); i++) {
    mData.push_back(values[i]);
  }

  mReadLock.unlock();
  mWriteLock.unlock();
}

template <typename T> void ThreadedVector<T>::resize(size_type n) {
  mWriteLock.lock();
  mReadLock.lock();

  mData.resize(n);

  mReadLock.unlock();
  mWriteLock.unlock();
}

template <typename T>
void ThreadedVector<T>::resize(size_type n, const T &value) {
  mWriteLock.lock();
  mReadLock.lock();

  mData.resize(n, value);

  mReadLock.unlock();
  mWriteLock.unlock();
}

template <typename T>
typename ThreadedVector<T>::size_type ThreadedVector<T>::size() {
  mReadLock.lock();

  size_type value = mData.size();

  mReadLock.unlock();

  return value;
}

#endif /* THREADEDVECTOR_H */
