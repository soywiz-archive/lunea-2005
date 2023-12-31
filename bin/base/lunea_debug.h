//#pragma once

//#define debug_lunea_kernel true
//#define debug_lunea_kernel false

#ifdef debug_lunea_kernel
#	ifndef LUNEA_DEBUG
#		define LUNEA_DEBUG if (true)
#	endif
#else
#	ifndef LUNEA_DEBUG
#		define LUNEA_DEBUG if (false)
#	endif
#endif