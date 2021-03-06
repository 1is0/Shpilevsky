﻿using System;

namespace Game
{
    enum Bow
    {
        UsualBone,
        SuperBone,
        MegaBone,
        Bone3000
    }

    class Archer: Unit
    {
        public Bow Weapon { get; set; }

       public Archer(Bow weapon):base()
        {
            
            Name = "Лучник";
            Armor = 100;
            Weapon = weapon;
            appearance = new Appearance(36, "Long blonde", "Elf");
            SetDamage();
        }
 
        public Archer(int hp, int damage, int stamina, int armor, string name, Appearance ap, Bow weapon):base(hp,damage,stamina,armor,"Лучник",ap)
        {
            Weapon = weapon;
        }

       public Archer(Archer ob, Bow bow) : base(ob) 
        {
            this.Weapon = ob.Weapon;
            SetDamage();
        }

        private void SetDamage()
        {
            switch (Weapon)
            {
                case Bow.UsualBone:
                    Damage = 200;
                    break;
                case Bow.SuperBone:
                    Damage = 300;
                    break;
                case Bow.MegaBone:
                    Damage = 400;
                    break;
                case Bow.Bone3000:
                    Damage = 1337;
                    break;
            }
        }

        public override void ShowInfo()
        {

            Console.WriteLine($"\n{Name}:\nHp - {Hp}\nDamage - {Damage}\n" +
           $"Stamina - {Stamina}\nArmor - {Armor}\nWeapon - {this.Weapon.ToString()}");
        }



    }
}
