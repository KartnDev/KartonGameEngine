#define USING_FAST_FLOAT

#ifdef USING_FAST_FLOAT
	typedef float FloatFX; 
#endif	

#ifndef USING_FAST_FLOAT
	typedef double FloatFX;
#endif // !USING_FAST_FLOAT



