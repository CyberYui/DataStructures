_declspec (dllexport) float GetAdd(float a, float b)
{
	return a + b;
}

_declspec (dllexport) float GetSub(float a, float b)
{
	return a - b;
}

_declspec (dllexport) float GetMul(float a, float b)
{
	return a * b;
}

int main()
{
	return 0;
}