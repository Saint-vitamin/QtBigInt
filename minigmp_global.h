#ifndef MINIGMP_GLOBAL_H
#define MINIGMP_GLOBAL_H

#if defined(MINIGMP_LIBRARY)
#  define UNTITLEDSHARED_EXPORT __declspec(dllexport)
#else
#  define UNTITLEDSHARED_EXPORT __attribute__((visibility("default")))
#endif

#endif //MINIGMP_GLOBAL_H
