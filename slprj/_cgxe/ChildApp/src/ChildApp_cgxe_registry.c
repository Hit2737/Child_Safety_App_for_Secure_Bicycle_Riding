#define S_FUNCTION_LEVEL               2
#define S_FUNCTION_NAME                ChildApp_cgxe
#include "simstruc.h"
#include "ChildApp_cgxe.h"
#define MDL_START

static void mdlStart(SimStruct* S)
{
  unsigned int success;
  success = cgxe_ChildApp_method_dispatcher(S, SS_CALL_MDL_START, NULL);
  if (!success) {
    /* error */
    mexPrintf("ERROR: Failed to dispatch s-function method!\n");
  }
}

#define MDL_INITIALIZE_CONDITIONS

static void mdlInitializeConditions(SimStruct *S)
{
  mexPrintf("ERROR: Calling model mdlInitializeConditions method directly.\n");
}

#define MDL_UPDATE

static void mdlUpdate(SimStruct *S, int_T tid)
{
  mexPrintf("ERROR: Calling model mdlUpdate method directly.\n");
}

static void mdlOutputs(SimStruct* S, int_T tid)
{
  mexPrintf("ERROR: Calling model mdlOutputs method directly.\n");
}

static void mdlTerminate(SimStruct *S)
{
  mexPrintf("ERROR: Calling model mdlTerminate method directly.\n");
}

static void mdlInitializeSizes(SimStruct *S)
{
}

static void mdlInitializeSampleTimes(SimStruct *S)
{
}

