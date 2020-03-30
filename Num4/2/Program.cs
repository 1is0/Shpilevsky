using System;

namespace DllTest
{
  

    class Program
    {
        static int Check()
        {
            int a;
            while(!int.TryParse(Console.ReadLine(),out a))
            {
                Console.WriteLine("Wrong data. Input again: ");
            }
            return a;
        }

        static void Main()
        {
            Console.Write("a = ");
            int a = Check();

            Console.Write("b = ");
            int b = Check();

            Console.Write("c = ");
            int c = Check();



            Console.WriteLine($"Average of {a} {b} {c} is " + MathOperations.Average(3,a,b,c));

            Console.WriteLine($"NOD of {a} & {b} is " + MathOperations.NOD(a,b));
            
            Console.WriteLine($"NOK of {a} & {c} is " + MathOperations.NOK(a,c));

            Console.WriteLine($"Sum of {a} {b} {c} is " + MathOperations.Sum(3,a,b,c));

            Console.WriteLine($"{a} - {b} = " + MathOperations.Sub(a,b));

            Console.WriteLine($"{b} * {c} = " + MathOperations.Mult(b,c));

            Console.WriteLine($"{a} / {b} = " + MathOperations.Div(a,b));
        
        }
    }
}
