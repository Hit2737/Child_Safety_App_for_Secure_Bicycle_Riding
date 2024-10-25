/* Include files */

#include "Gyro_cgxe.h"
#include "m_W3c0jUQLrkthkBTev0jd9D.h"

unsigned int cgxe_Gyro_method_dispatcher(SimStruct* S, int_T method, void* data)
{
  if (ssGetChecksum0(S) == 2239543533 &&
      ssGetChecksum1(S) == 62279425 &&
      ssGetChecksum2(S) == 2029902993 &&
      ssGetChecksum3(S) == 2691859786) {
    method_dispatcher_W3c0jUQLrkthkBTev0jd9D(S, method, data);
    return 1;
  }

  return 0;
}
