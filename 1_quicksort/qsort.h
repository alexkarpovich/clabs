#ifndef QSORT_H_   
#define QSORT_H_     
#include "templates.h"    
#ifdef T  
#undef T  
#endif  
#define T float  
#include "qsort_template.h"    
#ifdef T  
#undef T  
#endif  
#define T double  
#include "qsort_template.h"    
#ifdef T  
#undef T  
#endif  
#define T long  
#include "qsort_template.h"    
#ifdef T  
#undef T  
#endif  
#define T int  
#include "qsort_template.h"
#endif