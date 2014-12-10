
/*define all the calculations of the different index stores
and the different acceses */
#define a A[i+k*m] 
#define b A[j+k*m]
#define c C[i+j*m]
/* defing a row major tranpose macro 
defines a colum major transpose macro */
#define ROWMAJOR(i,j,m,n) (i*n)+j
#define COLMAJOR(i,j,m,n) (j*m)+i
/* include useful library */
#include <string.h>
#include "xmmintrin.h"
/* transposes and pad the matrix to an offest of four so as to be able to do calulation much easier */
float* transpad(int m, int n, float *inputfloat)
{
	/* if true return 4(namtrix size not offeset of 4) else 0*/
	int mpad = (m & ~0x03) + ((m & 0x03) ? 4:0);
	int npad = (n & ~0x03) + ((n & 0x03) ? 4:0);

	float *returnfloat = (float *)malloc(mpad *npad * sizeof(float));
	memset((void *) returnfloat, 0, mpad*npad* sizeof(float));
	/*transposes it*/
	for (int i =0; i <m; i++){
		for (int j=0; j<n; j++){
			returnfloat[ROWMAJOR(i,j,mpad,npad)] =inputfloat[COLMAJOR(i,j,m,n)];
		}
	}
	return returnfloat;
}
void sgemm( int m, int n, float *A, float *C )
{
	float *padded_A = transpad(m, n, A);
/*	//try this if all else fails
	 __builtin_prefetch(&A);
	 __builtin_prefetch(&C); */

	  for( int j = 0; j < m; j++ )
	  {
	    for( int k = 0; k < n; k++ )
	    {
	      for( int i = 0; i < m; i++ )
	      {
	        	c+=a*b;
	    	}
		}
	}
	free (padded_A);
}