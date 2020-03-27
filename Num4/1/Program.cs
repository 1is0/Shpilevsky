using System;

namespace UnsafeCode
{
    class Program
    {
        static void Main(string[] args)
        {

            Console.WriteLine(SystemInfo.ShowMemoryInfo());
            Console.WriteLine(SystemInfo.ShowProcessorInfo());

            Console.WriteLine(DiskMemoryInfo.Info("C:\\"));
            Console.WriteLine(DiskMemoryInfo.Info("D:\\"));
        }
    }
}
