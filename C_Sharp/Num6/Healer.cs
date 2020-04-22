using System;


namespace Game
{
  
    enum HealingDevice
    {
        FirstAidKit,
        MagicStick,
        MumScream
    }

    class Healer: Unit
    {
        HealingDevice hDev;
        int healCap;

        public Healer(HealingDevice dev):base()
        {
            Name = "Хиллер";
            hDev = dev;
            appearance = new Appearance(76, "Длинные черные", "Чернокнижник");
            SetHealCap();
        }

        public Healer(int hp, int damage, int armor,string name,HealingDevice dev, Appearance ap) :base(hp,damage,armor,name, ap)
        {
            hDev = dev;
            SetHealCap();
        }

        private void SetHealCap()
        {
            switch (hDev)
            {
                case HealingDevice.FirstAidKit:
                    healCap = 200;
                    break;
                case HealingDevice.MagicStick:
                    healCap = 300;
                    break;
                case HealingDevice.MumScream:
                    healCap = 1888;
                    break;
            }
        }
            
        public void HealUnit(Unit obj)
        {
            obj.Hp += this.healCap;
        }

        public override void ShowInfo()
        {
            base.ShowInfo();
            Console.Write($"Healing device is {this.hDev.ToString()}\n");
        }
    }
}
