#ifndef INTERVIEW_SET_ZERO
#define INTERVIEW_SET_ZERO

/**
 * Set entire row/column to zero if there is a zero.
 *
 * Time complexity: O(m*n)
 * Space complexity: O(m+n)
 */
void setZero(int **matrix, size_t m, size_t n) 
{
	// If martix[i][j] = 0, then martix[i][] = 0 and matrix[][j] = 0
	
	// We construct two indicators to log if a row/col is already set to zero

	bool isZeroRow[m]; // One can not initialize it by = {true};
	bool isZeroCol[n]; // because the length of it is variable-based

	memset(isZeroRow, 0, sizeof(bool) * m);
	memset(isZeroCol, 0, sizeof(bool) * n);

	for(size_t i = 0; i < m; i++) {
		for(size_t j = 0; j < n; j++) {
			if (matrix[i][j] == 0) { // if there is a zero, clear entire row
				isZeroRow[i] = true;
				isZeroCol[j] = true;
			}
		}
	}

	for(size_t i = 0; i < m; i++) {
		if(isZeroRow[i]) {
			memset(matrix[i],0, sizeof(int) * n);
		}
	}

	for(size_t j = 0; j < n; j++) {
		if(isZeroCol[j]) {
			for(size_t i = 0; i < m; i++) {
				matrix[i][j] = 0;
			}
		}
	}

}

#endif
