#include "postgres.h"
#include "tcop/utility.h"
#include "utils/builtins.h"

PG_MODULE_MAGIC;


void _PG_init(void);
void _PG_fini(void);
static ProcessUtility_hook_type prev_utility_hook = NULL;
static void forbid_truncate(PlannedStmt *pstmt,
							   const char *queryString,
							   ProcessUtilityContext context,
							   ParamListInfo params,
							   QueryEnvironment *queryEnv,
							   DestReceiver *dest,
							   QueryCompletion *qc);




static void forbid_truncate
(PlannedStmt *pstmt,
						const char *queryString,
						ProcessUtilityContext context,
						ParamListInfo params,
						QueryEnvironment *queryEnv,
						DestReceiver *dest,
						QueryCompletion *qc){
      Node	*parsetree = pstmt->utilityStmt;

       if (nodeTag(parsetree) ==  T_TruncateStmt){
         ereport(ERROR, (errmsg("forbid truncate")));
       }
       else
       standard_ProcessUtility(pstmt, queryString,
								context, params, queryEnv,
								dest, qc);


    }

void _PG_init(void)
{
  /* activate hook module is loaded */
  prev_utility_hook = ProcessUtility_hook;
  ProcessUtility_hook = forbid_truncate;
}

void _PG_fini(void)
{
  ProcessUtility_hook = prev_utility_hook;
}
