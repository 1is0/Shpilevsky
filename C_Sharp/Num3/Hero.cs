using System;


namespace lab
{
    class Hero
    {
        double hp;
        public double Damage { get; }
        public double Stamina { get; set; }
        public string Name { get; set; }
        double armor;

        public Hero()
        {
            Hp = 100;
            Damage = 0;
            Stamina = 100;
            Name = "Нейтральный юнит";
            Armor = 0;
        }

        public Hero(double hp, double damage, double stamina, double armor, string name)
        {
            Hp = hp;
            Damage = damage;
            Stamina = stamina;
            Armor = armor;
            Name = name;
        }

        public Hero(Hero ob)
        {
            Hp = ob.hp;
            Damage = ob.Damage;
            Stamina = ob.Stamina;
            Name = ob.Name;
            Armor = ob.Armor;
        }

        public void ShowInfo()
        {
            Console.WriteLine($"{Name}:\nHp - {Hp}\nDamage - {Damage}\n" +
                $"Stamina - {Stamina}\nArmor - {Armor}\n");
        }

        public double Hp
        {
            get
            {
                return hp;
            }
            set
            {
                hp = value < 0 ? 0 : value;
            }
        }

        public double Armor
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


        public void Attack(Hero ob)
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
                    double ad = this.Damage - ob.armor;
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