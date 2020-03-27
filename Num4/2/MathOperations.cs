using System.Runtime.InteropServices;

namespace DllTest
{
    static class MathOperations
    {
        [DllImport("Dll.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern int Sum(int n, int a, int b, int c);

        [DllImport("Dll.dll", CallingConvention = CallingConvention.StdCall)]
        public static extern int NOD(int a, int b);

        [DllImport("Dll.dll", CallingConvention = CallingConvention.StdCall)]
        public static extern int NOK(int a, int b);

        [DllImport("Dll.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern double Average(int n, double a, double b, double c);

        [DllImport("Dll.dll", CallingConvention = CallingConvention.StdCall)]
        public static extern int Sub(int a, int b);

        [DllImport("Dll.dll", CallingConvention = CallingConvention.StdCall)]
        public static extern int Mult(int a, int b);

        [DllImport("Dll.dll", CallingConvention = CallingConvention.StdCall)]
        public static extern double Div(int a, int b);
    }
}
