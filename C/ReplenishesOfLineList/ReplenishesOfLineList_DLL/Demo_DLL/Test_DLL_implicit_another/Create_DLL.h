#ifndef Create_DLL_H
#define Create_DLL_H

//要导出的函数在这里声明
_declspec (dllexport) float GetAdd(float a, float b);
_declspec (dllexport) float GetSub(float a, float b);
_declspec (dllexport) float GetMul(float a, float b);

#endif // Create_DLL_H