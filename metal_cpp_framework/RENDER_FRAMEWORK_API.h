
#ifndef RENDER_FRAMEWORK_API_H
#define RENDER_FRAMEWORK_API_H

#ifdef RENDER_FRAMEWORK_BUILT_AS_STATIC
#  define RENDER_FRAMEWORK_API
#  define RENDER_FRAMEWORK_NO_EXPORT
#else
#  ifndef RENDER_FRAMEWORK_API
#    ifdef render_framework_EXPORTS
        /* We are building this library */
#      define RENDER_FRAMEWORK_API __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define RENDER_FRAMEWORK_API __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef RENDER_FRAMEWORK_NO_EXPORT
#    define RENDER_FRAMEWORK_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef RENDER_FRAMEWORK_DEPRECATED
#  define RENDER_FRAMEWORK_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef RENDER_FRAMEWORK_DEPRECATED_EXPORT
#  define RENDER_FRAMEWORK_DEPRECATED_EXPORT RENDER_FRAMEWORK_API RENDER_FRAMEWORK_DEPRECATED
#endif

#ifndef RENDER_FRAMEWORK_DEPRECATED_NO_EXPORT
#  define RENDER_FRAMEWORK_DEPRECATED_NO_EXPORT RENDER_FRAMEWORK_NO_EXPORT RENDER_FRAMEWORK_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef RENDER_FRAMEWORK_NO_DEPRECATED
#    define RENDER_FRAMEWORK_NO_DEPRECATED
#  endif
#endif

#endif /* RENDER_FRAMEWORK_API_H */
