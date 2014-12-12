
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
/*this is the SSE intrincix library that gives 4 instuctions at time 4X speed [possibly]*/
#include "xmmintrin.h"
/* transposes and pad the matrix to an offest of four so as to be able to do calulation much easier */
float* transpad(int m, int n, float *inputfloat)
{
	/* if true return then next factor of 4 [e.g. if its 4*5 it becomes 4*8
	//(namtrix size not offeset of 4) else 0*/
	
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
	free (returnfloat);
}
void sgemm( int m, int n, float *A, float *C )
{
	/* creates the padded matrixes for a and c */
	float *padded_A = transpad(m, n, A);
	float *padded_C = transpad(m,n,C);
/*	//try this if all else fails 
	//dont ry this might make slower on different computers
	 __builtin_prefetch(&A);
	 __builtin_prefetch(&C);*/
	  for( int j = 0; j < m; j++ )
	  {
	    for( int k = 0; k < n; k++ )
	    {
	      for( int i = 0; i < m; i++ )
	      {
	//going to change this multiplier to be the padded c(column major) = padded a (colum major)  *padded a (row major) 
	        	c+=a*b;
	    	}
		}
	}

	free (padded_A);
	free (padded_C);
}
/*		float tmp = b;
	  for( int j = 0; j < m; j++ )
	  {
	        	c+=a*tmp;
	}
	free (padded_A);
	free (padded_A);
	
} */


