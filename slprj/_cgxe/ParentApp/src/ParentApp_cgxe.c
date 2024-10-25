/* Include files */

#include "ParentApp_cgxe.h"
#include "m_tCAoFCyNXuiliD9y4OuwTB.h"
#include "m_r6d06wCYakWyxELBslgYXE.h"

unsigned int cgxe_ParentApp_method_dispatcher(SimStruct* S, int_T method, void
  * data)
{
  if (ssGetChecksum0(S) == 2871132753 &&
      ssGetChecksum1(S) == 887078781 &&
      ssGetChecksum2(S) == 3019167137 &&
      ssGetChecksum3(S) == 2758171411) {
    method_dispatcher_tCAoFCyNXuiliD9y4OuwTB(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 4206048568 &&
      ssGetChecksum1(S) == 2422059978 &&
      ssGetChecksum2(S) == 3998251609 &&
      ssGetChecksum3(S) == 1860332016) {
    method_dispatcher_r6d06wCYakWyxELBslgYXE(S, method, data);
    return 1;
  }

  return 0;
}
