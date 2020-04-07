using System.Runtime.InteropServices;

namespace UnsafeCode
{
    [StructLayout(LayoutKind.Sequential, CharSet = CharSet.Auto)]
    class MemoryInfo
    {
        public uint Length;

        public uint MemoryLoad;

        public ulong TotalPhys;

        public ulong AvailPhys;

        public ulong TotalPageFile;

        public ulong AvailPageFile;

        public ulong TotalVirtual;

        public ulong AvailVirtual;

        public ulong AvailExtendedVirtual;

        public MemoryInfo()
        {
            this.Length = (uint)Marshal.SizeOf(typeof(MemoryInfo));
        }


    }
}
