#include <stdio.h>

float kappa0 = 1;
float alpha0 = 1;
float beta0 = 1;
float mu0 = 0.05;

float mu;
float kappa;

/**
 *  Maintain a list of up to n samples
 *  And keep track of their average whenever one is added using
 *  add_datum(new_data_point).
 */
#define MAX_DATA 200
float samples[MAX_DATA];        // data points in memory
int d_n = 0;                    // # of data points entered
int s_n = 0;                    // # of samples in memory
float samples_total = 0;        // um of all samples
float mean = 0;                 // linearly weighted average of samples
void add_datum(float datum)
{
  if( d_n < MAX_DATA ) {
    samples[d_n++] = datum;
    samples_total += datum;
    s_n = d_n;
  } else {
    samples_total -= samples[d_n % MAX_DATA];
    samples[d_n++ % MAX_DATA] = datum;
    samples_total += datum;
    s_n = MAX_DATA;
  }
  mean = samples_total / (float)s_n;
}

/**
 *  An implementation from Sec 3.3 of https://www.cs.ubc.ca/~murphyk/Papers/bayesGauss.pdf
 */
float _mu() {
  float mu_n = (kappa0 * mu0) + ((float)s_n * mean);
  mu_n /= (kappa0 + (float)s_n);
  return mu_n;
}

float _kappa() {
  return kappa0 + (float)s_n;
}

void process_datum(float datum)
{
  add_datum(datum);
  mu = _mu();
  kappa = _kappa();
}

int main()
{
  for( int k=0; k<100; k++ )
  {
    process_datum(0.02);
  }
  process_datum(1);
  printf("%f\n", mu);
  return 0;
}
