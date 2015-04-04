#ifndef INTERVIEW_MATRIX_ROTATION
#define INTERVIEW_MATRIX_ROTATION

/** 
 * Rotate 90 degree does NOT equals to transpose.
 * 
 * An example is
 *  1, 2, 3, 4;
 *  5, 6, 7, 8;
 *  9,10,11,12;
 * 13,14,15,16;
 *
 * Transpose is
 *  1, 5, 9,13
 *  2, 6,10,14
 *  3, 7,11,15
 *  4, 8,12,16
 *
 * Wherease rotation is
 *  13, 9, 5, 1
 *  14,10, 6, 2
 *  15,11, 7, 3
 *  16,12, 8, 4
 *
 *  First lets mark the matrtix by its index
 *
 *  0,0 0,1 0,2 0,3
 *  1,0 1,1 1,2 1,3
 *  2,0 2,1 2,2 2,3
 *	3,0 3,1 3,2 3,3
 *
 *	The rotation of 0,0 is
 *	0,0 -> 0,3
 *	0,3 -> 3,3
 *	3,3 -> 3,0
 *	3,0 -> 0,0
 *
 *	And the rotation of 0,1 is
 *	0,1 -> 1,3
 *	1,3 -> 3,2
 *	3,2 -> 2,0
 *	2,0 -> 0,1
 *
 *  As we can see, row 0 becomes column n, column n becomes
 *  row n, row n converts to column 0, and column now is row 0.
 *
 *  Therefore, the rotation of row 0,n column 0, is:
 *
 *  (0,i) -> (i,n)
 *  (i,n) -> (n, n-i)
 *  (n, n-i) -> (n-i, 0)
 *  (n-i, 0) -> (0,i)
 *  
 *  And for row i, n-i, colum i, n-i, the definition of transform is:
 *  
 *  (i,j) => (j, n-i) => (n-i,n-j) => (n-j,i) => (i,j)
 *
 *  REMEMBER, `n` here is the maximum index, NOT THE SIZE
 *
 *	Time complexity: O(m) m is the number of elements in matrix
 *	Space complexity: O(1) in place algorithm
 *
 */
void rotation(int n, int m[][4])
{

  n = n - 1;

  for(size_t i = 0; i <= (n + 1) / 2; i++) {
    for(size_t j = i; j < n - i; j++) {
      int tmp = m[i][j];

      m[i][j] = m[n-j][i];
      m[n-j][i] = m[n-i][n-j];
      m[n-i][n-j] = m[j][n-i];
      m[j][n-i] = tmp;
    }
  }
}

#endif
