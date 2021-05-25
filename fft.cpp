#include "fft.h"



void fft(double *in, fftw_complex *out)
{

    fftw_plan plan = fftw_plan_dft_r2c_1d(256, in, out, FFTW_PRESERVE_INPUT);
    fftw_execute(plan);
    fftw_destroy_plan(plan);
    fftw_cleanup();
}

void ifft(fftw_complex *in, double *out)
{
    fftw_plan plan = fftw_plan_dft_c2r_1d(256, in, out, FFTW_PRESERVE_INPUT);
    fftw_execute(plan);
    fftw_destroy_plan(plan);
    fftw_cleanup();
    for(int i = 0; i < 256; i++)
    {
        out[i] /=256;
    }
}