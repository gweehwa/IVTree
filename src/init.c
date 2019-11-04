#include "IVTree.h"
#include "R_ext/Rdynload.h"
#include "node.h"
#include "IVTreeproto.h"

SEXP init_ctcallback(SEXP rhox, SEXP ny, SEXP nr, SEXP expr1x, SEXP expr2x);
SEXP pred_IVTree(SEXP dimx, SEXP nnode, SEXP nsplit, SEXP dimc,
		SEXP nnum, SEXP nodes2, SEXP vnum, SEXP split2,
		SEXP csplit2, SEXP usesur, SEXP xdata2, SEXP xmiss2);
SEXP estimate_IVTree(SEXP dimx, SEXP nnode, SEXP nsplit, SEXP dimc,
  	SEXP nnum, SEXP nodes2, SEXP vnum, SEXP split2,
		SEXP csplit2, SEXP usesur, SEXP xdata2, SEXP xmiss2);

SEXP honest_estimate_IVTree(SEXP dimx, SEXP nnode, 
                               SEXP nsplit, SEXP dimc, SEXP nnum, 
                               SEXP nodes2,
                               SEXP n1, SEXP wt1, SEXP dev1, SEXP yval1, 
                               SEXP vnum, 
                               SEXP split2,
                               SEXP csplit2, SEXP usesur, 
                               SEXP xdata2, SEXP wt2, SEXP treatment2, SEXP y2,
                               SEXP xmiss2);
SEXP honest_estimate_rparttree(SEXP dimx, SEXP nnode, SEXP nsplit, SEXP dimc,
                           SEXP nnum, SEXP nodes2, SEXP n1, SEXP wt1, SEXP dev1, SEXP yval1,
                           SEXP vnum, SEXP split2,
                           SEXP csplit2, SEXP usesur, SEXP xdata2, SEXP wt2, SEXP y2,
                           SEXP xmiss2);


static const R_CallMethodDef CallEntries[] = {
    {"init_ctcallback", (DL_FUNC) &init_ctcallback, 5},
    {"IVTree", (DL_FUNC) &IVTree, 25},
    {"pred_IVTree", (DL_FUNC) &pred_IVTree, 12},
    {"estimate_IVTree", (DL_FUNC) &estimate_IVTree, 12},
    {"honest_estimate_IVTree", (DL_FUNC) &honest_estimate_IVTree, 21},
    {"honest_estimate_rparttree", (DL_FUNC) &honest_estimate_rparttree, 18},
    {NULL, NULL, 0}
};

#include <Rversion.h>
void
R_init_IVTree(DllInfo * dll)
{
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, TRUE);//FALSE
#if defined(R_VERSION) && R_VERSION >= R_Version(2, 16, 0)
    R_forceSymbols(dll, TRUE);
#endif
}
