#include "templates.h"  
#include "qsort.h"
#ifdef T 
#undef T  
#endif  
#define T float  
#include "qsort_template.c"    
#ifdef T  
#undef T  
#endif  
#define T double  
#include "qsort_template.c"    
#ifdef T  
#undef T  
#endif 
#define T long  
#include "qsort_template.c"    
#ifdef T  
#undef T  
#endif 
#define T int  
#include "qsort_template.c"