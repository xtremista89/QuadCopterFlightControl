#include "RunningAverage.h"

template <typename T> T RunningAverage<T>::Zero = (T)0;


template <typename T> RunningAverage<T>::RunningAverage(int n)
{
  Size = n;
  dataArray = new T[Size];
  Clear();
}

template <typename T> RunningAverage<T>::~RunningAverage()
{
  delete dataArray;
}

template <typename T> int RunningAverage<T>::getSize()
{
  return Size;
}

// resets all counters
template <typename T> void RunningAverage<T>::Clear()
{
  Count = 0;
  PrevAverageValue = Zero;
  _idx = 0;
  SUM = Zero;
  for (int i = 0; i < Size; i++) dataArray[i] = Zero; // needed to keep addValue simple
}

// adds a new value to the data-set
template <typename T> void RunningAverage<T>::Add(T f)
{
  SUM -= dataArray[_idx];
  dataArray[_idx] = f;
  SUM += dataArray[_idx];
  _idx++;
  if (_idx == Size) _idx = 0;  // faster than %
  if (Count < Size) Count++;
}

// returns the average of the data-set added so far
template <typename T> T RunningAverage<T>::GetAverage() const
{
  if (Count == 0) return Zero; // NaN ?  math.h
  return SUM / Count;
}

// fill the average with a value
// the param number determines how often value is added (weight)
// number should preferably be between 1 and size
template <typename T> void RunningAverage<T>::FillValue(T value, int number)
{
  Clear();
  for (int i = 0; i < number; i++)
  {
    Add(value);
  }
}
