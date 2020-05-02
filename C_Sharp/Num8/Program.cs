using System;

namespace Game
{
    class Program
    {


        static void Main(string[] args)
        {
            Appearance forArch = new Appearance(64, "Ирокез", "Ельф");
            Appearance forHealer = new Appearance(32, "Рыжий", "Человек");

            Archer ar = new Archer(Bow.Bone3000);
            Cavalier cv = new Cavalier(Sword.StickFromTheYard);
            Healer hl = new Healer(HealingDevice.MumScream);

            cv.ShowInfo();

            ar.Hit += (Hero, e) => Console.WriteLine("{0}",e.msg);
            hl.Heal += (Hero, e) => Console.WriteLine("{0}", e.msg);

            for (int i = 0; i < 2; i++)
            {
                ar.Attack(cv);
            }

            cv.ShowInfo();

            Console.WriteLine("\nPress sth to view prologue...");
            Console.ReadKey();
            Console.Clear();

            hl.HealUnit(cv);

            cv.ShowInfo();
        }
    }
}
