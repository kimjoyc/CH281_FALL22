#include <hw3.1.h>
#include <MyPotential.h>
#include <MyCosine.h>

std::complex<double> MyPotential::eval(const std::complex<double> r)
{
  /* implement */
  std::complex<double> r1=pow(r,2);
  std::complex<double> r2=pow(r,6);

  return std::conj(r1)/(r1* std::conj(r1)) - std::conj(r2)/(r2*std::conj(r2));
}

std::complex<double> MyCosine::eval(const std::complex<double> r)
{
  /* implement */
  return cos(r);
}


/********************************/
#include <stdio.h>
#include <float.h>
#include <hw3.1.h>

double firstDerivative(Derivable& d, const double r)
{
  /* implement */
  const double h = 1.0e-6;
  const std::complex<double> z=1i;
  return imag(d.eval(r+z*h))/h;

}
