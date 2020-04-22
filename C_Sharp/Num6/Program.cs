using System;

namespace Game
{
    class Program
    {
        static void Main(string[] args)
        {
            Appearance forArch = new Appearance(64, "Ирокез", "Ельф");
            Appearance forHealer = new Appearance(32, "Рыжий", "Человек");
            Appearance forUnit = new Appearance(60, "Темные короткие", "Люди");

            Archer ar = new Archer(Bow.Bone3000);
            Archer ar1 = (Archer)ar.Clone();
           
            Cavalier cv = new Cavalier(Sword.StickFromTheYard);
            Unit un = new Unit(150, 200, 400, "Пивовар", forUnit);
            Healer hl = new Healer(HealingDevice.MumScream);

            Unit[] units = new Unit[] { ar, ar1, cv, un, hl };

            Array.Sort(units);

            foreach (Unit unit in units)
            {
                unit.ShowInfo();
            }

            ar1.Attack(ar);
            ar.ShowInfo();

            hl.HealUnit(ar);
            ar.ShowInfo();

        }
    }
}
