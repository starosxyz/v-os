#if defined(__x86_64__)
#include "platform/amd64/ucontext.h"
#elif defined(__x86__)
#include "platform/x86/ucontext.h"
#elif defined(__ppc64__)
#include "platform/powerpc/ucontext.h"
#elif defined(__ppc__)
#include "platform/powerpc/ucontext.h"
#elif defined(__arm__)
#include "platform/arm/ucontext.h"
#elif defined(__aarch64__)
#include "platform/arm64/ucontext.h"
#elif !defined(__GNUC__)
#ifdef _WIN32
#include "platform/windows/ucontext.h"
#else
#error Your platform is unsupported
#endif
#endif