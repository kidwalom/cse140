
#define a A[i+k*m] 
#define b A[j+k*m]
#define c C[i+j*m]

void sgemm( int m, int n, float *A, float *C )
{
  __builtin_prefetch(&A);
  __builtin_prefetch(&C);

  for( int j = 0; j < m; j++ )
    for( int k = 0; k < n; k++ )
      for( int i = 0; i < m; i++ )
        c += a*b;
}
