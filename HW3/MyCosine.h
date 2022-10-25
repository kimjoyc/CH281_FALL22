#if !defined MYCOSINE__H
#define MYCOSINE_H
#include <hw3.1.h>

// virtual complex<double> eval(const std::complex<double> coord) = 0;


class MyCosine:public Derivable
{
  /* implement */
  public:
  std::complex<double> eval(const std::complex<double> r);

};


#endif
