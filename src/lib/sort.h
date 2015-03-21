#ifndef __INTERVIEW_SORT_H__
#define __INTERVIEW_SORT_H__

#include <vector>

template <typename T>
/**
 * Swap two item in a vector
 */
bool swap(std::vector<T>& v, size_t i, size_t j)
{

  if (v.size() <= j || i >= j) {
    return false;
  }

  T tmp = v[i];
  v[i] = v[j];
  v[j] = tmp;

  return true;
}

template <typename T>
/**
 * Partition function for Quick Sort
 */
size_t partition(std::vector<T>& v, size_t i, size_t j)
{
  T pivot = v[(i + j) / 2];
	size_t lowBound = i;
	size_t highBound = j;

  while(i <= j) {
    while(v[i] < pivot) { // Left side should less than pivot
      i++;
			if (i == highBound) break;
    }
    while(v[j] > pivot) { // Right side should larger than pivot
      j--;
			if (j == lowBound) break;
    }
    if (i <= j) { // v[i] > pivot > v[j]
      swap(v, i, j);
      if(j < highBound) i++;
      if(j > lowBound) j--;
    }
  }
  return i;
}

template <typename T>
/**
 * Sort a vector using Quick Sort
 */
void quickSort(std::vector<T>& v, size_t i, size_t j)
{
  if (v.size() <= j || i >= j) return;

  size_t pivotPos = partition(v, i, j);
  quickSort(v, i, pivotPos - 1);
  quickSort(v, pivotPos, j);
}

#endif
