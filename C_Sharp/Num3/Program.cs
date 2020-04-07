using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab
{
    class Program
    {
        static void Main(string[] args)
        {
            Hero pers = new Hero();
            Hero pers1 = new Hero(200, 300, 100, 275, "Debush");
            Hero pers2 = new Hero(pers1);

            pers.ShowInfo();
            pers1.ShowInfo();


            pers2.Hp = 75;
            pers2.Name = "Glad";
            pers2.ShowInfo();

            pers2.Attack(pers1);

            pers1.ShowInfo();
        }
    }
}

