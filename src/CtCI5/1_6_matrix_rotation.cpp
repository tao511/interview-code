#ifndef INTERVIEW_MATRIX_ROTATION
#define INTERVIEW_MATRIX_ROTATION

/** Rotate 90 degree does NOT equals to transpose
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
 *  The rotation happens in the following way:
 *  (i,j) => (j, n-i) => (n-i,n-j) => (n-j,i) => (i,j)
 *
 *  REMEMBER, `n` here is the maximum index, NOT THE SIZE
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
