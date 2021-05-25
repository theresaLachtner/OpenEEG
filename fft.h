#include <iostream>
#include <complex>
#include <cmath>
#include <iterator>
#include <fftw3.h>

void fft(double *in, fftw_complex *out);
void ifft(fftw_complex *in, double *out);
