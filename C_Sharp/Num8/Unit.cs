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


    class Unit:IUnit, IComparable, ICloneable
    {
        int hp;

        public Appearance appearance { get; set; }
        public int Damage { get; protected set; }
        public string Name { get; set; }
        int armor;

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

        public Unit()
        {
            Hp = 100;
            Damage = 0;
            Name = "Нейтральный юнит";
            Armor = 0;
            appearance = new Appearance(18, "Dreds", "Люди");
        }

        public Unit(int hp, int damage, int armor, string name, Appearance ap)
        {
            Hp = hp;
            Damage = damage;
            Armor = armor;
            Name = name;
            appearance = ap;
        }

        public virtual void ShowInfo()
        {
            Console.Write($"\n{Name}:\nHp - {Hp}\nDamage - {Damage}" + $"\nArmor - {Armor}");
            ShowAppearance();
        }

        public void ShowAppearance()
        {
            Console.Write($"\nAppearance: Age - {appearance.Age}, Hair is {appearance.HairType}, Race is {appearance.Race}\n");
        }


        public event EventHandler<UnitEventArgs> Hit;
        
        public void Attack(Unit obj)
        {
            if (obj.Hp > 0)
            {
                if (obj.Armor > 0)
                {
                    if (obj.Armor - this.Damage >= 0)
                    {
                        obj.Armor -= this.Damage;
                    }

                    else
                    {
                        int ad = this.Damage - obj.armor;
                        obj.Armor -= this.Damage;
                        obj.Hp -= ad;
                    }
                }
                else
                {
                    obj.Hp -= this.Damage;
                }
                Hit?.Invoke(obj, new UnitEventArgs($"{obj.Name} took {this.Damage} damage"));
            }

            else
            {
                Hit?.Invoke(obj, new UnitEventArgs($"{obj.Name} Dead. R.I.P"));
            }


        }

        public int CompareTo(object obj)
        {
            Unit unit = obj as Unit;

            if(unit != null)
            {
                return (Hp).CompareTo(unit.Hp );
            }

            else
            {
                throw new Exception("Невозможно сравнить два объекта");
            }
        }

        public object Clone()
        {
            return (Unit)this.MemberwiseClone();
        }
    }

}