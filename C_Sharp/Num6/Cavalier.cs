using System;

namespace Game
{
    enum Sword
    {
        UsualSword,
        SwordOfGods,
        StickFromTheYard
    }

    class Cavalier:Unit
    {
         Sword Weapon { get; set; }
        
        public Cavalier(Sword weapon) : base()
        {
            Hp = 393;
            Name = "Cavalier";
            Armor = 400;
            Weapon = weapon;
            SetDamage();
        }

        public Cavalier(int hp, int damage, int armor, string name, Sword weapon,Appearance ap) : base(hp, damage,  armor, name,ap)
        {
            Weapon = weapon;
        }

        private void SetDamage()
        {
            switch (Weapon)
            {
                case Sword.StickFromTheYard:
                    Damage = 555;
                    break;
                case Sword.UsualSword:
                    Damage = 200;
                    break;
                case Sword.SwordOfGods:
                    Damage = 333;
                    break;
            }
        }

        public override void ShowInfo()
        {
            Console.WriteLine($"\n{Name}:\nHp - {Hp}\nDamage - {Damage}\n" +
           $"Armor - {Armor}\nWeapon - {this.Weapon.ToString()}");
        }
    }
}
