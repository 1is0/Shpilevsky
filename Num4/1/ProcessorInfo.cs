using  System;

namespace UnsafeCode
{

    class ProcessorInfo
    {
        public short ProcessorArchitecture;

        public uint PageSize;

        public IntPtr MinimumApplicationAddress;

        public IntPtr MaximumApplicationAddress;

        public IntPtr ActiveProcessorMask;

        public uint NumberOfProcessors;

        public uint ProcessorType;

        public uint AllocationGranularity;

        public ushort ProcessorLevel;

        public ushort ProcessorRevision;

    }
}