static mxArray* cgxe_get_supported_modules(void)
{
  mxArray* mxModules = mxCreateCellMatrix(6, 1);
  mxArray* mxChksum = NULL;
  uint32_T* checksumData = NULL;
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 347937350;
  checksumData[1] = 1460979762;
  checksumData[2] = 3640040636;
  checksumData[3] = 3655889136;
  mxSetCell(mxModules, 0, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 2002085996;
  checksumData[1] = 1024576321;
  checksumData[2] = 2014206729;
  checksumData[3] = 2385633598;
  mxSetCell(mxModules, 1, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 2207911699;
  checksumData[1] = 3552240136;
  checksumData[2] = 682922085;
  checksumData[3] = 2506753311;
  mxSetCell(mxModules, 2, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 2322836994;
  checksumData[1] = 1846064845;
  checksumData[2] = 3518152846;
  checksumData[3] = 2412948684;
  mxSetCell(mxModules, 3, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 3303928983;
  checksumData[1] = 3141673938;
  checksumData[2] = 2723886985;
  checksumData[3] = 1957248087;
  mxSetCell(mxModules, 4, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 3314667035;
  checksumData[1] = 3295405573;
  checksumData[2] = 1353369979;
  checksumData[3] = 3268045778;
  mxSetCell(mxModules, 5, mxChksum);
  return mxModules;
}

static int cgxe_process_get_checksums(int nlhs, mxArray* plhs[], int nrhs, const
  mxArray* prhs[])
{
  const char* checksumFields[] = { "modules", "model", "makefile", "target",
    "overall" };

  mxArray* mxChecksum = mxCreateStructMatrix(1, 1, 5, checksumFields);
  mxSetField(mxChecksum, 0, "modules", cgxe_get_supported_modules());

  {
    mxArray* mxModelChksum = mxCreateDoubleMatrix(1, 4, mxREAL);
    double* checksumData = (double*) mxGetData(mxModelChksum);
    checksumData[0] = 833879372;
    checksumData[1] = 1991817552;
    checksumData[2] = 2770522580;
    checksumData[3] = 107129010;
    mxSetField(mxChecksum, 0, "model", mxModelChksum);
  }

  {
    mxArray* mxMakefileChksum = mxCreateDoubleMatrix(1, 4, mxREAL);
    double* checksumData = (double*) mxGetData(mxMakefileChksum);
    checksumData[0] = 2832987186;
    checksumData[1] = 2816209525;
    checksumData[2] = 2656235777;
    checksumData[3] = 1669520980;
    mxSetField(mxChecksum, 0, "makefile", mxMakefileChksum);
  }

  {
    mxArray* mxTargetChksum = mxCreateDoubleMatrix(1, 4, mxREAL);
    double* checksumData = (double*) mxGetData(mxTargetChksum);
    checksumData[0] = 2911221907;
    checksumData[1] = 2308967934;
    checksumData[2] = 2419390157;
    checksumData[3] = 1906300239;
    mxSetField(mxChecksum, 0, "target", mxTargetChksum);
  }

  {
    mxArray* mxOverallChksum = mxCreateDoubleMatrix(1, 4, mxREAL);
    double* checksumData = (double*) mxGetData(mxOverallChksum);
    checksumData[0] = 4121004685;
    checksumData[1] = 4155074134;
    checksumData[2] = 3085682820;
    checksumData[3] = 1966646247;
    mxSetField(mxChecksum, 0, "overall", mxOverallChksum);
  }

  plhs[0] = mxChecksum;
  return 1;
}

static int cgxe_mex_unlock_call(int nlhs, mxArray * plhs[], int nrhs, const
  mxArray * prhs[])
{
  while (mexIsLocked()) {
    mexUnlock();
  }

  return 1;
}

static SimStruct* cgxe_unpack_simstruct(const mxArray *mxS)
{
  uint32_T *uintPtr = (uint32_T*)malloc(sizeof(SimStruct*));
  int nEl = sizeof(SimStruct*)/sizeof(uint32_T);
  uint32_T *uintDataPtr = (uint32_T *)mxGetData(mxS);
  int el;
  SimStruct *S;
  for (el=0; el < nEl; el++) {
    uintPtr[el] = uintDataPtr[el];
  }

  memcpy(&S,uintPtr,sizeof(SimStruct*));
  free(uintPtr);
  return S;
}

static int cgxe_get_sim_state(int nlhs, mxArray * plhs[], int nrhs, const
  mxArray * prhs[])
{
  unsigned int success;
  SimStruct *S = cgxe_unpack_simstruct(prhs[1]);
  success = cgxe_ChildApp_method_dispatcher(S, SS_CALL_MDL_GET_SIM_STATE, (void *)
    (plhs));
  if (!success) {
    /* error */
    mexPrintf("ERROR: Failed to dispatch s-function method!\n");
  }

  return 1;
}

static int cgxe_set_sim_state(int nlhs, mxArray * plhs[], int nrhs, const
  mxArray * prhs[])
{
  unsigned int success;
  SimStruct *S = cgxe_unpack_simstruct(prhs[1]);
  success = cgxe_ChildApp_method_dispatcher(S, SS_CALL_MDL_SET_SIM_STATE, (void *)
    prhs[2]);
  if (!success) {
    /* error */
    mexPrintf("ERROR: Failed to dispatch s-function method!\n");
  }

  return 1;
}

static int cgxe_get_BuildInfoUpdate(int nlhs, mxArray * plhs[], int nrhs, const
  mxArray * prhs[])
{
  char tpChksum[64];
  mxGetString(prhs[1], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(tpChksum, "fVlsMLmdzYAX6SQIZ1SASG") == 0) {
    extern mxArray *cgxe_fVlsMLmdzYAX6SQIZ1SASG_BuildInfoUpdate(void);
    plhs[0] = cgxe_fVlsMLmdzYAX6SQIZ1SASG_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "blSUn4QnJNLfWyYmFDGX2") == 0) {
    extern mxArray *cgxe_blSUn4QnJNLfWyYmFDGX2_BuildInfoUpdate(void);
    plhs[0] = cgxe_blSUn4QnJNLfWyYmFDGX2_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "Ypj5Jn8N33o3OLpRVCU3p") == 0) {
    extern mxArray *cgxe_Ypj5Jn8N33o3OLpRVCU3p_BuildInfoUpdate(void);
    plhs[0] = cgxe_Ypj5Jn8N33o3OLpRVCU3p_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "JYafLD391rVjYJYcOtHmWG") == 0) {
    extern mxArray *cgxe_JYafLD391rVjYJYcOtHmWG_BuildInfoUpdate(void);
    plhs[0] = cgxe_JYafLD391rVjYJYcOtHmWG_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "Vey3QZKPPVzA79ZKkJbj3D") == 0) {
    extern mxArray *cgxe_Vey3QZKPPVzA79ZKkJbj3D_BuildInfoUpdate(void);
    plhs[0] = cgxe_Vey3QZKPPVzA79ZKkJbj3D_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "ovoTD6Rpo9A66H7u0ZZ2HH") == 0) {
    extern mxArray *cgxe_ovoTD6Rpo9A66H7u0ZZ2HH_BuildInfoUpdate(void);
    plhs[0] = cgxe_ovoTD6Rpo9A66H7u0ZZ2HH_BuildInfoUpdate();
    return 1;
  }

  return 0;
}

