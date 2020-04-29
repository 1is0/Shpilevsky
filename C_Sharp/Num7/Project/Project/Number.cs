using System;

namespace Project
{
    class Number : IEquatable<Number>, IComparable
    {
        double value;

        public int Numerator
        {
            get;

            set;
        }

        public int Denominator
        {
            get;

            set;
        }

        public Number()
        {
            Numerator = 1;
            Denominator = 1;
        }

        public Number(int num, int den)
        {
            Numerator = num;
            Denominator = den;
            value = (double)num / den;
        }

        public Number(double x)
        {
            value = x;

            if(x%10 == 0)
            {
                Numerator = (int)x;
                Denominator = 1;
            }

            else
            {
                int i = 0;
                while(x%10!=0)
                {
                    x *= 10;
                    i++;
                }

                i--;
                x /= 10;

                Numerator = (int)x;
                Denominator = (int)Math.Pow(10, i);

                Reduce();
            }
        }

        public static Number operator +(Number n1, Number n2)
        {
            Number num = new Number();

            num.Numerator = n1.Numerator * n2.Denominator + n1.Denominator * n2.Numerator;
            num.Denominator = n1.Denominator * n2.Denominator;
            num.value = n1.value + n2.value;

            num.Reduce();

            return num;
        }

        public static Number operator -(Number n1, Number n2)
        {
            Number num = new Number();

            num.Numerator = n1.Numerator * n2.Denominator -  n1.Denominator * n2.Numerator;
            num.Denominator = n1.Denominator * n2.Denominator;
            num.value = n1.value - n2.value;

            num.Reduce();

            return num;
        }
        public static Number operator *(Number n1, Number n2)
        {
            Number num = new Number();

            num.Numerator = n1.Numerator * n2.Numerator;
            num.Denominator = n1.Denominator * n2.Denominator;
            num.value = n1.value * n2.value;

            num.Reduce();

            return num;
        }
        public static Number operator /(Number n1, Number n2)
        {
            Number num = new Number();

            num.Numerator = n1.Numerator * n2.Denominator;
            num.Denominator = n1.Denominator * n2.Numerator;
            num.value = n1.value / n2.value;
            if (n1 < 0 || n2 < 0)
            {
                num.Numerator = -num.Numerator;
                num.Denominator = Math.Abs(num.Denominator);
            }

            num.Reduce();

            return num;
        }

        public static bool operator <(Number n1, Number n2)
        {
            return n1.value < n2.value;
        }

        public static bool operator >(Number n1, Number n2)
        {
            return n1.value > n2.value;
        }

        public static implicit operator int(Number num)
        {
            return (int)num;
        }

        public static implicit operator double(Number num)
        {
            return num.value;
        }

        public static bool operator<=(Number n1, Number n2)
        {
            return n1.value <= n2.value;
        }

        public static bool operator >=(Number n1, Number n2)
        {
            return n1.value >= n2.value;
        }

        public static bool operator ==(Number n1, Number n2)
        {
            return n1.Equals(n2);
        }

        public static bool operator !=(Number n1, Number n2)
        {
            return !n1.Equals(n2);
        }

        public int CompareTo(object obj)
        {
            if (this.value > ((Number)obj).value)
            {
                return 1;
            }

            if (this.value < ((Number)obj).value)
            {
                return -1;
            }

            else
            {
                return 0;
            }
        }

        public bool Equals(Number other)
        {
            return value == other.value;
        }

        public override string ToString()
        {
            if ((value - (int)value) != 0)
            {
                return $"{Numerator}/{Denominator}";
            }
            else
            {
                return $"{value}";
            }
        }

        void Reduce()
        {
            int NOD(int a, int b)
            {
                a = Math.Abs(a);
                b = Math.Abs(b);
                while (a!=0 && b!=0)
                {
                    if (a >= b)
                        a %= b;

                    else
                        b %= a;
                }

                return a | b;
            }

            while (NOD(Numerator,Denominator)!=1)
            {
                int n = NOD(Numerator, Denominator);
                Numerator /= n;
                Denominator /= n;
            }
        }
    }
}
