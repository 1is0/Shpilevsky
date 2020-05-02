using System;

namespace Game
{
    class UnitEventArgs:EventArgs
    {
        public readonly string msg;
        public UnitEventArgs(string Name)
        {
            msg = Name;
        }    
    }
}
