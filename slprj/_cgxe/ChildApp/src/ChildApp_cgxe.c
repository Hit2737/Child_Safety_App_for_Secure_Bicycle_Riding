/* Include files */

#include "ChildApp_cgxe.h"
#include "m_fVlsMLmdzYAX6SQIZ1SASG.h"
#include "m_blSUn4QnJNLfWyYmFDGX2.h"
#include "m_Ypj5Jn8N33o3OLpRVCU3p.h"
#include "m_JYafLD391rVjYJYcOtHmWG.h"
#include "m_Vey3QZKPPVzA79ZKkJbj3D.h"
#include "m_ovoTD6Rpo9A66H7u0ZZ2HH.h"

unsigned int cgxe_ChildApp_method_dispatcher(SimStruct* S, int_T method, void
  * data)
{
  if (ssGetChecksum0(S) == 347937350 &&
      ssGetChecksum1(S) == 1460979762 &&
      ssGetChecksum2(S) == 3640040636 &&
      ssGetChecksum3(S) == 3655889136) {
    method_dispatcher_fVlsMLmdzYAX6SQIZ1SASG(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 2002085996 &&
      ssGetChecksum1(S) == 1024576321 &&
      ssGetChecksum2(S) == 2014206729 &&
      ssGetChecksum3(S) == 2385633598) {
    method_dispatcher_blSUn4QnJNLfWyYmFDGX2(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 2207911699 &&
      ssGetChecksum1(S) == 3552240136 &&
      ssGetChecksum2(S) == 682922085 &&
      ssGetChecksum3(S) == 2506753311) {
    method_dispatcher_Ypj5Jn8N33o3OLpRVCU3p(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 2322836994 &&
      ssGetChecksum1(S) == 1846064845 &&
      ssGetChecksum2(S) == 3518152846 &&
      ssGetChecksum3(S) == 2412948684) {
    method_dispatcher_JYafLD391rVjYJYcOtHmWG(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 3303928983 &&
      ssGetChecksum1(S) == 3141673938 &&
      ssGetChecksum2(S) == 2723886985 &&
      ssGetChecksum3(S) == 1957248087) {
    method_dispatcher_Vey3QZKPPVzA79ZKkJbj3D(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 3314667035 &&
      ssGetChecksum1(S) == 3295405573 &&
      ssGetChecksum2(S) == 1353369979 &&
      ssGetChecksum3(S) == 3268045778) {
    method_dispatcher_ovoTD6Rpo9A66H7u0ZZ2HH(S, method, data);
    return 1;
  }

  return 0;
}
