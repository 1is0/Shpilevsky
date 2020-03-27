using System;
using System.Runtime.InteropServices;
using System.Text;

namespace UnsafeCode
{
    class DiskMemoryInfo
    {
        [DllImport("kernel32.dll",SetLastError = true,CharSet = CharSet.Auto)]
        static extern bool GetDiskFreeSpaceEx(
            string lpDirectoryName, //имя диска
            out ulong lpFreeBytesAvailable, //доступно для использвония(байт)
            out ulong lpTotalNumberOfBytes, //максимальный объём(байт)
            out ulong lpTotalNumberOfFreeBytes); //свободно на диске(байт)

        public static string Info(string disc)
        {
            ulong FreeBytesAvailable;
            ulong TotalNumberOfBytes;
            ulong TotalNumberOfFreeBytes;

            bool success = GetDiskFreeSpaceEx(disc, out FreeBytesAvailable, out TotalNumberOfBytes, out TotalNumberOfFreeBytes);

            StringBuilder str = new StringBuilder();

            str.Append($"Free Space on disc {disc} {(FreeBytesAvailable / Math.Pow(2, 30)).ToString()}" + " GB\n") ;
            str.Append($"Total Space on disc {disc} {(TotalNumberOfBytes / Math.Pow(2, 30)).ToString()}" + " GB\n");

            return str.ToString();

        }
    }
}
