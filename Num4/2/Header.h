#pragma once

#ifdef MATHLIBRARY_EXPORTS
#define MATHLIBRARY_API __declspec(dllexport)
#else
#define MATHLIBRARY_API __declspec(dllimport)
#endif

extern "C" MATHLIBRARY_API int Sum(int amount, ...);

extern "C" MATHLIBRARY_API int NOD(int a, int b);

extern "C" MATHLIBRARY_API int NOK(int a, int b);

extern "C" MATHLIBRARY_API int Sub(int a, int b);

extern "C" MATHLIBRARY_API double Average(int count, ...);

extern "C" MATHLIBRARY_API int Mult(int a, int b);

extern "C" MATHLIBRARY_API double Div(int a, int b);
