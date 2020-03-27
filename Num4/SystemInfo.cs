using System;
using System.Text;
using System.Runtime.InteropServices;

namespace UnsafeCode
{
    class SystemInfo
    {
        [DllImport("kernel32.dll", SetLastError = true)]
        public static extern bool GlobalMemoryStatusEx(MemoryInfo info);

        [DllImport("kernel32.dll", SetLastError = false)]
        public static extern void GetSystemInfo(ProcessorInfo info);

        public static string ShowMemoryInfo()
        {
            MemoryInfo info = new MemoryInfo();
            GlobalMemoryStatusEx(info);

            StringBuilder str = new StringBuilder();
            str.Append($"Memory architecture - {info.Length} bit\n");
            str.Append($"Memory Load - {info.MemoryLoad}%\n");
            str.Append($"Total Memory - {info.TotalPhys / Math.Pow(2, 30)} GB\n");
            str.Append($"Available Memory - {info.AvailPhys / Math.Pow(2, 30)} GB\n");
            str.Append($"Total Virtual Memory  - {info.TotalVirtual / Math.Pow(2, 30)} GB\n");
            str.Append($"Available Virtual Memory - {info.AvailVirtual / Math.Pow(2, 30)} GB\n");

            return str.ToString();
        }

        public static string ShowProcessorInfo()
        {
            ProcessorInfo info = new ProcessorInfo();
            
            GetSystemInfo(info);

            StringBuilder str = new StringBuilder();    
            switch (info.ProcessorArchitecture)
            {
                case 0:
                    str.Append("x64\n");
                    break;
                case 9:
                    str.Append("x86\n");
                    break;
            }

            str.Append($"Amount of processors = {info.NumberOfProcessors + 1}\n");
            return str.ToString();
        }
    }
}