static int cgxe_get_fallback_info(int nlhs, mxArray * plhs[], int nrhs, const
  mxArray * prhs[])
{
  char tpChksum[64];
  mxGetString(prhs[1], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(tpChksum, "fVlsMLmdzYAX6SQIZ1SASG") == 0) {
    extern mxArray *cgxe_fVlsMLmdzYAX6SQIZ1SASG_fallback_info(void);
    plhs[0] = cgxe_fVlsMLmdzYAX6SQIZ1SASG_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "blSUn4QnJNLfWyYmFDGX2") == 0) {
    extern mxArray *cgxe_blSUn4QnJNLfWyYmFDGX2_fallback_info(void);
    plhs[0] = cgxe_blSUn4QnJNLfWyYmFDGX2_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "Ypj5Jn8N33o3OLpRVCU3p") == 0) {
    extern mxArray *cgxe_Ypj5Jn8N33o3OLpRVCU3p_fallback_info(void);
    plhs[0] = cgxe_Ypj5Jn8N33o3OLpRVCU3p_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "JYafLD391rVjYJYcOtHmWG") == 0) {
    extern mxArray *cgxe_JYafLD391rVjYJYcOtHmWG_fallback_info(void);
    plhs[0] = cgxe_JYafLD391rVjYJYcOtHmWG_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "Vey3QZKPPVzA79ZKkJbj3D") == 0) {
    extern mxArray *cgxe_Vey3QZKPPVzA79ZKkJbj3D_fallback_info(void);
    plhs[0] = cgxe_Vey3QZKPPVzA79ZKkJbj3D_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "ovoTD6Rpo9A66H7u0ZZ2HH") == 0) {
    extern mxArray *cgxe_ovoTD6Rpo9A66H7u0ZZ2HH_fallback_info(void);
    plhs[0] = cgxe_ovoTD6Rpo9A66H7u0ZZ2HH_fallback_info();
    return 1;
  }

  return 0;
}

#define PROCESS_MEX_SFUNCTION_CMD_LINE_CALL

static int ProcessMexSfunctionCmdLineCall(int nlhs, mxArray* plhs[], int nrhs,
  const mxArray* prhs[])
{
  char commandName[64];
  if (nrhs < 1 || !mxIsChar(prhs[0]))
    return 0;
  mxGetString(prhs[0], commandName, sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName, "get_checksums") == 0) {
    return cgxe_process_get_checksums(nlhs, plhs, nrhs, prhs);
  }

  if (strcmp(commandName, "mex_unlock") == 0) {
    return cgxe_mex_unlock_call(nlhs, plhs, nrhs, prhs);
  }

  if (strcmp(commandName, "get_sim_state") == 0) {
    return cgxe_get_sim_state(nlhs, plhs, nrhs, prhs);
  }

  if (strcmp(commandName, "set_sim_state") == 0) {
    return cgxe_set_sim_state(nlhs, plhs, nrhs, prhs);
  }

  if (strcmp(commandName, "get_BuildInfoUpdate") == 0) {
    return cgxe_get_BuildInfoUpdate(nlhs, plhs, nrhs, prhs);
  }

  if (strcmp(commandName, "get_fallback_info") == 0) {
    return cgxe_get_fallback_info(nlhs, plhs, nrhs, prhs);
  }

  return 0;
}

#include "simulink.c"
