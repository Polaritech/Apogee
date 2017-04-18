#if defined(APOGEE_DLL)
#  if defined(APOGEE_EXPORT)
#    if defined(_WIN32)
#      define APOGEE_API __declspec(dllexport)
#    else
#      define APOGEE_API
#    endif
#  else
#    if defined(_WIN32)
#      define APOGEE_API __declspec(dllimport)
#    else
#      define APOGEE_API
#    endif
#  endif
#else
#  define APOGEE_API
#endif