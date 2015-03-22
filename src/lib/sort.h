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

template <typename T>
/**
 * Bottom-up heapify
 * For array with index starting at 0,
 * node x's children are: 2(x-1) and 2(x-1) + 1
 *					parent is: (x-1) / 2
 */
void swim(std::vector<T>& v, size_t pos)
{
}

template <typename T>
/**
 * Top-down heapify
 * For array with index starting at 0,
 * node x's children are: 2x + 1 and 2x + 2 
 *					parent is: (x-1) / 2
 */
void sink(std::vector<T>& v, size_t pos, size_t highBound)
{
	while(2 * pos + 1 < highBound) { // check if left child is in range
		size_t rightChildPos = 2 * pos + 1;
		// Choose the largest one
		if (rightChildPos + 1 < highBound &&
			v[rightChildPos] < v[rightChildPos+1]){
			rightChildPos++;
		}
		if(v[pos] < v[rightChildPos]){ // parent is less than children
			swap(v, pos, rightChildPos); // switch and check subheap
			pos = rightChildPos;
		} else { // if this subheap is valid, exit
			break;
		}
	}
}

template <typename T>
/**
 * Heap Sort
 * Frist heapify every sub-heap, and then repeat
 * removing maximum; re-heapify
 */
void heapSort(std::vector<T>& v)
{
	size_t highBound = v.size();
	// heapify every sub-heap 
	for(size_t pos = highBound/2 - 1; ; pos--) {
		sink(v, pos, highBound);
		if (pos == 0) break; // size_t always larger than 0
	}

	// Actual sorting
	while (highBound > 1) { // we do not need to move last element
		swap(v, 0, --highBound); // remove max
		sink(v, 0, highBound); // heapify [0, highBound]
	}

}

#endif
