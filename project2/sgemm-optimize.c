void sgemm( int m, int n, float *A, float *C )
{
  for( int k = 0; k < m; k++ ){
    for( int i = 0; i < n; i++ ){
      for( int j = 0; j < m; j++ ){
        C[i+j*m] += A[i+k*m] * A[j+k*m];
      }
    }
  }
}
