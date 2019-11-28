/*
 *
 * status tracing for microwin
 * 2006/06/27
 *
 */


#ifndef __DEVSTATUS_H
#define __DEVSTATUS_H  1



#define  USE_STATUS_TRACING  1



typedef struct _StatusTrace_t {
	int index;
	int values[];
} StatusTrace_t;

extern StatusTrace_t *g_psStatTrace;
extern int            g_lsStatTraceMaxIdx;
		


#if USE_STATUS_TRACING

#define STATUS_TRACE(n)   do { if(g_psStatTrace) {(g_psStatTrace->index)++; \
       g_psStatTrace->values[(g_psStatTrace->index)&g_lsStatTraceMaxIdx]=(unsigned int)(n); } } while(0)


#else  /* #if USE_STATUS_TRACING */


#define STATUS_TRACE(n)  (void)(0)


#endif /* #if USE_STATUS_TRACING */


#endif /* #ifndef __DEVSTATUS_H */

