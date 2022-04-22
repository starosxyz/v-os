#if defined(__x86_64__)
#include "platform/amd64/cpu.h"
#elif defined(__x86__)
#include "platform/x86/cpu.h"
#elif defined(__ppc64__)
#include "platform/powerpc/cpu.h"
#elif defined(__ppc__)
#include "platform/powerpc/cpu.h"
#elif defined(__arm__)
#include "platform/arm/cpu.h"
#elif defined(__aarch64__)
#include "platform/arm64/cpu.h"
#elif !defined(__GNUC__)
#ifdef _WIN32
#include "platform/windows/cpu.h"
#else
#error Your platform is unsupported
#endif
#endif