using System;

namespace Game
{
    public struct Appearance
    {
        int age;
        public string HairType { get; set; } 

        public string Race { get; set; }

        public int Age
        {
            get
            {
                return age;
            }

            set
            {
                age = value > 0 ? value : 0;
            }
        }

        public Appearance(int vozr, string hType,string race) : this()
        {
            HairType = hType;
            this.Age = vozr;
            Race = race;
        }
    }


    class Unit
    {
        int hp;

        public Appearance appearance { get; set; }
        public int Damage { get; protected set; }
        public int Stamina { get; set; }
        public string Name { get; set; }
        int armor;

        public Unit()
        {
            Hp = 100;
            Damage = 0;
            Stamina = 100;
            Name = "Нейтральный юнит";
            Armor = 0;
            appearance = new Appearance(18, "Dreds", "Люди");
        }

        public Unit(int hp, int damage, int stamina, int armor, string name, Appearance ap)
        {
            Hp = hp;
            Damage = damage;
            Stamina = stamina;
            Armor = armor;
            Name = name;
            appearance = ap;
        }

        public Unit(Unit ob)
        {
            Hp = ob.hp;
            Damage = ob.Damage;
            Stamina = ob.Stamina;
            Name = ob.Name;
            Armor = ob.Armor;
            this.appearance = ob.appearance;
        }

        public virtual void ShowInfo()
        {
            ShowAppearance();
            Console.Write($"\n{Name}:\nHp - {Hp}\nDamage - {Damage}\n" +
                $"Stamina - {Stamina}\nArmor - {Armor}");
        }

        public void ShowAppearance()
        {
            Console.Write($"\nAppearance: Age - {appearance.Age}, Hair is {appearance.HairType}, Race is {appearance.Race}");
        }

        public int Hp
        {
            get
            {
                return hp;
            }
            set
            {
                hp = value < 0 ? 0 : value > 1000 ? 1000 : value;
            }
        }

        public int Armor
        {
            get
            {
                return armor;
            }

            set
            {
                armor = value < 0 ? 0 : value;
            }
        }


        public void Attack(Unit ob)
        {
            Console.WriteLine($"{this.Name} attacked {ob.Name}");

            if (ob.Armor > 0)
            {
                if (ob.Armor - this.Damage >= 0)
                {
                    ob.Armor -= this.Damage;
                }

                else
                {
                    int ad = this.Damage - ob.armor;
                    ob.Armor -= this.Damage;
                    ob.Hp -= ad;
                }
            }

            else
            {
                ob.Hp -= this.Damage;
            }
        }


    }

}