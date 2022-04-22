#if defined(__x86_64__)
#include "platform/amd64/exec.h"
#elif defined(__x86__)
#include "platform/x86/exec.h"
#elif defined(__ppc64__)
#include "platform/powerpc/exec.h"
#elif defined(__ppc__)
#include "platform/powerpc/exec.h"
#elif defined(__arm__)
#include "platform/arm/exec.h"
#elif defined(__aarch64__)
#include "platform/arm64/exec.h"
#elif !defined(__GNUC__)
#ifdef _WIN32
#include "platform/windows/exec.h"
#else
#error Your platform is unsupported
#endif
#endif