using System;

namespace Project
{
    class Program
    {
        public static double GetDouble()
        {

            double a;

            while (!double.TryParse(Console.ReadLine(), out a))
            {
                Console.Write("Incorrect input, repeat: ");
            }

            return a;
        }

        public static Number GetFraction()
        { 
            Console.Write("\nEnter fraction: ");

            string str = Console.ReadLine();
            while (!CheckFraction(str))
            {

                Console.Write("Incorrect input, repeat: ");
                str = Console.ReadLine();
            }

            try
            {
                string[] mas = str.Split('/');
                return new Number(int.Parse(mas[0]), int.Parse(mas[1]));
            }

            catch
            {
                return new Number(int.Parse(str), 1);
            }
        }

        public static Number GetNumber()
        {
            Console.Write("\nEnter number: ");
            double number = GetDouble();
            return new Number(number);
        }

        public static Number GetRatNumber()
        {
            int x;
            Console.Write("\n0 - Fraction, 1 - Number ");

            
            while (!int.TryParse(Console.ReadLine(), out x) || x < 0 || x > 1)
            {
                Console.Write("Incorrect input, repeat: ");
            }

            if(x == 0)
            {
                return GetFraction();
            }

            else
            {
                return GetNumber();
            }
        }

        public static bool CheckFraction(string frac)
        {
            if (String.IsNullOrEmpty(frac))
            { 
                return false;
            }

            for (int i = 0; i < frac.Length; i++)
            {
                if (i == 0 && frac[i] == '-')
                {
                    i++;
                }

                if((frac[i] == '/' && i != frac.Length - 1))
                {
                    i++;
                }

                if (frac[i] == '0' && frac.Length == 1)
                {
                    return false;
                }

                if (!char.IsDigit(frac[i]) || (frac[i] == '0' && i == frac.Length - 1 && frac[i - 1] == '/'))
                {
                    return false;
                }
            }
            return true;
        }

        static void Main(string[] args)
        {
            Console.Write("Enter the first number");
            var num1 = GetRatNumber();

            Console.Write("\nEnter the second number");
            var num2 = GetRatNumber();

            Console.Clear();
            Console.WriteLine("first number: " + num1);
            Console.WriteLine("second number: " + num2);

            Console.WriteLine($"1. {num1} > {num2} = " + (num1 > num2));

            Console.WriteLine($"2. {num1} < {num2} = " + (num1 < num2));

            Console.WriteLine($"3. {num1} == {num2} = " + (num1 == num2));

            Console.WriteLine($"4. {num1} != {num2} = " + (num1 != num2));

            Console.WriteLine($"5. {num1} + {num2} = " + (num1 + num2));

            Console.WriteLine($"6. {num1} - {num2} = " + (num1 - num2));

            Console.WriteLine($"7. {num1} * {num2} = " + (num1 * num2));
        }
    }
}
