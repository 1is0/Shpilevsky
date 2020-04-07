
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
            Archer ar1 = new Archer(ar,Bow.Bone3000);
            Cavalier cv = new Cavalier(Sword.StickFromTheYard);
            Unit un = new Unit(150, 200, 300, 400, "Пивовар", forUnit);
            Healer hl = new Healer(HealingDevice.MumScream);

            un.ShowInfo();

            ar.ShowInfo();
            ar1.ShowInfo();

            ar1.Attack(ar);

            ar1.ShowInfo();
            ar.ShowInfo();

            hl.HealUnit(ar);

            ar.ShowInfo();

            cv.Attack(ar);

            cv.ShowInfo();
            ar.ShowInfo();

            cv.ShowAppearance();
            un.ShowAppearance();
        }
    }
}
