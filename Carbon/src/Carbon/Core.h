#pragma once

#define BIT(val) (1 << val)
#define BIND_FN(fn) std::bind(&fn, this, std::placeholders::_1)

#ifdef CN_DEBUG
#define CN_ASSERTIONS 1
#endif

#ifdef CN_ASSERTIONS
#define CN_ASSERT(val, ...) { if(!val) { CN_CORE_ERROR(__VA_ARGS__); __debugbreak(); }}
#else
#define CN_ASSERT(val, ...)
#endif