using System;
using System.Collections.Generic;

namespace decimal_to_binary
{
    class Program
    {
        static void Main(string[] args)
        {
            int number = int.Parse(Console.ReadLine());
            Stack<int> deci = new Stack<int>();

            if (number == 0) Console.WriteLine("0");
            else while (number > 0)
            {
                deci.Push(number % 2);
                number /= 2;
            }
            while (deci.Count > 0)
            {
                Console.Write(deci.Pop());
            }

        }
    }
}
